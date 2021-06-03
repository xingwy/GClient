#include "module_base.h"

ModuleBase::ModuleBase(Agent *agent)
{
    this->_agent = agent;
}

ModuleBase::~ModuleBase()
{
    // 是否需要释放
}

Agent* ModuleBase::agent()
{
    return _agent;
}

void ModuleBase::_register(qint32 opcode, QKeyFunc handler)
{
    return this->agent()->game()->gprotocol()->registerProtocol(opcode, handler);
}
