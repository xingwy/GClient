#include "login_mgr.h"

LoginMgr::LoginMgr()
{

}

void *LoginMgr::authLogin(GTcp* gtcp, QString account, QString password)
{
    //
    qDebug()<<"----auth login"<<account<<"."<<password;
    gtcp->clientConnect(account, password);
}

