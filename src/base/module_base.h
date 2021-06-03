#ifndef MODULEBASE_H
#define MODULEBASE_H

#include "qui.h"
#include "agent.h"

class Agent;

class ModuleBase
{
public:
    ModuleBase(Agent *agent);
    ~ModuleBase();
    Agent* agent();
    void init();
protected:

    void _register(qint32 opcode, QKeyFunc handler);
private:
    Agent* _agent;
};

#endif // MODULEBASE_H
