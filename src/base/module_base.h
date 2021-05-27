#ifndef MODULEBASE_H
#define MODULEBASE_H

class Agent;

class ModuleBase
{
public:
    ModuleBase(Agent *parent = nullptr);
    ~ModuleBase();

    Agent* getAgent();

protected:
    Agent* _agent;
};

#endif // MODULEBASE_H
