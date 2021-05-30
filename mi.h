#ifndef MI_H
#define MI_H

#include <QImage>
#include <QObject>
#include <QWidget>
#include <QPainter>

#include <iostream>
#include <qui.h>
#include <constant.h>



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
