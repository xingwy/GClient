#include "grouter.h"

GRouter::GRouter(Game *g) {
    this->_game = g;
    this->_handlers = new QMap<quint32, void(*)(QVariant)>();

    this->_asyncConsumes = new QQueue<Message>();
}

void GRouter::pushMessage(quint32 from, quint32 opcode, quint8 flag, QVariant tuple)
{
    this->_asyncConsumes->append(Message(from, opcode, flag, tuple));
}

void GRouter::forward(quint32 from, quint32 opcode, quint8 flag, QVariant tuple)
{
    // 执行
    void(*handler)(QVariant) = this->_game->gprotocol()->getProtocolFunc(opcode);
    if (!handler) {
        return;
    }
    handler(tuple);
}
