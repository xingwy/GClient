#include "gprotocol.h"

GProtocol::GProtocol(Game *g)
{
    this->_game = g;
    this->_protocols = new QMap<quint32, QKeyFunc>();
}

GProtocol::~GProtocol()
{

}

void GProtocol::registerProtocol(quint32 opcode, QKeyFunc handler)
{
    if (this->_protocols->contains(opcode)) {
        // LOG <opcode exist>
        return;
    }
    this->_protocols->insert(opcode, handler);
}

QKeyFunc GProtocol::getProtocolFunc(quint32 opcode)
{
    return this->_protocols->value(opcode);
}
