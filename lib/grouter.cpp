#include "grouter.h"

GRouter::GRouter(Game *g) {
    this->_game = g;
    this->_handlers = new QMap<quint32, long>();
}
