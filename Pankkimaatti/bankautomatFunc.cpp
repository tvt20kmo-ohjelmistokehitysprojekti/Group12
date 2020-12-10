#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>
#include "Money.h"
#include <QDebug>
#include <QIntValidator>

BankAutomat::BankAutomat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankAutomat)
{
    ui->setupUi(this);

    connect(nam, &QNetworkAccessManager::authenticationRequired, this, &BankAutomat::authRequired); //yhdistetään authentication

    baseUrl.setUrl("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/");
    this->setLineEditValidation();
    ui->frame->hide();
    ui->withdrawBtnOther->setCheckable("True");
}

BankAutomat::~BankAutomat()
{
    delete nam;
    delete ui;
}

QByteArray BankAutomat::getNetworkreply(QJsonObject json, QString url)
{
    //Funktio auttamaan networkrequestin ja vastauksen hakua. Ottaa vastaan lähetettävän jsonobjectin
    //ja Url polun joka yhdistetään baseurl. Eli esim "Otto"
    //Tehdään Qurl olio
    QUrl relative = url;
    //Yhdistetään polku base urliin
    QUrl urli = this->baseUrl.resolved(relative);

    //Uusi request
    QNetworkRequest request(baseUrl.resolved(relative));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //lähetetään post metodilla ja otetaan vastaus
    QNetworkReply *reply = nam->post(request,QJsonDocument(json).toJson());

    //Odotetaan vastausta
    while(!reply->isFinished()){
        qApp->processEvents();
    }
    //Otetaan vastaus talteen
    QByteArray result = reply->readAll();

    //Poistetaan reply
    reply->deleteLater();

    //Palautetaan result

    return result;
}

//Ottofunktio hakee rahat tililtä
void BankAutomat::withdraw(QString amount)
{
    QString idTili = getTiliID();

    QJsonObject json;
        json.insert("idTili", idTili);
        json.insert("Summa", amount);   //Lähetetään summa ja tili miltä nostetaan

        //Otetaan vastaus talteen
        QByteArray response = this->getNetworkreply(json,"Otto");

        if (response.contains("viesti") && response.contains("1")){ //Otto menee läpi
                ui->stackedWidget->setCurrentWidget(ui->Endingpage);
                Money* Notes = new Money(this);
                Notes->setGeometry((this->x()+500),(this->y()+500),530,280); //laitetaan raha ikkuna suhteessa bankautomat ikkunaan
                connect(Notes, &Money::destroyed, this, &BankAutomat::gotologin);//yhdistetään setelien sulkeminen gotologiniin
                Notes->show();
                Notes->setSubset(amount.toInt());
                Notes->openNotes();
        }
        else { ui->withdrawLabelInfo->setText("Tilillä ei katetta");
        }
}

//Saldofunktio hakee saldotiedot
QString BankAutomat::Saldo()
{
    QJsonObject json;
       json.insert("idTili",getTiliID()); //Lähetetään idtili

   QByteArray response = getNetworkreply(json,"Saldo"); //Haetaan ja otetaan vastaus talteen

   QJsonDocument json_doc = QJsonDocument::fromJson(response);
   QJsonObject jsobj = json_doc.object();

   QString resp;

   resp = jsobj["Saldo"].toString()+ " euroa";    //Tulostetaan vastaus

    return resp;
}


//Funktio kortin tyypin valintaan
void BankAutomat::CreditDebit(QString Tyyppi)
{
    QString KorttiID = this->getKorttiID();

    //Tehdään json tiedoista
    QJsonObject json;
    json.insert("Tyyppi",Tyyppi);
    json.insert("KorttiID",KorttiID);

    QByteArray response = this->getNetworkreply(json,"Fetch_account");

    //Tarkistetaan vastauksen sisältö ja tehdään vertailua
    if (response.contains("false")){
        qDebug() <<"Jotain meni väärin";
    }
    else{
        QJsonDocument json_doc = QJsonDocument::fromJson(response);
        QJsonObject jsobj = json_doc.object();

        this->setTiliID(jsobj["idTili"].toString());

        ui->stackedWidget->setCurrentWidget(ui->Actionpage);
    }
}

//Authentikaatio
void BankAutomat::authRequired(QNetworkReply *Reply, QAuthenticator *Authenticator)
{
    qDebug() << Reply->readAll();
   Authenticator->setUser("Group");
   Authenticator->setPassword("1212");
}

void BankAutomat::gotologin(){
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    clearInfo();
}

//Poistetaan tiedot ettei ne näy seuraavalle käyttäjälle
void BankAutomat::clearInfo()
{
    this->setKorttiID("0");
    this->setTiliID("0");
    ui->loginlineEditKorttiID->clear();
    ui->loginlineEditTunnusluku->clear();
    ui->loginLabelInfo->clear();
    ui->withdrawlineEditAmount->clear();
    ui->frame->hide();
}
//LineEditValidation
void BankAutomat::setLineEditValidation(){
    QIntValidator* validator = new QIntValidator(0,9999,this);
    ui->loginlineEditKorttiID->setValidator(validator);
    ui->loginlineEditTunnusluku->setValidator(validator);
    ui->withdrawlineEditAmount->setValidator(validator);
}
//Set & get
QString BankAutomat::getTiliID() const
{
    return TiliID;
}

void BankAutomat::setTiliID(const QString &value)
{
    TiliID = value;
}
QString BankAutomat::getKorttiID() const
{
    return KorttiID;
}

void BankAutomat::setKorttiID(const QString &value)
{
    KorttiID = value;
}
