#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>


//Otto
void BankAutomat::on_withdrawBtnOther_clicked(bool checked)
{
    if(checked){
        ui->frame->show();
    }
    else
        ui->frame->hide();
}

void BankAutomat::on_withdrawBtn100_clicked()
{
    withdraw("100");
}

void BankAutomat::on_withdrawBtn20_clicked()
{
    withdraw("20");
}

void BankAutomat::on_withdrawBtn40_clicked()
{
    withdraw("40");
}

void BankAutomat::on_withdrawBtn50_clicked()
{
    withdraw("50");
}

void BankAutomat::on_withdrawBtnOk_clicked()
{
    QString amount = ui->withdrawlineEditAmount->text();
    if(checkSum(amount)){
        withdraw(amount);
    }
    else{
            ui->withdrawLabelInfo->setText("Summa ei kelvollinen\nNostettavan summan pitää\n olla jaollinen 20 eurolla");
        }

}

void BankAutomat::withdraw(QString amount)
{
    QString idTili = getTiliID();

    QUrl url("http://www.students.oamk.fi/~t9alma00/Group12/RestApi/index.php/Pankki/Otto");

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
        json.insert("idTili", idTili);
        json.insert("Summa", amount);

    QNetworkReply *reply = nam->post(req, QJsonDocument(json).toJson());

        //Odotetaan vastausta
        while(!reply->isFinished())
          {
            qApp->processEvents();
          }


        //Otetaan vastuas talteen
        QByteArray response = reply->readAll();
        //Poistetaan reply
        reply->deleteLater();

        //myöhemmin tehdään vastauksen käsittely

        if (response.contains("1")){
                ui->stackedWidget->setCurrentWidget(ui->Endingpage);    }//Tässä otto menee läpi//



                else {
                ui->withdrawLabelInfo->setText("Tilillä ei katetta");
}



}

bool BankAutomat::checkSum(QString sum){
        return !(sum.toInt()%20); //true jos summa jaollinen 20
}

void BankAutomat::printMoney(QString sum)
{
//to-do
}


