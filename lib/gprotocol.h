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
    void registerProtocol(quint32 opcode, QKeyFunc);
    QKeyFunc getProtocolFunc(quint32 opcode);
//    int (*Test ()) (int, int)


// Values
private:
    Game *_game;
    QMap<quint32, QKeyFunc> *_protocols;
};

#endif // GPROTOCOL_H
