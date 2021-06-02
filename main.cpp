#include "game.h"

#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QLocale>
#include <QTranslator>
#include <QMainWindow>
#include <QApplication>

#include <iostream>
#include <constant.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w;

    w.show();
    w.run();

    return a.exec();
}
