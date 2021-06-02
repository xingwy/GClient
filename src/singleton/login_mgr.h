#ifndef LOGIN_MGR_H
#define LOGIN_MGR_H

#include <gtcp.h>
#include "game.h"
#include <agent.h>
#include <constant.h>

class GTcp;
class Game;

class LoginMgr
{
public:
    LoginMgr();

    GTcp static *authLogin(Game *p, QString account, QString password);
};

#endif // LOGIN_MGR_H
