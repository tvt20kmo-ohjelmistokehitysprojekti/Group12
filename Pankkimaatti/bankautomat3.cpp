#include "bankautomat.h"
#include "ui_bankautomat.h"


//Saldo
void BankAutomat::on_ActionBtnSaldo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->saldopage);
    QUrl url("http://localhost/Pankkiautomaatti/Group12/RestApi/index.php/Pankki/Saldo");

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
       json.insert("idTili",getTiliID());


   QNetworkReply *reply = nam->post(req, QJsonDocument(json).toJson());

   while(!reply->isFinished()){
       qApp->processEvents();
   }

   QByteArray response = reply->readAll();

   reply->deleteLater();

   QJsonDocument json_doc = QJsonDocument::fromJson(response);
   QJsonObject jsobj = json_doc.object();

   QString resp;

   resp = jsobj["Saldo"].toString()+ "  euroa";

   ui->saldoLabelTilinsaldo->setText(resp);





   //tulos vielä käsitellä
}

//Tapahtumat
void BankAutomat::on_ActionBtnTapahtumat_clicked()
{

    QUrl url("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/Tapahtumat");


    ui->stackedWidget->setCurrentWidget(ui->Transactionpage);

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
       json.insert("idTili",getTiliID());


   QNetworkReply *reply = nam->post(req, QJsonDocument(json).toJson());

   while(!reply->isFinished()){
       qApp->processEvents();
   }

   QByteArray response = reply->readAll();

   reply->deleteLater();

   ui->transactionLabelTransaction->setText(response);

}

void BankAutomat::on_TransactionBtnLopeta_clicked()
{

}

void BankAutomat::on_TransactionBtnPalaa_clicked()
{

}
