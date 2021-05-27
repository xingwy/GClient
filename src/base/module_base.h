#ifndef MODULEBASE_H
#define MODULEBASE_H

#include "../../lib/qui.h"

class Agent;


class ModuleBase: public QUi
{
public:
    ModuleBase(QWidget *parent = nullptr, Agent *agent = nullptr);
    ~ModuleBase();

    Agent* getAgent();

protected:
    Agent* _agent;
};

#endif // MODULEBASE_H
