#ifndef LOGIN_MGR_H
#define LOGIN_MGR_H

#include <gtcp.h>

#include <agent.h>
#include <constant.h>

class LoginMgr
{
public:
    LoginMgr();

    bool static authLogin(Agent *agent);
};

#endif // LOGIN_MGR_H
