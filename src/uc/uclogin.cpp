#include "uclogin.h"

UCLogin::UCLogin(QWidget *parent): UCBase(parent)
{
    this->resize(958, 538);
    this->setMinimumSize(958, 538);
    this->setMaximumSize(958, 538);
}

UCLogin::~UCLogin() {

}

void UCLogin::paintEvent(QPaintEvent *event) {

    QImage *a_img = new QImage(":/images/scene/s_login_v1.jpg");
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(1, 1, 960 - 1, 540 - 1), *a_img, QRect(0, 0, 960, 540));
    painter->end();
    cout<<this->height()<<"--"<<this->width()<<endl;
}
