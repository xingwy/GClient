#include "agent.h"


#include <iostream>

Agent::Agent(QWidget *parent)
{
    bag = new Bag(parent, this);
    authState = USER_NOTAUTH;
}

Agent::~Agent()
{

}
Bag* Agent::getBag() {
    return bag;
}

void Agent::update() {
}

