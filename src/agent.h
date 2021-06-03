#ifndef AGENT_H
#define AGENT_H

// 代理人模块 所有角色相关模块
#include <QTimer>
#include <QImage>
#include <iostream>

#include "game.h"
#include "constant.h"

class Bag;
class Game;

class Agent
{
public:
    Agent(Game *g = nullptr);
    ~Agent();

    Bag* getBag();
    void update();

    USER_STATE getAuthState() {
        return this->authState;
    }

    void setAuthState(USER_STATE state) {
        this->authState = state;
    }

    Game* game();
private:
    QString account;
    QString name;

    unsigned int level;
    // 登录状态 是否经过验证
    USER_STATE authState;
    Bag *bag;

    Game *_game;

};

#endif // AGENT_H
