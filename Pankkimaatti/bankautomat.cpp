#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>


BankAutomat::BankAutomat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankAutomat)
{
    ui->setupUi(this);

    connect(nam, &QNetworkAccessManager::authenticationRequired, this, &BankAutomat::authRequired);

    baseUrl.setUrl("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/Pankki");
    //testiä
    setTiliID("1");
    ui->stackedWidget->setCurrentWidget(ui->Actionpage);


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

    //Tehdään Qurl olio
    QUrl relative("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/Login");

       //Uusi request
    QNetworkRequest req(relative);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //Tehdään json tiedoista
    QJsonObject json;
        json.insert("KorttiID",KorttiID);
        json.insert("Tunnusluku",Tunnusluku);

    //lähetetään post metoditlla ja otetaan vastaus
    QNetworkReply *reply = nam->post(req, QJsonDocument(json).toJson());

    //Odotetaan vastausta
    while(!reply->isFinished()){
        qApp->processEvents();
    }


    //Otetaan vastuas talteen
    QByteArray response = reply->readAll();
    //Poistetaan reply
    reply->deleteLater();

    //Tarkistetaan vastauksen sisältö ja vertailaan
    /*if(response.compare("true")==0){
        relative.setUrl("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/Fetch_account");
        QNetworkRequest req(relative);

        QJsonObject json;



        ui->stackedWidget->setCurrentWidget(ui->DepitCreditPage);


        //kato onko credit ja sen mukaan sitte....
   // }


    else{
        ui->loginLabelInfo->setText("Kirjautumistiedot eivät kelpaa, yritä uudelleen");
    }


*/

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

    QUrl url("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/Fetch_account");

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json.insert("Tyyppi",Tyyppi);
    json.insert("KorttiID",KorttiID);

    QNetworkReply *reply = nam->post(req,QJsonDocument(json).toJson());


    while(!reply->isFinished()){
        qApp->processEvents();
    }


    //Otetaan vastuas talteen
    QByteArray response = reply->readAll();
    //Poistetaan reply
    reply->deleteLater();

    QString idtili = response;//korjailaan backend vähä...
    ui->label_4->setText(idtili);


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
