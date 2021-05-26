#include "game.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QDebug>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w;

    w.show();
    return a.exec();
}
