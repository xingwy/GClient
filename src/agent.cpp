#include "agent.h"
#include <QTimer>
#include <QImage>
#include <iostream>

Agent::Agent(QWidget *parent)
{
    bag = new Bag(parent, this);
}

Agent::~Agent()
{

}
Bag* Agent::getBag() {
    return bag;
}
