#include "login_mgr.h"

LoginMgr::LoginMgr()
{

}

GTcp *LoginMgr::authLogin(Game *p, QString account, QString password)
{
    //
    qDebug()<<"----auth login"<<account<<"."<<password;

    GTcp *tcp = new GTcp(p, GAMEHOST, GAMEPORT);
    tcp->clientConnect(account, password);
    return tcp;
}

