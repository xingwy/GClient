#include "bag.h"

Bag::Bag()
{
    this->_size = 0;
    this->_gridPool = new QMap<int, Item>();
    this->_itemHash = new QMap<int, QVector<int>>();
}
