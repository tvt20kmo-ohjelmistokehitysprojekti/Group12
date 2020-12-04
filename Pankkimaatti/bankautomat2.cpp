#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>
#include "moneywndow.h"



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
    if(!(amount.toInt()%20) || !((amount.toInt()%50)%20)){
        withdraw(amount);
    }
    else{
            ui->withdrawLabelInfo->setText("Summa ei kelvollinen\nAutomaatista nostettavissa\n 100,50,20 euron setelit");
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

        if (response.contains("1")){//Tässä otto menee läpi
                ui->stackedWidget->setCurrentWidget(ui->Endingpage);
                MoneyWndow* Money = new MoneyWndow(this);
                Money->setGeometry((this->x()+500),(this->y()+500),530,280); //laitetaan raha ikkuna suhteessa bankautomat ikkunaan
                connect(Money, &MoneyWndow::destroyed, this, &BankAutomat::gotologin);
                Money->show();
                Money->setNotes(amount);

        }

        else { ui->withdrawLabelInfo->setText("Tilillä ei katetta");}
}



void BankAutomat::gotologin(){
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    clearInfo();
}

