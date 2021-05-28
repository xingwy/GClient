#include "mi.h"

mi::mi(QWidget *parent) : QUi(parent)
{
    x = 0;
    this->setFixedSize(960, 540);
}

void mi::paintEvent(QPaintEvent *event)
{
    QImage* m_img = new QImage(":/images/bg/bg_black.jpg");
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(0, 0, m_img->width(), m_img->height()), *m_img);
    painter->end();

//    QImage *a_img = new QImage(":/images/scene/s_login_v1.jpg");
//    QPainter *painter1 = new QPainter(this);
//    painter1->drawImage(QRect(0, 0, 480, 270), *a_img, QRect(0, 0, 960, 540));
//    painter1->end();
//    cout<<a_img->width()<<"--"<<a_img->height()<<endl;
}
