#include "bankautomat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BankAutomat w;
    w.show();
    return a.exec();
}
