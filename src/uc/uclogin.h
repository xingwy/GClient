#ifndef UCLOGIN_H
#define UCLOGIN_H

#include <iostream>
#include <QImage>
#include <QPainter>
#include "../base/ucbase.h"

using namespace std;


class UCLogin: UCBase
{
public:
    UCLogin(QWidget *parent = nullptr);
    ~UCLogin();

    void paintEvent(QPaintEvent *event);
};

#endif // UCLOGIN_H
