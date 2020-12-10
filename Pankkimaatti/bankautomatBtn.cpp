#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QtNetwork>
#include <QDebug>
#include <QIntValidator>


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
    if(response.contains("true")){

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

//Valinta ikkuna
void BankAutomat::on_ActionBtnOtto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->withdrawpage);
}

//Saldo
void BankAutomat::on_ActionBtnSaldo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->saldopage);
    ui->saldoLabelTilinsaldo->setText(Saldo());
}

//Tapahtumat
void BankAutomat::on_ActionBtnTapahtumat_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->Transactionpage);

    QJsonObject json;
       json.insert("idTili",getTiliID());

    QByteArray response = this->getNetworkreply(json,"Tapahtumat");

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
//Paluut ja lopetat
void BankAutomat::on_TransactionBtnLopeta_clicked()
{   gotologin();
}
void BankAutomat::on_saldoBtnLopeta_clicked()
{   gotologin();
}
void BankAutomat::on_saldoBtnLopeta_3_clicked()
{   gotologin();
}
void BankAutomat::on_saldoBtnLopeta_2_clicked()
{ gotologin();
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

