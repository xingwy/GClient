#ifndef MI_H
#define MI_H

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <iostream>

using namespace std;
class mi : public QWidget
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
