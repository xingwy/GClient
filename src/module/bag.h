#ifndef BAG_H
#define BAG_H

#include <qmap.h>

#include <QVector>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include <iostream>

#include "../base/item.h"
#include "../base/module_base.h"

using namespace std;


class Bag: public ModuleBase
{
public:
    Bag(QWidget *parent = nullptr, Agent *agent = nullptr);

    Item findItemById();

private:


    // 背包大小
    int _size;
    // 物品池 <格子ID, 道具>
    QMap<int, Item> *_gridPool;
    QMap<int, QVector<int>> *_itemHash;


};

#endif // BAG_H
