#include "mi.h"

mi::mi(QWidget *parent) : QWidget(parent)
{
    x = 0;
}

void mi::paintEvent(QPaintEvent *event)
{

//    int x, int y, const QImage &image, int sx, int sy, int sw, int sh,Qt::ImageConversionFlags flags
    QImage* m_img = new QImage(":/images/tank.jpg");
    QPainter *painter = new QPainter(this);
    painter->drawImage(x, 0, *m_img, 100, 100, 50, 50);
    x++;
    cout<<"draw"<<endl;
}
