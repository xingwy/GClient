#include "module_base.h"

ModuleBase::ModuleBase(QWidget *parent, Agent *agent): QUi(parent)
{
    _agent = agent;
}

ModuleBase::~ModuleBase()
{
    // 是否需要释放
}

Agent* ModuleBase::getAgent()
{
    return _agent;
}
