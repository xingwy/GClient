#include "agent.h"
#include "bag.h"

Agent::Agent(Game *g)
{
    this->_game = g;
    bag = new Bag(this);
    authState = USER_NOTAUTH;
}

Agent::~Agent()
{

}

Game* Agent::game()
{
    return this->_game;
}

Bag* Agent::getBag()
{
    return bag;
}

void Agent::update()
{
    this->bag->init();
}

