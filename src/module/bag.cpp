#include "bag.h"
typedef std::function<void(QVariant)> Fun;
void test1(Bag bag) {
}

Bag::Bag(Agent *agent): ModuleBase(agent)
{
    this->_size = 0;
    this->_gridPool = new QMap<int, Item>();
    this->_itemHash = new QMap<int, QVector<int>>();
//    Register(1, std::bind(&Bag::test, this, std::placeholders::_1));
}

void Bag::init()
{

}





