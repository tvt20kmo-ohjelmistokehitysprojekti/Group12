#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>
#include <QDebug>


BankAutomat::BankAutomat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankAutomat)
{
    ui->setupUi(this);

    connect(nam, &QNetworkAccessManager::authenticationRequired, this, &BankAutomat::authRequired);

    baseUrl.setUrl("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/");
}

BankAutomat::~BankAutomat()
{
    delete ui;

}


// Login
void BankAutomat::on_loginBtnKirjaudu_clicked()
{

    //Haetaan KorttiID, Tunnusluku käyttöliittymästä
    QString KorttiID, Tunnusluku;

    KorttiID = ui->loginlineEditKorttiID->text();
    Tunnusluku = ui->loginlineEditTunnusluku->text();

    //Asetetaan KorttiID
    setKorttiID(KorttiID);

    //Tehdään json tiedoista
    QJsonObject json;
        json.insert("KorttiID",KorttiID);
        json.insert("Tunnusluku",Tunnusluku);

    QByteArray response = getNetworkreply(json,"Login");

    ui->loginLabelInfo->setText(response);

    //Tarkistetaan vastauksen sisältö ja vertailaan
    if(response.compare("true")==0){

        //Katsotaan onko käyttäjällä credit kortti jos ei mennään credit debit valintaan
        json.insert("Tyyppi","Credit");

        response = getNetworkreply(json,"Fetch_account");


        if (response.contains("false")){

            json.insert("Tyyppi","Debit");
            response = getNetworkreply(json,"Fetch_account");

            if (response.contains("false")){
                //QDebug<<"Jotain meni väärin";
            }
            else{
            QJsonDocument json_doc = QJsonDocument::fromJson(response);
            QJsonObject jsobj = json_doc.object();

            QString idTili;

            idTili = jsobj["idTili"].toString();
            setTiliID(idTili);

            ui->stackedWidget->setCurrentWidget(ui->Actionpage);
            }
        }
        else{
        ui->stackedWidget->setCurrentWidget(ui->DepitCreditPage);
        }

    }//endif
    else{
        ui->loginLabelInfo->setText("Kirjautumistiedot eivät kelpaa, yritä uudeleen");
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
    QString KorttiID = getKorttiID();

    QJsonObject json;
    json.insert("Tyyppi",Tyyppi);
    json.insert("KorttiID",KorttiID);


    QByteArray response = getNetworkreply(json,"Fetch_account");

    if (response.contains("false")){
        //QDebug<<"Jotain meni väärin";
    }
    else{

    QJsonDocument json_doc = QJsonDocument::fromJson(response);
    QJsonObject jsobj = json_doc.object();

    QString idTili;

    idTili = jsobj["idTili"].toString();
    setTiliID(idTili);

    ui->stackedWidget->setCurrentWidget(ui->Actionpage);
    }

}


//Valinta ikkuna
void BankAutomat::on_ActionBtnOtto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->withdrawpage);
}



//Saldo
void BankAutomat::on_saldoBtnLopeta_clicked()
{

}

void BankAutomat::on_saldoBtnPalaa_clicked()
{

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

void BankAutomat::authRequired(QNetworkReply *aReply, QAuthenticator *aAuthenticator)
{

   aAuthenticator->setUser("Group");
   aAuthenticator->setPassword("1212");
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
    QUrl urli = baseUrl.resolved(relative);

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
