#include "gprotocol.h"

GProtocol::GProtocol(Game *g)
{
    this->_game = g;
    this->_protocols = new QMap<quint32, long>();
}

GProtocol::~GProtocol()
{

}

void GProtocol::registerProtocol(quint32 opcode, long func)
{
    if (this->_protocols->contains(opcode)) {
        // LOG <opcode exist>
        return;
    }
    this->_protocols->insert(opcode, func);
}

long GProtocol::getProtocolFunc(quint32 opcode)
{
    return this->_protocols->value(opcode);
}
