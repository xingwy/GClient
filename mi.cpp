#include "mi.h"

mi::mi(QWidget *parent) : QUi(parent)
{
    x = 0;
}

void mi::paintEvent(QPaintEvent *event)
{
    QImage* m_img = new QImage(":/images/river.jpg");
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(x, 0, m_img->width(), m_img->height()), *m_img);
    painter->end();
    x++;
    cout<<"draw"<<m_img->width()<<" "<<m_img->height()<<endl;
}
