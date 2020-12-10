#include "Money.h"
#include "ui_Money.h"
#include <QPixmap>

/* Opens images of notes in new window used for school project atm machine
 *
 * Money::Money(QWidget *parent)
 * // Opens blank money window and sets DeleteonClose flag
 * Money::Money(QWidget *parent, int x)
 * //Opens new window where image is note of value of x
 * void Money::setImg(int x)
 * //Sets image where image is note of value of x
 * void Money::setSubset(int sum){
 * // Creates sum subset from notes
 * void Money::openNotes()
 * //Opens all moneys set in subset first note image to current window +diagonal offset
 *
 *
 * --- **MA**
*/


Money::Money(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Money)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

Money::Money(QWidget *parent, int x):
    QMainWindow(parent),
    ui(new Ui::Money)
{
    ui->setupUi(this);
    this->setImg(x);
}

void Money::setImg(int x){
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

Money::~Money()
{
    delete ui;
}

void Money::setSubset(int sum){

    if (sum > 2000){  //limit
        sum = 2000;
    }
    for(int i = 0;i < 3 ;i++){
        if(sum>=notes[i]){
            if(!(sum%notes[i]%20) || !(sum%notes[i]%50%20)){
                subset[i] = sum / notes[i];
                sum = sum % notes[i];
            }
        }
    }//endfor
}

void Money::openNotes(){
    bool first = true;
    int x = this->x()+10, y = this->y()+30;
    for (int i = 0;i<3;i++){
        for (;subset[i]>0;subset[i]--){
            if (first){
                this->setImg(notes[i]);
                first = false;
            }
            else{
                Money * moneys = new Money(this,notes[i]);
                 moneys->setGeometry(x,y,530,280);
                 moneys->show();
            }
            x+=20;
            y+=20;

        }//end second for
    }//end for
}



