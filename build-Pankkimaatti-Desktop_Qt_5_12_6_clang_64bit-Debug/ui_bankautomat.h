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
    QLabel *label_12;
    QWidget *DepitCreditPage;
    QLabel *label_4;
    QPushButton *DebitCreditBtnDebit;
    QPushButton *DebitCreditBtnCredit;
    QLabel *label_13;
    QWidget *Actionpage;
    QPushButton *ActionBtnOtto;
    QPushButton *ActionBtnSaldo;
    QPushButton *ActionBtnTapahtumat;
    QLabel *label_5;
    QLabel *label_14;
    QWidget *intakeInfopage;
    QPushButton *intakeinfoBtnKuitille;
    QPushButton *intakeinfoBtnNaytto;
    QPushButton *intakeinfoBtnEi;
    QLabel *label_6;
    QLabel *label_15;
    QWidget *saldopage;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *saldoBtnLopeta;
    QLabel *saldoLabelTilinsaldo;
    QPushButton *saldoBtnPalaa;
    QLabel *label_16;
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
    QLabel *label_17;
    QWidget *Transactionpage;
    QLabel *label_9;
    QLabel *transactionLabelTransaction;
    QPushButton *TransactionBtnLopeta;
    QPushButton *TransactionBtnPalaa;
    QLabel *label_18;
    QLabel *transactionLabelTransaction_2;
    QLabel *transactionLabelTransaction_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BankAutomat)
    {
        if (BankAutomat->objectName().isEmpty())
            BankAutomat->setObjectName(QString::fromUtf8("BankAutomat"));
        BankAutomat->resize(800, 600);
        BankAutomat->setStyleSheet(QString::fromUtf8("background-color rgb(20, 27, 255);"));
        centralwidget = new QWidget(BankAutomat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -20, 831, 611));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 20pt \"Helvetica Neue\";\n"
