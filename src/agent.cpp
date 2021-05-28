#include "agent.h"
#include <QTimer>
#include <QImage>
#include <iostream>

Agent::Agent(QWidget *parent)
{
    bag = new Bag(parent, this);
}

Agent::~Agent()
{

}
Bag* Agent::getBag() {
    return bag;
}

void Agent::update() {
}

//void Agent::paintEvent(QPaintEvent *event)
//{
//    QImage* m_img = new QImage(":/images/bg/bg_black.jpg");
//    QPainter *painter = new QPainter(this);
//    painter->drawImage(QRect(0, 0, m_img->width(), m_img->height()), *m_img);
//    painter->end();
//}
