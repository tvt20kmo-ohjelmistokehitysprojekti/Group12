/********************************************************************************
** Form generated from reading UI file 'bankautomat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKAUTOMAT_H
#define UI_BANKAUTOMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QPushButton *withdrawBtnPaluu;
    QLabel *label_11;
    QLabel *label_17;
    QPushButton *withdrawBtn20_2;
    QFrame *frame;
    QLabel *label_10;
    QPushButton *withdrawBtnOk;
    QLineEdit *withdrawlineEditAmount;
    QLabel *withdrawLabelInfo;
    QWidget *Transactionpage;
    QLabel *label_9;
    QLabel *transactionLabelDate;
    QPushButton *TransactionBtnLopeta;
    QPushButton *TransactionBtnPalaa;
    QLabel *label_18;
    QLabel *transactionLabelSum;
    QLabel *transactionLabelTransact;
    QWidget *Endingpage;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BankAutomat)
    {
        if (BankAutomat->objectName().isEmpty())
            BankAutomat->setObjectName(QStringLiteral("BankAutomat"));
        BankAutomat->resize(800, 600);
        BankAutomat->setStyleSheet(QStringLiteral("background-color rgb(20, 27, 255);"));
        centralwidget = new QWidget(BankAutomat);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -20, 801, 601));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QLatin1String("QPushButton {\n"
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
        stackedWidget->setLineWidth(0);
        loginPage = new QWidget();
        loginPage->setObjectName(QStringLiteral("loginPage"));
        loginlineEditKorttiID = new QLineEdit(loginPage);
        loginlineEditKorttiID->setObjectName(QStringLiteral("loginlineEditKorttiID"));
        loginlineEditKorttiID->setGeometry(QRect(310, 210, 231, 31));
        label = new QLabel(loginPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 220, 131, 21));
        label_2 = new QLabel(loginPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 100, 331, 71));
        label_2->setStyleSheet(QStringLiteral("font: 13pt \"Helvetica Neue\";"));
        loginBtnKirjaudu = new QPushButton(loginPage);
        loginBtnKirjaudu->setObjectName(QStringLiteral("loginBtnKirjaudu"));
        loginBtnKirjaudu->setGeometry(QRect(330, 340, 191, 51));
        loginBtnKirjaudu->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        loginlineEditTunnusluku = new QLineEdit(loginPage);
        loginlineEditTunnusluku->setObjectName(QStringLiteral("loginlineEditTunnusluku"));
        loginlineEditTunnusluku->setGeometry(QRect(310, 270, 231, 31));
        loginlineEditTunnusluku->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 270, 131, 31));
        loginLabelInfo = new QLabel(loginPage);
        loginLabelInfo->setObjectName(QStringLiteral("loginLabelInfo"));
        loginLabelInfo->setGeometry(QRect(150, 420, 561, 71));
        label_12 = new QLabel(loginPage);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 20, 301, 81));
        label_12->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(loginPage);
        DepitCreditPage = new QWidget();
        DepitCreditPage->setObjectName(QStringLiteral("DepitCreditPage"));
        label_4 = new QLabel(DepitCreditPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 170, 191, 41));
        DebitCreditBtnDebit = new QPushButton(DepitCreditPage);
        DebitCreditBtnDebit->setObjectName(QStringLiteral("DebitCreditBtnDebit"));
        DebitCreditBtnDebit->setGeometry(QRect(210, 280, 151, 41));
        DebitCreditBtnDebit->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        DebitCreditBtnCredit = new QPushButton(DepitCreditPage);
        DebitCreditBtnCredit->setObjectName(QStringLiteral("DebitCreditBtnCredit"));
        DebitCreditBtnCredit->setGeometry(QRect(450, 280, 151, 41));
        DebitCreditBtnCredit->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        label_13 = new QLabel(DepitCreditPage);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 20, 301, 81));
        label_13->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(DepitCreditPage);
        Actionpage = new QWidget();
        Actionpage->setObjectName(QStringLiteral("Actionpage"));
        ActionBtnOtto = new QPushButton(Actionpage);
        ActionBtnOtto->setObjectName(QStringLiteral("ActionBtnOtto"));
        ActionBtnOtto->setGeometry(QRect(320, 170, 141, 41));
        ActionBtnOtto->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        ActionBtnSaldo = new QPushButton(Actionpage);
        ActionBtnSaldo->setObjectName(QStringLiteral("ActionBtnSaldo"));
        ActionBtnSaldo->setGeometry(QRect(320, 240, 141, 41));
        ActionBtnSaldo->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        ActionBtnTapahtumat = new QPushButton(Actionpage);
        ActionBtnTapahtumat->setObjectName(QStringLiteral("ActionBtnTapahtumat"));
        ActionBtnTapahtumat->setGeometry(QRect(320, 310, 141, 41));
        ActionBtnTapahtumat->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        label_5 = new QLabel(Actionpage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(340, 100, 191, 41));
        label_14 = new QLabel(Actionpage);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 20, 311, 81));
        label_14->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(Actionpage);
        saldopage = new QWidget();
        saldopage->setObjectName(QStringLiteral("saldopage"));
        label_7 = new QLabel(saldopage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(300, 130, 271, 51));
        label_8 = new QLabel(saldopage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 230, 151, 41));
        saldoBtnLopeta = new QPushButton(saldopage);
        saldoBtnLopeta->setObjectName(QStringLiteral("saldoBtnLopeta"));
        saldoBtnLopeta->setGeometry(QRect(570, 360, 121, 41));
        saldoBtnLopeta->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        saldoLabelTilinsaldo = new QLabel(saldopage);
        saldoLabelTilinsaldo->setObjectName(QStringLiteral("saldoLabelTilinsaldo"));
        saldoLabelTilinsaldo->setGeometry(QRect(410, 230, 151, 41));
        saldoBtnPalaa = new QPushButton(saldopage);
        saldoBtnPalaa->setObjectName(QStringLiteral("saldoBtnPalaa"));
        saldoBtnPalaa->setGeometry(QRect(90, 360, 121, 41));
        saldoBtnPalaa->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        label_16 = new QLabel(saldopage);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 20, 331, 81));
        label_16->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        stackedWidget->addWidget(saldopage);
        withdrawpage = new QWidget();
        withdrawpage->setObjectName(QStringLiteral("withdrawpage"));
        withdrawBtn20 = new QPushButton(withdrawpage);
        withdrawBtn20->setObjectName(QStringLiteral("withdrawBtn20"));
        withdrawBtn20->setGeometry(QRect(40, 180, 131, 41));
        withdrawBtn20->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        withdrawBtn40 = new QPushButton(withdrawpage);
        withdrawBtn40->setObjectName(QStringLiteral("withdrawBtn40"));
        withdrawBtn40->setGeometry(QRect(40, 270, 131, 41));
        withdrawBtn40->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        withdrawBtn50 = new QPushButton(withdrawpage);
        withdrawBtn50->setObjectName(QStringLiteral("withdrawBtn50"));
        withdrawBtn50->setGeometry(QRect(600, 180, 131, 41));
        withdrawBtn50->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        withdrawBtn100 = new QPushButton(withdrawpage);
        withdrawBtn100->setObjectName(QStringLiteral("withdrawBtn100"));
        withdrawBtn100->setGeometry(QRect(600, 270, 131, 41));
        withdrawBtn100->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        withdrawBtnPaluu = new QPushButton(withdrawpage);
        withdrawBtnPaluu->setObjectName(QStringLiteral("withdrawBtnPaluu"));
        withdrawBtnPaluu->setGeometry(QRect(50, 480, 131, 41));
        withdrawBtnPaluu->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        label_11 = new QLabel(withdrawpage);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(350, 110, 121, 41));
        label_17 = new QLabel(withdrawpage);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 20, 291, 81));
        label_17->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        withdrawBtn20_2 = new QPushButton(withdrawpage);
        withdrawBtn20_2->setObjectName(QStringLiteral("withdrawBtn20_2"));
        withdrawBtn20_2->setGeometry(QRect(580, 470, 181, 41));
        withdrawBtn20_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        frame = new QFrame(withdrawpage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(230, 280, 341, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 0, 311, 41));
        label_10->setAlignment(Qt::AlignCenter);
        withdrawBtnOk = new QPushButton(frame);
        withdrawBtnOk->setObjectName(QStringLiteral("withdrawBtnOk"));
        withdrawBtnOk->setGeometry(QRect(100, 140, 131, 41));
        withdrawBtnOk->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        withdrawlineEditAmount = new QLineEdit(frame);
        withdrawlineEditAmount->setObjectName(QStringLiteral("withdrawlineEditAmount"));
        withdrawlineEditAmount->setGeometry(QRect(100, 70, 131, 31));
        withdrawLabelInfo = new QLabel(withdrawpage);
        withdrawLabelInfo->setObjectName(QStringLiteral("withdrawLabelInfo"));
        withdrawLabelInfo->setGeometry(QRect(230, 160, 341, 91));
        withdrawLabelInfo->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(withdrawpage);
        Transactionpage = new QWidget();
        Transactionpage->setObjectName(QStringLiteral("Transactionpage"));
        label_9 = new QLabel(Transactionpage);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 130, 341, 81));
        transactionLabelDate = new QLabel(Transactionpage);
        transactionLabelDate->setObjectName(QStringLiteral("transactionLabelDate"));
        transactionLabelDate->setGeometry(QRect(100, 210, 181, 191));
        TransactionBtnLopeta = new QPushButton(Transactionpage);
        TransactionBtnLopeta->setObjectName(QStringLiteral("TransactionBtnLopeta"));
        TransactionBtnLopeta->setGeometry(QRect(580, 420, 121, 41));
        TransactionBtnLopeta->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        TransactionBtnPalaa = new QPushButton(Transactionpage);
        TransactionBtnPalaa->setObjectName(QStringLiteral("TransactionBtnPalaa"));
        TransactionBtnPalaa->setGeometry(QRect(100, 420, 121, 41));
        TransactionBtnPalaa->setStyleSheet(QStringLiteral("background-color: rgb(0, 137, 255);"));
        label_18 = new QLabel(Transactionpage);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 20, 291, 81));
        label_18->setStyleSheet(QStringLiteral("color:rgb(255, 175, 0);"));
        transactionLabelSum = new QLabel(Transactionpage);
        transactionLabelSum->setObjectName(QStringLiteral("transactionLabelSum"));
        transactionLabelSum->setGeometry(QRect(500, 210, 181, 191));
        transactionLabelSum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        transactionLabelTransact = new QLabel(Transactionpage);
        transactionLabelTransact->setObjectName(QStringLiteral("transactionLabelTransact"));
        transactionLabelTransact->setGeometry(QRect(300, 200, 181, 211));
        stackedWidget->addWidget(Transactionpage);
        Endingpage = new QWidget();
        Endingpage->setObjectName(QStringLiteral("Endingpage"));
        label_19 = new QLabel(Endingpage);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(160, 70, 451, 131));
        label_20 = new QLabel(Endingpage);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(50, 390, 731, 101));
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(Endingpage);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 210, 651, 161));
        label_21->setStyleSheet(QLatin1String("image: url(:/img/img/Pankkimaattikuva.png);\n"
"widht:300px;\n"
""));
        stackedWidget->addWidget(Endingpage);
        BankAutomat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BankAutomat);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        BankAutomat->setMenuBar(menubar);
        statusbar = new QStatusBar(BankAutomat);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BankAutomat->setStatusBar(statusbar);

        retranslateUi(BankAutomat);

        QMetaObject::connectSlotsByName(BankAutomat);
    } // setupUi

    void retranslateUi(QMainWindow *BankAutomat)
    {
        BankAutomat->setWindowTitle(QApplication::translate("BankAutomat", "BankAutomat", Q_NULLPTR));
        label->setText(QApplication::translate("BankAutomat", "KorttiID", Q_NULLPTR));
        label_2->setText(QApplication::translate("BankAutomat", "<h1>Kirjaudu sis\303\244\303\244n</h1>", Q_NULLPTR));
        loginBtnKirjaudu->setText(QApplication::translate("BankAutomat", "Kirjaudu", Q_NULLPTR));
        loginlineEditTunnusluku->setText(QApplication::translate("BankAutomat", "1234", Q_NULLPTR));
        label_3->setText(QApplication::translate("BankAutomat", "Tunnusluku", Q_NULLPTR));
        loginLabelInfo->setText(QString());
        label_12->setText(QApplication::translate("BankAutomat", "<h1> OttoMaatti</h1>", Q_NULLPTR));
        label_4->setText(QApplication::translate("BankAutomat", "<h2>Valitse</h2>", Q_NULLPTR));
        DebitCreditBtnDebit->setText(QApplication::translate("BankAutomat", "Debit", Q_NULLPTR));
        DebitCreditBtnCredit->setText(QApplication::translate("BankAutomat", "Credit", Q_NULLPTR));
        label_13->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", Q_NULLPTR));
        ActionBtnOtto->setText(QApplication::translate("BankAutomat", "Otto", Q_NULLPTR));
        ActionBtnSaldo->setText(QApplication::translate("BankAutomat", "Saldo", Q_NULLPTR));
        ActionBtnTapahtumat->setText(QApplication::translate("BankAutomat", "Tapahtumat", Q_NULLPTR));
        label_5->setText(QApplication::translate("BankAutomat", "<h2>Valitse</h2>", Q_NULLPTR));
        label_14->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", Q_NULLPTR));
        label_7->setText(QApplication::translate("BankAutomat", "<h2>Tilin tilanne</h2>", Q_NULLPTR));
        label_8->setText(QApplication::translate("BankAutomat", "Tilin saldo", Q_NULLPTR));
        saldoBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", Q_NULLPTR));
        saldoLabelTilinsaldo->setText(QApplication::translate("BankAutomat", "60 euroa", Q_NULLPTR));
        saldoBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", Q_NULLPTR));
        label_16->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", Q_NULLPTR));
        withdrawBtn20->setText(QApplication::translate("BankAutomat", "20", Q_NULLPTR));
        withdrawBtn40->setText(QApplication::translate("BankAutomat", "40", Q_NULLPTR));
        withdrawBtn50->setText(QApplication::translate("BankAutomat", "50", Q_NULLPTR));
        withdrawBtn100->setText(QApplication::translate("BankAutomat", "100", Q_NULLPTR));
        withdrawBtnPaluu->setText(QApplication::translate("BankAutomat", "Paluu", Q_NULLPTR));
        label_11->setText(QApplication::translate("BankAutomat", "<h2>Otto</h2>", Q_NULLPTR));
        label_17->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", Q_NULLPTR));
        withdrawBtn20_2->setText(QApplication::translate("BankAutomat", "Muu summa", Q_NULLPTR));
        label_10->setText(QApplication::translate("BankAutomat", "<strong>N\303\244pp\303\244ile summa</strong>", Q_NULLPTR));
        withdrawBtnOk->setText(QApplication::translate("BankAutomat", "Ok", Q_NULLPTR));
        withdrawLabelInfo->setText(QString());
        label_9->setText(QApplication::translate("BankAutomat", "<h2>Tilin tapahtumat</h2>", Q_NULLPTR));
        transactionLabelDate->setText(QApplication::translate("BankAutomat", "01.01.1990<br>01.01.1990<br>01.01.1990<br>01.01.1990<br>", Q_NULLPTR));
        TransactionBtnLopeta->setText(QApplication::translate("BankAutomat", "Lopeta", Q_NULLPTR));
        TransactionBtnPalaa->setText(QApplication::translate("BankAutomat", "Palaa", Q_NULLPTR));
        label_18->setText(QApplication::translate("BankAutomat", "<h1>OttoMaatti</h1>", Q_NULLPTR));
        transactionLabelSum->setText(QApplication::translate("BankAutomat", "90 euroa<br>90 euroa<br>90 euroa<br>90 euroa<br>", Q_NULLPTR));
        transactionLabelTransact->setText(QApplication::translate("BankAutomat", "Pano<br>Pano<br>Pano<br>Pano<br>", Q_NULLPTR));
        label_19->setText(QApplication::translate("BankAutomat", "<h2>Ota rahat, ole hyv\303\244.</h2>", Q_NULLPTR));
        label_20->setText(QApplication::translate("BankAutomat", "<h3>Kiitos k\303\244ynnist\303\244, tervetuloa uudelleen!</h3>", Q_NULLPTR));
        label_21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BankAutomat: public Ui_BankAutomat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKAUTOMAT_H
