#ifndef MONEYWNDOW_H
#define MONEYWNDOW_H

#include <QMainWindow>

namespace Ui {
class MoneyWndow;
}

class MoneyWndow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MoneyWndow(QWidget *parent = nullptr);
    MoneyWndow(QWidget *parent, int);
    ~MoneyWndow();


    void openNotesSubSet(int);
    void setNotes(QString);
    void set(int);
    void setImg(int x);
private slots:

private:
    Ui::MoneyWndow *ui;
};

#endif // MONEYWNDOW_H
