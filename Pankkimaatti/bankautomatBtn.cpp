#include "bankautomat.h"
#include "ui_bankautomat.h"
#include <QString>
#include <QDebug>



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

    //Tarkistetaan vastauksen sisältö ja vertaillaan
    if(response.contains("true")){

        //Asetetaan KorttiID
        setKorttiID(KorttiID);

        //Katsotaan onko käyttäjällä credit kortti, jos on mennään credit-debit valintaan muuten action valikkoon
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

//Buttonit debitille ja creditille
void BankAutomat::on_DebitCreditBtnCredit_clicked()
{
    this->CreditDebit("Credit");
    isCredit = true;
}

void BankAutomat::on_DebitCreditBtnDebit_clicked()
{
    this->CreditDebit("Debit");
}

//Toimintovalinta ikkuna
void BankAutomat::on_ActionBtnOtto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->withdrawpage); //siirrytään otto-sivulle
}

//Saldo
void BankAutomat::on_ActionBtnSaldo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->saldopage); //Siirrytään saldo-sivulle
    ui->saldoLabelTilinsaldo->setText(Saldo()); //Näytetään tilin saldo
    if (isCredit){//Jos credit tili näytetään nostettavissa oleva summa
        QJsonObject json;
           json.insert("idTili",getTiliID());
           QByteArray response = this->getNetworkreply(json,"Nostettavissa");

           QJsonDocument json_doc = QJsonDocument::fromJson(response);
           QJsonObject jsobj = json_doc.object();

           QString amount;

           amount ="Nostettavissa      "+ jsobj["Nostettavissa"].toString()+ " euroa";

           ui->saldoLabelNostettavissa->setText(amount);
    }
}

//Tapahtumat-buttonista päästään tarkastelemaan tilin tapahtumia
void BankAutomat::on_ActionBtnTapahtumat_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->Transactionpage);

    QJsonObject json;
       json.insert("idTili",getTiliID());

    QByteArray response = this->getNetworkreply(json,"Tapahtumat"); //Haetaan tapahtumat

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
     // Tulostetaan käyttöliittymään pvm, selite, summa ja saldo
     ui->transactionLabelDate->setText(date);
     ui->transactionLabelTransact->setText(transact);
     ui->transactionLabelSum->setText(sum);
     ui->TransactionLabelSaldo->setText(Saldo());

}

//Otto
void BankAutomat::on_withdrawBtnOther_clicked(bool checked)
{
    if(checked){                //Näytetään muu summa valinta jos buttonia klikataan, muuten piilotetaan valinta
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
{   gotologin();
}
void BankAutomat::on_saldoBtnPalaa_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
}
void BankAutomat::on_withdrawBtnPaluu_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
    ui->withdrawBtnOther->click();
    ui->withdrawLabelInfo->clear();
}
void BankAutomat::on_TransactionBtnPalaa_clicked()
{   ui->stackedWidget->setCurrentWidget(ui->Actionpage);
}

