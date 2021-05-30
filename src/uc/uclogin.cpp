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
    QWidget::paintEvent(event);
    QImage *login_bg_img = new QImage(RES_LOGIN_BG_IMG);
    QPainter *painter = new QPainter(this);
    painter->drawImage(QRect(0, 0, LOGIN_BG_WIDTH, LOGIN_BG_HEIGHT), *login_bg_img, QRect(0, 0, login_bg_img->width(), login_bg_img->height()));
    painter->end();

}
