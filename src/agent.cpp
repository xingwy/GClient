#include "agent.h"
#include <QTimer>
#include <QImage>
#include <iostream>

Agent::Agent()
{
    bag = new Bag(this);
}

Agent::~Agent()
{

}
Bag* Agent::getBag() {
    return bag;
}
