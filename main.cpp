#include "game.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QDebug>
#include <iostream>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w;
    w.resize(960, 540);
    w.setMinimumSize(960, 540);
    w.setMaximumSize(960, 540);

    w.show();
    w.run();
    return a.exec();
}
