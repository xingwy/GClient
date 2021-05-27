#include "module_base.h"

ModuleBase::ModuleBase(Agent *parent) {
    _agent = parent;
}

ModuleBase::~ModuleBase() {
    // 是否需要释放
}

Agent* ModuleBase::getAgent() {
    return _agent;
}
