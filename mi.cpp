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
}