"	color: #fff;\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: rgb(0, 150, 255);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	font: 18pt \"Helvetica Neue\";\n"
"	color: #fff;\n"
"}\n"
"QLineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: rgb(211, 236, 255);\n"
"    selection-background-color: darkgray;\n"
"}\n"
"QWidget {     \n"
"background-color:rgb(0, 0, 255);\n"
"}"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        loginlineEditKorttiID = new QLineEdit(loginPage);
        loginlineEditKorttiID->setObjectName(QString::fromUtf8("loginlineEditKorttiID"));
        loginlineEditKorttiID->setGeometry(QRect(310, 210, 231, 31));
        label = new QLabel(loginPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 220, 131, 21));
        label_2 = new QLabel(loginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 100, 331, 71));
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"Helvetica Neue\";"));
        loginBtnKirjaudu = new QPushButton(loginPage);
        loginBtnKirjaudu->setObjectName(QString::fromUtf8("loginBtnKirjaudu"));
        loginBtnKirjaudu->setGeometry(QRect(330, 340, 191, 51));
        loginBtnKirjaudu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        loginlineEditTunnusluku = new QLineEdit(loginPage);
        loginlineEditTunnusluku->setObjectName(QString::fromUtf8("loginlineEditTunnusluku"));
        loginlineEditTunnusluku->setGeometry(QRect(310, 270, 231, 31));
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 270, 131, 31));
        loginLabelInfo = new QLabel(loginPage);
        loginLabelInfo->setObjectName(QString::fromUtf8("loginLabelInfo"));
        loginLabelInfo->setGeometry(QRect(260, 420, 401, 71));
        label_12 = new QLabel(loginPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 30, 301, 71));
        label_12->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(loginPage);
        DepitCreditPage = new QWidget();
        DepitCreditPage->setObjectName(QString::fromUtf8("DepitCreditPage"));
        label_4 = new QLabel(DepitCreditPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 170, 191, 41));
        DebitCreditBtnDebit = new QPushButton(DepitCreditPage);
        DebitCreditBtnDebit->setObjectName(QString::fromUtf8("DebitCreditBtnDebit"));
        DebitCreditBtnDebit->setGeometry(QRect(210, 280, 151, 41));
        DebitCreditBtnDebit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        DebitCreditBtnCredit = new QPushButton(DepitCreditPage);
        DebitCreditBtnCredit->setObjectName(QString::fromUtf8("DebitCreditBtnCredit"));
        DebitCreditBtnCredit->setGeometry(QRect(450, 280, 151, 41));
        DebitCreditBtnCredit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_13 = new QLabel(DepitCreditPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 40, 301, 71));
        label_13->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(DepitCreditPage);
        Actionpage = new QWidget();
        Actionpage->setObjectName(QString::fromUtf8("Actionpage"));
        ActionBtnOtto = new QPushButton(Actionpage);
        ActionBtnOtto->setObjectName(QString::fromUtf8("ActionBtnOtto"));
        ActionBtnOtto->setGeometry(QRect(320, 170, 141, 41));
        ActionBtnOtto->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        ActionBtnSaldo = new QPushButton(Actionpage);
        ActionBtnSaldo->setObjectName(QString::fromUtf8("ActionBtnSaldo"));
        ActionBtnSaldo->setGeometry(QRect(320, 240, 141, 41));
        ActionBtnSaldo->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        ActionBtnTapahtumat = new QPushButton(Actionpage);
        ActionBtnTapahtumat->setObjectName(QString::fromUtf8("ActionBtnTapahtumat"));
        ActionBtnTapahtumat->setGeometry(QRect(320, 310, 141, 41));
        ActionBtnTapahtumat->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_5 = new QLabel(Actionpage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 100, 191, 41));
        label_14 = new QLabel(Actionpage);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 40, 311, 71));
        label_14->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(Actionpage);
        intakeInfopage = new QWidget();
        intakeInfopage->setObjectName(QString::fromUtf8("intakeInfopage"));
        intakeinfoBtnKuitille = new QPushButton(intakeInfopage);
        intakeinfoBtnKuitille->setObjectName(QString::fromUtf8("intakeinfoBtnKuitille"));
        intakeinfoBtnKuitille->setGeometry(QRect(200, 290, 141, 41));
        intakeinfoBtnKuitille->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        intakeinfoBtnNaytto = new QPushButton(intakeInfopage);
        intakeinfoBtnNaytto->setObjectName(QString::fromUtf8("intakeinfoBtnNaytto"));
        intakeinfoBtnNaytto->setGeometry(QRect(410, 290, 141, 41));
        intakeinfoBtnNaytto->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        intakeinfoBtnEi = new QPushButton(intakeInfopage);
        intakeinfoBtnEi->setObjectName(QString::fromUtf8("intakeinfoBtnEi"));
        intakeinfoBtnEi->setGeometry(QRect(200, 370, 141, 41));
        intakeinfoBtnEi->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_6 = new QLabel(intakeInfopage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 160, 311, 81));
        label_15 = new QLabel(intakeInfopage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 40, 321, 81));
        label_15->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(intakeInfopage);
        saldopage = new QWidget();
        saldopage->setObjectName(QString::fromUtf8("saldopage"));
        label_7 = new QLabel(saldopage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 130, 271, 51));
        label_8 = new QLabel(saldopage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 230, 151, 41));
        saldoBtnLopeta = new QPushButton(saldopage);
        saldoBtnLopeta->setObjectName(QString::fromUtf8("saldoBtnLopeta"));
        saldoBtnLopeta->setGeometry(QRect(570, 360, 121, 41));
        saldoBtnLopeta->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        saldoLabelTilinsaldo = new QLabel(saldopage);
        saldoLabelTilinsaldo->setObjectName(QString::fromUtf8("saldoLabelTilinsaldo"));
        saldoLabelTilinsaldo->setGeometry(QRect(410, 230, 151, 41));
        saldoBtnPalaa = new QPushButton(saldopage);
        saldoBtnPalaa->setObjectName(QString::fromUtf8("saldoBtnPalaa"));
        saldoBtnPalaa->setGeometry(QRect(90, 360, 121, 41));
        saldoBtnPalaa->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_16 = new QLabel(saldopage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 30, 331, 81));
        label_16->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(saldopage);
        withdrawpage = new QWidget();
        withdrawpage->setObjectName(QString::fromUtf8("withdrawpage"));
        withdrawBtn20 = new QPushButton(withdrawpage);
        withdrawBtn20->setObjectName(QString::fromUtf8("withdrawBtn20"));
        withdrawBtn20->setGeometry(QRect(320, 190, 131, 41));
        withdrawBtn20->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        withdrawBtn40 = new QPushButton(withdrawpage);
        withdrawBtn40->setObjectName(QString::fromUtf8("withdrawBtn40"));
        withdrawBtn40->setGeometry(QRect(320, 270, 131, 41));
        withdrawBtn40->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        withdrawBtn50 = new QPushButton(withdrawpage);
        withdrawBtn50->setObjectName(QString::fromUtf8("withdrawBtn50"));
        withdrawBtn50->setGeometry(QRect(320, 350, 131, 41));
        withdrawBtn50->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        withdrawBtn100 = new QPushButton(withdrawpage);
        withdrawBtn100->setObjectName(QString::fromUtf8("withdrawBtn100"));
        withdrawBtn100->setGeometry(QRect(320, 430, 131, 41));
        withdrawBtn100->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        withdrawlineEditAmount = new QLineEdit(withdrawpage);
        withdrawlineEditAmount->setObjectName(QString::fromUtf8("withdrawlineEditAmount"));
        withdrawlineEditAmount->setGeometry(QRect(590, 360, 131, 31));
        label_10 = new QLabel(withdrawpage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(590, 290, 201, 41));
        withdrawBtnOk = new QPushButton(withdrawpage);
        withdrawBtnOk->setObjectName(QString::fromUtf8("withdrawBtnOk"));
        withdrawBtnOk->setGeometry(QRect(590, 430, 131, 41));
        withdrawBtnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        withdrawBtnPaluu = new QPushButton(withdrawpage);
        withdrawBtnPaluu->setObjectName(QString::fromUtf8("withdrawBtnPaluu"));
        withdrawBtnPaluu->setGeometry(QRect(50, 430, 131, 41));
        withdrawBtnPaluu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_11 = new QLabel(withdrawpage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(350, 110, 121, 41));
        label_17 = new QLabel(withdrawpage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 30, 291, 81));
        label_17->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(withdrawpage);
        Transactionpage = new QWidget();
        Transactionpage->setObjectName(QString::fromUtf8("Transactionpage"));
        label_9 = new QLabel(Transactionpage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(260, 130, 341, 81));
        transactionLabelTransaction = new QLabel(Transactionpage);
        transactionLabelTransaction->setObjectName(QString::fromUtf8("transactionLabelTransaction"));
        transactionLabelTransaction->setGeometry(QRect(100, 230, 181, 141));
        TransactionBtnLopeta = new QPushButton(Transactionpage);
        TransactionBtnLopeta->setObjectName(QString::fromUtf8("TransactionBtnLopeta"));
        TransactionBtnLopeta->setGeometry(QRect(580, 420, 121, 41));
        TransactionBtnLopeta->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        TransactionBtnPalaa = new QPushButton(Transactionpage);
        TransactionBtnPalaa->setObjectName(QString::fromUtf8("TransactionBtnPalaa"));
        TransactionBtnPalaa->setGeometry(QRect(100, 420, 121, 41));
        TransactionBtnPalaa->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 137, 255);"));
        label_18 = new QLabel(Transactionpage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 30, 291, 81));
        label_18->setStyleSheet(QString::fromUtf8("color:rgb(255, 175, 0);"));
        transactionLabelTransaction_2 = new QLabel(Transactionpage);
        transactionLabelTransaction_2->setObjectName(QString::fromUtf8("transactionLabelTransaction_2"));
        transactionLabelTransaction_2->setGeometry(QRect(500, 230, 181, 141));
        transactionLabelTransaction_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        transactionLabelTransaction_3 = new QLabel(Transactionpage);
        transactionLabelTransaction_3->setObjectName(QString::fromUtf8("transactionLabelTransaction_3"));
        transactionLabelTransaction_3->setGeometry(QRect(300, 230, 181, 141));
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
        label_2->setText(QApplication::translate("BankAutomat", "<h1>Kirjaudu sis\303\244\303\244n</h1>", nullptr));
        loginBtnKirjaudu->setText(QApplication::translate("BankAutomat", "Kirjaudu", nullptr));
        label_3->setText(QApplication::translate("BankAutomat", "Tunnusluku", nullptr));
        loginLabelInfo->setText(QString());
        label_12->setText(QApplication::translate("BankAutomat", "<h1> OttoMaatti</h1>", nullptr));
        label_4->setText(QApplication::translate("BankAutomat", "<h2>Valitse</h2>", nullptr));
        DebitCreditBtnDebit->setText(QApplication::translate("BankAutomat", "Debit", nullptr));
        DebitCreditBtnCredit->setText(QApplication::translate("BankAutomat", "Credit", nullptr));
        label_13->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        ActionBtnOtto->setText(QApplication::translate("BankAutomat", "Otto", nullptr));
        ActionBtnSaldo->setText(QApplication::translate("BankAutomat", "Saldo", nullptr));
        ActionBtnTapahtumat->setText(QApplication::translate("BankAutomat", "Tapahtumat", nullptr));
        label_5->setText(QApplication::translate("BankAutomat", "<h2>Valitse</h2>", nullptr));
        label_14->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        intakeinfoBtnKuitille->setText(QApplication::translate("BankAutomat", "Kuitille", nullptr));
        intakeinfoBtnNaytto->setText(QApplication::translate("BankAutomat", "N\303\244yt\303\266lle", nullptr));
        intakeinfoBtnEi->setText(QApplication::translate("BankAutomat", "Ei kiitos", nullptr));
        label_6->setText(QApplication::translate("BankAutomat", "<h2>Haluatko tiedot</h2>", nullptr));
        label_15->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        label_7->setText(QApplication::translate("BankAutomat", "<h2>Tilin tilanne</h2>", nullptr));
        label_8->setText(QApplication::translate("BankAutomat", "Tilin saldo", nullptr));
        saldoBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", nullptr));
        saldoLabelTilinsaldo->setText(QApplication::translate("BankAutomat", "60 euroa", nullptr));
        saldoBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", nullptr));
        label_16->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        withdrawBtn20->setText(QApplication::translate("BankAutomat", "20", nullptr));
        withdrawBtn40->setText(QApplication::translate("BankAutomat", "40", nullptr));
        withdrawBtn50->setText(QApplication::translate("BankAutomat", "50", nullptr));
        withdrawBtn100->setText(QApplication::translate("BankAutomat", "100", nullptr));
        label_10->setText(QApplication::translate("BankAutomat", "<strong>Muu summa</strong>", nullptr));
        withdrawBtnOk->setText(QApplication::translate("BankAutomat", "Ok", nullptr));
        withdrawBtnPaluu->setText(QApplication::translate("BankAutomat", "Paluu", nullptr));
        label_11->setText(QApplication::translate("BankAutomat", "<h2>Otto</h2>", nullptr));
        label_17->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        label_9->setText(QApplication::translate("BankAutomat", "<h2>Tilin tapahtumat</h2>", nullptr));
        transactionLabelTransaction->setText(QApplication::translate("BankAutomat", "01.01.1990<br>01.01.1990<br>01.01.1990<br>01.01.1990<br>", nullptr));
        TransactionBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", nullptr));
        TransactionBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", nullptr));
        label_18->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", nullptr));
        transactionLabelTransaction_2->setText(QApplication::translate("BankAutomat", "90 euroa<br>90 euroa<br>90 euroa<br>90 euroa<br>", nullptr));
        transactionLabelTransaction_3->setText(QApplication::translate("BankAutomat", "Pano<br>Pano<br>Pano<br>Pano<br>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BankAutomat: public Ui_BankAutomat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKAUTOMAT_H
