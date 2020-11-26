#include "bankautomat.h"
#include "ui_bankautomat.h"

BankAutomat::BankAutomat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankAutomat)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->withdrawpage);
}

BankAutomat::~BankAutomat()
{
    delete ui;
}


void BankAutomat::on_loginBtnKirjaudu_clicked()
{

}



void BankAutomat::on_DebitCreditBtnCredit_clicked()
{

}

void BankAutomat::on_DebitCreditBtnDebit_clicked()
{

}

void BankAutomat::on_ActionBtnOtto_clicked()
{

}

void BankAutomat::on_ActionBtnSaldo_clicked()
{

}

void BankAutomat::on_ActionBtnTapahtumat_clicked()
{

}

void BankAutomat::on_intakeinfoBtnEi_clicked()
{

}

void BankAutomat::on_intakeinfoBtnKuitille_clicked()
{

}

void BankAutomat::on_intakeinfoBtnNaytto_clicked()
{

}

void BankAutomat::on_saldoBtnLopeta_clicked()
{

}

void BankAutomat::on_saldoBtnPalaa_clicked()
{

}

void BankAutomat::on_withdrawBtn100_clicked()
{

}

void BankAutomat::on_withdrawBtn20_clicked()
{

}

void BankAutomat::on_withdrawBtn40_clicked()
{

}

void BankAutomat::on_withdrawBtn50_clicked()
{

}

void BankAutomat::on_withdrawBtnOk_clicked()
{

}

void BankAutomat::on_withdrawBtnPaluu_clicked()
{

}

void BankAutomat::on_TransactionBtnLopeta_clicked()
{

}

void BankAutomat::on_TransactionBtnPalaa_clicked()
{

}
