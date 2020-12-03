#include "moneywndow.h"
#include "ui_moneywndow.h"
#include <QPixmap>



MoneyWndow::MoneyWndow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MoneyWndow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

void MoneyWndow::setNotes(QString sum){
    QString path;
    int x = sum.toInt();
    openNotesSubSet(x);
}
MoneyWndow::MoneyWndow(QWidget *parent, int x):
    QMainWindow(parent),
    ui(new Ui::MoneyWndow)
{
    ui->setupUi(this);
    this->setImg(x);
}

void MoneyWndow::setImg(int x){
    QString path;

    switch (x) {
    case 20:
        path = ":/img/img/20.jpg";
        break;
    case 100:
        path = ":/img/img/100.jpg";
        break;
    case 50:
        path = ":/img/img/50.jpg";
        break;
    default:
        break;
    }

    QPixmap img(path);
    ui->label->setPixmap(img);
}

MoneyWndow::~MoneyWndow()
{
    delete ui;
}


void MoneyWndow::openNotesSubSet(int sum){

    if (sum > 5000){  //rajoitetaan kuin paljo avataan
        sum = 5000;
    }
    int notes[] = {100,50,20};
    static int subset[3];

    bool next = "false";

    int temp = 0,temp2 = 0;
        for(int i = 0;i < 3 ;i++){
            if(sum>=notes[i] || !next){
                temp = sum / notes[i];
                temp2 = sum - temp*notes[i];
                if(!(temp2%20) || !(temp2%50) || !((temp2%50)%20)){
                    sum = temp2;
                    subset[i] = temp;
                }
                else{   next="true";}
            }
        }//endfor
    //Open money windows
    bool first = true;
    int x = 20;
    for (int i = 0;i<3;i++){
        for (;subset[i]>0;subset[i]--){
            if (first){ // set first note img to this
                this->setImg(notes[i]);
                first = false;
            }
            else{
                MoneyWndow * moneys = new MoneyWndow(this,notes[i]);
                 moneys->setGeometry((this->x()+x),(this->y()+x),530,280);  //toinen ikkuna menee eri linjaa jostain syystä
                 moneys->show();
                 x+=20;
            }

    }
    }
}


