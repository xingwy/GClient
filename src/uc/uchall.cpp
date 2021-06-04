#include "uchall.h"
#include <QDebug>

UCHall::UCHall(QWidget *parent): UCBase(parent)
{
    this->resize(HALL_BG_WIDTH, HALL_BG_HEIGHT);
    this->setMinimumSize(HALL_BG_WIDTH, HALL_BG_HEIGHT);
    this->setMaximumSize(HALL_BG_WIDTH, HALL_BG_HEIGHT);
//    this->hide();
}

UCHall::~UCHall()
{

}

void UCHall::paintEvent(QPaintEvent *event) {
    qDebug()<<"uc hall";
    QWidget::paintEvent(event);
    QImage *hall_bg_img = new QImage(RES_HALL_BG_IMG);
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(0, 0, HALL_BG_WIDTH, HALL_BG_HEIGHT), *hall_bg_img, QRect(0, 0, hall_bg_img->width(), hall_bg_img->height()));
    painter->end();

}
