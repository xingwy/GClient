#ifndef UCHALL_H
#define UCHALL_H

#include <iostream>
#include <QImage>
#include <QPainter>

#include "ucbase.h"
#include "constant.h"

class UCHall: public UCBase
{
public:
    UCHall(QWidget *parent);
    ~UCHall();
    void paintEvent(QPaintEvent *event);
};

#endif // UCHALL_H
