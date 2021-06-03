#ifndef GROUTER_H
#define GROUTER_H

#include <QQueue>
#include <functional>

#include "game.h"

class Game;

class Message {
public:
    Message(quint32 from, quint32 opcode, quint8 flag, QVariant tuple):
        _from(from), _opcode(opcode), _flag(flag), _tuple(tuple){};
    quint32 _from;
    quint32 _opcode;
    quint8 _flag;
    QVariant _tuple;
};

class GRouter
{
public:
    GRouter(Game *g);
    void pushMessage(quint32 from, quint32 opcode, quint8 flag, QVariant tuple);
    void forward(quint32 from, quint32 opcode, quint8 flag, QVariant tuple);

private:
    Game *_game;
    QMap<quint32, void(*)(QVariant)> *_handlers;

    QQueue<Message>* _syncConsumes;
    QQueue<Message>* _asyncConsumes;
};

#endif // GROUTER_H
