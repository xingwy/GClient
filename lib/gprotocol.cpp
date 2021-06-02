#include "gprotocol.h"

GProtocol::GProtocol(Game *g)
{
    this->_game = g;
    this->_protocols = new QMap<quint32, void(*)(QVariant)>();
}

GProtocol::~GProtocol()
{

}

void GProtocol::registerProtocol(quint32 opcode, void(*p)(QVariant))
{
    if (this->_protocols->contains(opcode)) {
        // LOG <opcode exist>
        return;
    }
    this->_protocols->insert(opcode, p);
}

void(*GProtocol::getProtocolFunc(quint32 opcode))(QVariant)
{
    return this->_protocols->value(opcode);
}
