/********************************************************************************
** Form generated from reading UI file 'bankautomat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKAUTOMAT_H
#define UI_BANKAUTOMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BankAutomat
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QLineEdit *loginlineEditKorttiID;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginBtnKirjaudu;
    QLineEdit *loginlineEditTunnusluku;
    QLabel *label_3;
    QLabel *loginLabelInfo;
    QWidget *DepitCreditPage;
    QLabel *label_4;
    QPushButton *DebitCreditBtnDebit;
    QPushButton *DebitCreditBtnCredit;
    QWidget *Actionpage;
    QPushButton *ActionBtnOtto;
    QPushButton *ActionBtnSaldo;
    QPushButton *ActionBtnTapahtumat;
    QLabel *label_5;
    QWidget *intakeInfopage;
    QPushButton *intakeinfoBtnKuitille;
    QPushButton *intakeinfoBtnNaytto;
    QPushButton *intakeinfoBtnEi;
    QLabel *label_6;
    QWidget *saldopage;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *saldoBtnLopeta;
    QLabel *saldoLabelTilinsaldo;
    QPushButton *saldoBtnPalaa;
    QWidget *withdrawpage;
    QPushButton *withdrawBtn20;
    QPushButton *withdrawBtn40;
    QPushButton *withdrawBtn50;
    QPushButton *withdrawBtn100;
    QLineEdit *withdrawlineEditAmount;
    QLabel *label_10;
    QPushButton *withdrawBtnOk;
    QPushButton *withdrawBtnPaluu;
    QLabel *label_11;
    QWidget *Transactionpage;
    QLabel *label_9;
    QLabel *transactionLabelTransaction;
    QPushButton *TransactionBtnLopeta;
    QPushButton *TransactionBtnPalaa;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BankAutomat)
    {
        if (BankAutomat->objectName().isEmpty())
            BankAutomat->setObjectName(QString::fromUtf8("BankAutomat"));
        BankAutomat->resize(800, 600);
        centralwidget = new QWidget(BankAutomat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, -20, 811, 611));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        loginlineEditKorttiID = new QLineEdit(loginPage);
        loginlineEditKorttiID->setObjectName(QString::fromUtf8("loginlineEditKorttiID"));
        loginlineEditKorttiID->setGeometry(QRect(310, 160, 231, 31));
        label = new QLabel(loginPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 160, 71, 21));
        label_2 = new QLabel(loginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 50, 121, 21));
        loginBtnKirjaudu = new QPushButton(loginPage);
        loginBtnKirjaudu->setObjectName(QString::fromUtf8("loginBtnKirjaudu"));
        loginBtnKirjaudu->setGeometry(QRect(280, 380, 191, 51));
        loginlineEditTunnusluku = new QLineEdit(loginPage);
        loginlineEditTunnusluku->setObjectName(QString::fromUtf8("loginlineEditTunnusluku"));
        loginlineEditTunnusluku->setGeometry(QRect(310, 210, 231, 31));
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 210, 71, 21));
        loginLabelInfo = new QLabel(loginPage);
        loginLabelInfo->setObjectName(QString::fromUtf8("loginLabelInfo"));
        loginLabelInfo->setGeometry(QRect(220, 270, 301, 71));
        stackedWidget->addWidget(loginPage);
        DepitCreditPage = new QWidget();
        DepitCreditPage->setObjectName(QString::fromUtf8("DepitCreditPage"));
        label_4 = new QLabel(DepitCreditPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 90, 111, 31));
        DebitCreditBtnDebit = new QPushButton(DepitCreditPage);
        DebitCreditBtnDebit->setObjectName(QString::fromUtf8("DebitCreditBtnDebit"));
        DebitCreditBtnDebit->setGeometry(QRect(110, 220, 113, 32));
        DebitCreditBtnCredit = new QPushButton(DepitCreditPage);
        DebitCreditBtnCredit->setObjectName(QString::fromUtf8("DebitCreditBtnCredit"));
        DebitCreditBtnCredit->setGeometry(QRect(520, 220, 113, 32));
        stackedWidget->addWidget(DepitCreditPage);
        Actionpage = new QWidget();
        Actionpage->setObjectName(QString::fromUtf8("Actionpage"));
        ActionBtnOtto = new QPushButton(Actionpage);
        ActionBtnOtto->setObjectName(QString::fromUtf8("ActionBtnOtto"));
        ActionBtnOtto->setGeometry(QRect(110, 180, 113, 32));
        ActionBtnSaldo = new QPushButton(Actionpage);
        ActionBtnSaldo->setObjectName(QString::fromUtf8("ActionBtnSaldo"));
        ActionBtnSaldo->setGeometry(QRect(110, 250, 113, 32));
        ActionBtnTapahtumat = new QPushButton(Actionpage);
        ActionBtnTapahtumat->setObjectName(QString::fromUtf8("ActionBtnTapahtumat"));
        ActionBtnTapahtumat->setGeometry(QRect(480, 250, 113, 32));
        label_5 = new QLabel(Actionpage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 50, 131, 31));
        stackedWidget->addWidget(Actionpage);
        intakeInfopage = new QWidget();
        intakeInfopage->setObjectName(QString::fromUtf8("intakeInfopage"));
        intakeinfoBtnKuitille = new QPushButton(intakeInfopage);
        intakeinfoBtnKuitille->setObjectName(QString::fromUtf8("intakeinfoBtnKuitille"));
        intakeinfoBtnKuitille->setGeometry(QRect(80, 270, 113, 32));
        intakeinfoBtnNaytto = new QPushButton(intakeInfopage);
        intakeinfoBtnNaytto->setObjectName(QString::fromUtf8("intakeinfoBtnNaytto"));
        intakeinfoBtnNaytto->setGeometry(QRect(490, 270, 113, 32));
        intakeinfoBtnEi = new QPushButton(intakeInfopage);
        intakeinfoBtnEi->setObjectName(QString::fromUtf8("intakeinfoBtnEi"));
        intakeinfoBtnEi->setGeometry(QRect(80, 340, 113, 32));
        label_6 = new QLabel(intakeInfopage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 80, 171, 16));
        stackedWidget->addWidget(intakeInfopage);
        saldopage = new QWidget();
        saldopage->setObjectName(QString::fromUtf8("saldopage"));
        label_7 = new QLabel(saldopage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 65, 151, 31));
        label_8 = new QLabel(saldopage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(58, 160, 131, 21));
        saldoBtnLopeta = new QPushButton(saldopage);
        saldoBtnLopeta->setObjectName(QString::fromUtf8("saldoBtnLopeta"));
        saldoBtnLopeta->setGeometry(QRect(600, 390, 113, 32));
        saldoLabelTilinsaldo = new QLabel(saldopage);
        saldoLabelTilinsaldo->setObjectName(QString::fromUtf8("saldoLabelTilinsaldo"));
        saldoLabelTilinsaldo->setGeometry(QRect(570, 150, 131, 41));
        saldoBtnPalaa = new QPushButton(saldopage);
        saldoBtnPalaa->setObjectName(QString::fromUtf8("saldoBtnPalaa"));
        saldoBtnPalaa->setGeometry(QRect(460, 390, 113, 32));
        stackedWidget->addWidget(saldopage);
        withdrawpage = new QWidget();
        withdrawpage->setObjectName(QString::fromUtf8("withdrawpage"));
        withdrawBtn20 = new QPushButton(withdrawpage);
        withdrawBtn20->setObjectName(QString::fromUtf8("withdrawBtn20"));
        withdrawBtn20->setGeometry(QRect(60, 210, 113, 32));
        withdrawBtn40 = new QPushButton(withdrawpage);
        withdrawBtn40->setObjectName(QString::fromUtf8("withdrawBtn40"));
        withdrawBtn40->setGeometry(QRect(60, 270, 113, 32));
        withdrawBtn50 = new QPushButton(withdrawpage);
        withdrawBtn50->setObjectName(QString::fromUtf8("withdrawBtn50"));
        withdrawBtn50->setGeometry(QRect(480, 210, 113, 32));
        withdrawBtn100 = new QPushButton(withdrawpage);
        withdrawBtn100->setObjectName(QString::fromUtf8("withdrawBtn100"));
        withdrawBtn100->setGeometry(QRect(480, 270, 113, 32));
        withdrawlineEditAmount = new QLineEdit(withdrawpage);
        withdrawlineEditAmount->setObjectName(QString::fromUtf8("withdrawlineEditAmount"));
        withdrawlineEditAmount->setGeometry(QRect(490, 350, 113, 31));
        label_10 = new QLabel(withdrawpage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(500, 320, 91, 16));
        withdrawBtnOk = new QPushButton(withdrawpage);
        withdrawBtnOk->setObjectName(QString::fromUtf8("withdrawBtnOk"));
        withdrawBtnOk->setGeometry(QRect(480, 390, 113, 32));
        withdrawBtnPaluu = new QPushButton(withdrawpage);
        withdrawBtnPaluu->setObjectName(QString::fromUtf8("withdrawBtnPaluu"));
        withdrawBtnPaluu->setGeometry(QRect(70, 410, 113, 32));
        label_11 = new QLabel(withdrawpage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(340, 120, 59, 16));
        stackedWidget->addWidget(withdrawpage);
        Transactionpage = new QWidget();
        Transactionpage->setObjectName(QString::fromUtf8("Transactionpage"));
        label_9 = new QLabel(Transactionpage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 40, 171, 31));
        transactionLabelTransaction = new QLabel(Transactionpage);
        transactionLabelTransaction->setObjectName(QString::fromUtf8("transactionLabelTransaction"));
        transactionLabelTransaction->setGeometry(QRect(68, 140, 591, 151));
        TransactionBtnLopeta = new QPushButton(Transactionpage);
        TransactionBtnLopeta->setObjectName(QString::fromUtf8("TransactionBtnLopeta"));
        TransactionBtnLopeta->setGeometry(QRect(570, 340, 113, 32));
        TransactionBtnPalaa = new QPushButton(Transactionpage);
        TransactionBtnPalaa->setObjectName(QString::fromUtf8("TransactionBtnPalaa"));
        TransactionBtnPalaa->setGeometry(QRect(430, 340, 113, 32));
        stackedWidget->addWidget(Transactionpage);
        BankAutomat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BankAutomat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        BankAutomat->setMenuBar(menubar);
        statusbar = new QStatusBar(BankAutomat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BankAutomat->setStatusBar(statusbar);

        retranslateUi(BankAutomat);

        QMetaObject::connectSlotsByName(BankAutomat);
    } // setupUi

    void retranslateUi(QMainWindow *BankAutomat)
    {
        BankAutomat->setWindowTitle(QApplication::translate("BankAutomat", "BankAutomat", nullptr));
        label->setText(QApplication::translate("BankAutomat", "KorttiID", nullptr));
        label_2->setText(QApplication::translate("BankAutomat", "Kirjaudu sis\303\244\303\244n", nullptr));
        loginBtnKirjaudu->setText(QApplication::translate("BankAutomat", "Kirjaudu", nullptr));
        label_3->setText(QApplication::translate("BankAutomat", "Tunnusluku", nullptr));
        loginLabelInfo->setText(QString());
        label_4->setText(QApplication::translate("BankAutomat", "Valitse", nullptr));
        DebitCreditBtnDebit->setText(QApplication::translate("BankAutomat", "Debit", nullptr));
        DebitCreditBtnCredit->setText(QApplication::translate("BankAutomat", "Credit", nullptr));
        ActionBtnOtto->setText(QApplication::translate("BankAutomat", "Otto", nullptr));
        ActionBtnSaldo->setText(QApplication::translate("BankAutomat", "Saldo", nullptr));
        ActionBtnTapahtumat->setText(QApplication::translate("BankAutomat", "Tapahtumat", nullptr));
        label_5->setText(QApplication::translate("BankAutomat", "Valitse", nullptr));
        intakeinfoBtnKuitille->setText(QApplication::translate("BankAutomat", "Kuitille", nullptr));
        intakeinfoBtnNaytto->setText(QApplication::translate("BankAutomat", "N\303\244yt\303\266lle", nullptr));
        intakeinfoBtnEi->setText(QApplication::translate("BankAutomat", "Ei kiitos", nullptr));
        label_6->setText(QApplication::translate("BankAutomat", "Haluatko tiedot", nullptr));
        label_7->setText(QApplication::translate("BankAutomat", "Tilin tilanne", nullptr));
        label_8->setText(QApplication::translate("BankAutomat", "Tilin saldo", nullptr));
        saldoBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", nullptr));
        saldoLabelTilinsaldo->setText(QApplication::translate("BankAutomat", "60 euroa", nullptr));
        saldoBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", nullptr));
        withdrawBtn20->setText(QApplication::translate("BankAutomat", "20", nullptr));
        withdrawBtn40->setText(QApplication::translate("BankAutomat", "40", nullptr));
        withdrawBtn50->setText(QApplication::translate("BankAutomat", "50", nullptr));
        withdrawBtn100->setText(QApplication::translate("BankAutomat", "100", nullptr));
        label_10->setText(QApplication::translate("BankAutomat", "Muu summa", nullptr));
        withdrawBtnOk->setText(QApplication::translate("BankAutomat", "Ok", nullptr));
        withdrawBtnPaluu->setText(QApplication::translate("BankAutomat", "Paluu", nullptr));
        label_11->setText(QApplication::translate("BankAutomat", "Otto", nullptr));
        label_9->setText(QApplication::translate("BankAutomat", "Tilin tapahtumat", nullptr));
        transactionLabelTransaction->setText(QString());
        TransactionBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", nullptr));
        TransactionBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BankAutomat: public Ui_BankAutomat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKAUTOMAT_H
