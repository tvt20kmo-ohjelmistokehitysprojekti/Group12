#ifndef BANKAUTOMAT_H
#define BANKAUTOMAT_H

#include <QMainWindow>
#include <QUrl>
#include <QtNetwork>


QT_BEGIN_NAMESPACE
namespace Ui { class BankAutomat; }
QT_END_NAMESPACE

class BankAutomat : public QMainWindow
{
    Q_OBJECT

public:
    BankAutomat(QWidget *parent = nullptr);
    ~BankAutomat();

    QNetworkAccessManager* nam = new QNetworkAccessManager(this);

    QUrl baseUrl;

    QString getKorttiID() const;
    void setKorttiID(const QString &value);

    QString getTiliID() const;
    void setTiliID(const QString &value);

    void CreditDebit(QString);

    void withdraw(QString amount);

    QByteArray getNetworkreply(QJsonObject, QString);

    void clearInfo();


    void setLineEditValidation();

    QString Saldo();
public slots:
    void authRequired(QNetworkReply *Reply,QAuthenticator *Authenticator);

   void gotologin();

private slots:


    void on_loginBtnKirjaudu_clicked();

    void on_DebitCreditBtnCredit_clicked();

    void on_DebitCreditBtnDebit_clicked();

    void on_ActionBtnOtto_clicked();

    void on_ActionBtnSaldo_clicked();

    void on_ActionBtnTapahtumat_clicked();

    void on_saldoBtnLopeta_clicked();

    void on_saldoBtnPalaa_clicked();

    void on_withdrawBtn100_clicked();

    void on_withdrawBtn20_clicked();

    void on_withdrawBtn40_clicked();

    void on_withdrawBtn50_clicked();

    void on_withdrawBtnOk_clicked();

    void on_withdrawBtnPaluu_clicked();

    void on_TransactionBtnLopeta_clicked();

    void on_TransactionBtnPalaa_clicked();

    void on_withdrawBtnOther_clicked(bool checked);

    void on_saldoBtnLopeta_3_clicked();

    void on_saldoBtnLopeta_2_clicked();


private:
    Ui::BankAutomat *ui;

    QString KorttiID;
    QString TiliID;
    bool isCredit = false;


};
#endif // BANKAUTOMAT_H
