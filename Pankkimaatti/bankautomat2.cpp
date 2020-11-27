#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>


//Otto
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
    withdraw(amount);

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


}




void BankAutomat::on_withdrawBtnPaluu_clicked()

{

}
//Kuitti ei kiitos ikkuna
void BankAutomat::on_intakeinfoBtnEi_clicked()
{

}

void BankAutomat::on_intakeinfoBtnKuitille_clicked()
{

}

void BankAutomat::on_intakeinfoBtnNaytto_clicked()
{

}
