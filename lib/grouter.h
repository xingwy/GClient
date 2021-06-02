#ifndef GROUTER_H
#define GROUTER_H

#include "game.h"

class Game;

class GRouter
{
public:
    GRouter(Game *g);

private:
    Game *_game;
    QMap<quint32, long> *_handlers;
};

#endif // GROUTER_H
