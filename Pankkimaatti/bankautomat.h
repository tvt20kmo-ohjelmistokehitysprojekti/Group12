#ifndef BANKAUTOMAT_H
#define BANKAUTOMAT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BankAutomat; }
QT_END_NAMESPACE

class BankAutomat : public QMainWindow
{
    Q_OBJECT

public:
    BankAutomat(QWidget *parent = nullptr);
    ~BankAutomat();

private slots:
    void on_loginBtnKirjaudu_clicked();

    void on_withdrawBtn100_clicked(bool checked);

    void on_DebitCreditBtnCredit_clicked();

    void on_DebitCreditBtnDebit_clicked();

    void on_ActionBtnOtto_clicked();

    void on_ActionBtnSaldo_clicked();

    void on_ActionBtnTapahtumat_clicked();

    void on_intakeinfoBtnEi_clicked();

    void on_intakeinfoBtnKuitille_clicked();

    void on_intakeinfoBtnNaytto_clicked();

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

private:
    Ui::BankAutomat *ui;
};
#endif // BANKAUTOMAT_H
