#ifndef RECEIPT_H
#define RECEIPT_H

#include <QWidget>

namespace Ui {
class Receipt;
}

class Receipt : public QWidget
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = 0);
    ~Receipt();

private:
    Ui::Receipt *ui;
};

#endif // RECEIPT_H
