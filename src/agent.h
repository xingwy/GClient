#ifndef AGENT_H
#define AGENT_H

// 代理人模块 所有角色相关模块
#include <QTimer>
#include <QImage>
#include <iostream>

#include "./module/bag.h"

class Agent
{
public:
    Agent();
    ~Agent();

    Bag* getBag();
private:
    QString account;
    QString name;
    unsigned int level;

    Bag *bag;

};

#endif // AGENT_H
