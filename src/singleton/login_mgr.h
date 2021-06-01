#ifndef LOGIN_MGR_H
#define LOGIN_MGR_H

#include <gtcp.h>

#include <agent.h>
#include <constant.h>

class LoginMgr
{
public:
    LoginMgr();

    GTcp static *authLogin(QString account, QString password);
};

#endif // LOGIN_MGR_H
