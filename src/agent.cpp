#include "agent.h"


#include <iostream>

Agent::Agent(Game *g)
{
    this->_game = g;
    bag = new Bag(g->centralWidget(), this);
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

