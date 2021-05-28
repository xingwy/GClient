#include "qui.h"

QUi::QUi(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
}
