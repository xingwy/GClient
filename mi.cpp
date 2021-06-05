#include "mi.h"
#include <QDebug>
mi::mi(QWidget *parent) : QUi(parent)
{
    this->setFixedSize(960, 540);
}

void mi::paintEvent(QPaintEvent *event)
{
    qDebug()<<"uc mi";
    QImage* m_img = new QImage(GAME_BG_IMG);
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(0, 0, GAME_BG_WIDTH, GAME_BG_HEIGHT), *m_img, QRect(0, 0, m_img->width(), m_img->height()));
    painter->end();
}
