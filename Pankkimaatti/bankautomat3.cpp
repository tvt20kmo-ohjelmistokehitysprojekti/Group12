#include "bankautomat.h"
#include "ui_bankautomat.h"


//Saldo
void BankAutomat::on_ActionBtnSaldo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->saldopage);





   ui->saldoLabelTilinsaldo->setText(Saldo());
}

QString BankAutomat::Saldo(){
    QJsonObject json;
       json.insert("idTili",getTiliID());



   QByteArray response = getNetworkreply(json,"Saldo");



   QJsonDocument json_doc = QJsonDocument::fromJson(response);
   QJsonObject jsobj = json_doc.object();

   QString resp;

   resp = jsobj["Saldo"].toString()+ " eur";


    return resp;

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

   QJsonDocument json_doc = QJsonDocument::fromJson(response);
           QJsonObject jsobj = json_doc.object();
           QJsonArray jsarr = json_doc.array();

           QString date, transact, sum;

          foreach (const QJsonValue &value, jsarr) {
                     QJsonObject jsob = value.toObject();

                     date+=jsob["Pvm"].toString()+"\n";
                     transact+=jsob["Selite"].toString()+"\n";
                     sum+=jsob["Summa"].toString()+"\n";


           }



           ui->transactionLabelDate->setText(date);
           ui->transactionLabelTransact->setText(transact);
           ui->transactionLabelSum->setText(sum);
           ui->TransactionLabelSaldo->setText(Saldo());

}



