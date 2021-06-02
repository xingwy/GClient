#ifndef GPROTOCOL_H
#define GPROTOCOL_H

#include <QMap>

#include "game.h"
#include "protocol.h"

class Game;

class GProtocol
{
public:
    GProtocol(Game *g);
    ~GProtocol();

    // 注册协议
    void registerProtocol(quint32 opcode, long func);
    long getProtocolFunc(quint32 opcode);


// Values
private:
    Game *_game;
    QMap<quint32, long> *_protocols;
};

#endif // GPROTOCOL_H
