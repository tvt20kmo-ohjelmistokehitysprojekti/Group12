#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>
#include <QDebug>
#include <QIntValidator>


BankAutomat::BankAutomat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankAutomat)
{
    ui->setupUi(this);

    connect(nam, &QNetworkAccessManager::authenticationRequired, this, &BankAutomat::authRequired);

    baseUrl.setUrl("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/");
    this->setLineEditValidation();


}

BankAutomat::~BankAutomat()
{
    delete nam;
    delete ui;
}

// Login
void BankAutomat::on_loginBtnKirjaudu_clicked()
{
    ui->loginLabelInfo->setText("Kirjaudutaan..."); //Odotus viesti
    //Haetaan KorttiID, Tunnusluku käyttöliittymästä
    QString KorttiID, Tunnusluku;

    KorttiID = ui->loginlineEditKorttiID->text();
    Tunnusluku = ui->loginlineEditTunnusluku->text();

    //Tehdään json tiedoista
    QJsonObject json;
        json.insert("KorttiID",KorttiID);
        json.insert("Tunnusluku",Tunnusluku);

    QByteArray response = this->getNetworkreply(json,"Login");

    //Tarkistetaan vastauksen sisältö ja vertailaan
    if(response.compare("true")==0){

        //Asetetaan KorttiID
        setKorttiID(KorttiID);

        //Katsotaan onko käyttäjällä credit kortti jos on mennään credit debit valintaan muuten action valikkoon
        json.insert("Tyyppi","Credit");

        response = this->getNetworkreply(json,"Fetch_account");

        if (response.contains("false")){

            json.insert("Tyyppi","Debit");
            response = this->getNetworkreply(json,"Fetch_account");

            if (response.contains("false")){
                qDebug("Jotain meni väärin");
            }
            else{
                QJsonDocument json_doc = QJsonDocument::fromJson(response);
                QJsonObject jsobj = json_doc.object();

                this->setTiliID(jsobj["idTili"].toString());

                ui->stackedWidget->setCurrentWidget(ui->Actionpage);
            }
        }
        else{
            ui->stackedWidget->setCurrentWidget(ui->DepitCreditPage);
        }

    }//endif
    else{
        ui->loginLabelInfo->setText("Kirjautumistiedot eivät kelpaa, yritä uudelleen");
    }
}

//Credit / Debit
void BankAutomat::on_DebitCreditBtnCredit_clicked()
{
    this->CreditDebit("Credit");
}

void BankAutomat::on_DebitCreditBtnDebit_clicked()
{
    this->CreditDebit("Debit");
}

void BankAutomat::CreditDebit(QString Tyyppi)
{
    QString KorttiID = this->getKorttiID();

    QJsonObject json;
    json.insert("Tyyppi",Tyyppi);
    json.insert("KorttiID",KorttiID);

    QByteArray response = this->getNetworkreply(json,"Fetch_account");

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


//Valinta ikkuna
void BankAutomat::on_ActionBtnOtto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->withdrawpage);
}

//Paluut ja lopetat
void BankAutomat::on_TransactionBtnLopeta_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->loginPage);
    clearInfo();
}
void BankAutomat::on_saldoBtnLopeta_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->loginPage);
    clearInfo();
}
void BankAutomat::on_saldoBtnPalaa_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
}
void BankAutomat::on_withdrawBtnPaluu_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
}
void BankAutomat::on_TransactionBtnPalaa_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
}

//Muut
QString BankAutomat::getTiliID() const
{
    return TiliID;
}

void BankAutomat::setTiliID(const QString &value)
{
    TiliID = value;
}

void BankAutomat::authRequired(QNetworkReply *Reply, QAuthenticator *Authenticator)
{
    qDebug() << Reply->readAll();
   Authenticator->setUser("Group");
   Authenticator->setPassword("1212");
}

QString BankAutomat::getKorttiID() const
{
    return KorttiID;
}

void BankAutomat::setKorttiID(const QString &value)
{
    KorttiID = value;
}
QByteArray BankAutomat::getNetworkreply(QJsonObject json, QString url)
{
    //Funktio auttamaan networkrequestin ja vastauksen hakua. Ottaa vastaan lähetettävän jsonobjectin
    //ja Url polun joka yhdistetään baseurl. Eli esmim "Otto"
    //Tehdään Qurl olio
    QUrl relative = url;
    //Yhdistetään polku base urliin
    QUrl urli = this->baseUrl.resolved(relative);

    //Uusi request
    QNetworkRequest request(baseUrl.resolved(relative));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //lähetetään post metoditlla ja otetaan vastaus
    QNetworkReply *reply = nam->post(request,QJsonDocument(json).toJson());

    //Odotetaan vastausta
    while(!reply->isFinished()){
        qApp->processEvents();
    }
    //Otetaan vastuas talteen
    QByteArray result = reply->readAll();

    //Poistetaan reply
    reply->deleteLater();

    //Palautetaan result

    return result;
}

void BankAutomat::clearInfo()
{
    this->setKorttiID("0");
    this->setTiliID("0");
    ui->loginlineEditKorttiID->clear();
    ui->loginlineEditTunnusluku->clear();
    ui->loginLabelInfo->clear();
}

void BankAutomat::setLineEditValidation(){
    QIntValidator* validator = new QIntValidator(0,9999,this);
    ui->loginlineEditKorttiID->setValidator(validator);
    ui->loginlineEditTunnusluku->setValidator(validator);
    ui->withdrawlineEditAmount->setValidator(validator);
}
