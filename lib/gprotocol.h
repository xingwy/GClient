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
    void registerProtocol(quint32 opcode, void(*p)(QVariant));
    void(*getProtocolFunc(quint32 opcode)) (QVariant);
//    int (*Test ()) (int, int)


// Values
private:
    Game *_game;
    QMap<quint32, void(*)(QVariant)> *_protocols;
};

#endif // GPROTOCOL_H
