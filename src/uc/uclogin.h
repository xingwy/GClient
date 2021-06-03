#ifndef UCLOGIN_H
#define UCLOGIN_H

#include <iostream>
#include <QImage>
#include <QPainter>

#include "ucbase.h"
#include "constant.h"

using namespace std;


class UCLogin: public UCBase
{
public:
    UCLogin(QWidget *parent = nullptr);
    ~UCLogin();

    void paintEvent(QPaintEvent *event);
};

#endif // UCLOGIN_H
