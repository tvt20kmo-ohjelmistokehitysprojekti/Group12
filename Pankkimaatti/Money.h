#ifndef Money_H
#define Money_H

#include <QMainWindow>

namespace Ui {
class Money;
}

class Money : public QMainWindow
{
    Q_OBJECT

public:
    explicit Money(QWidget *parent = nullptr);
    Money(QWidget *parent, int);
    ~Money();

    void setSubset(int);
    void setImg(int x);
    void openNotes();
private slots:

private:
    Ui::Money *ui;
    int notes[3] = {100,50,20};
    int subset[3] = {0,0,0};
};

#endif // Money_H
