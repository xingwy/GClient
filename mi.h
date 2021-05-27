#ifndef MI_H
#define MI_H

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <iostream>
#include "./lib/qui.h"

using namespace std;
class mi : public QUi
{
    Q_OBJECT
public:
    explicit mi(QWidget *parent = nullptr);

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    int x;
};

#endif // MI_H
