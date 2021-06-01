#include "login_mgr.h"

LoginMgr::LoginMgr() {

}

GTcp *LoginMgr::authLogin(QString account, QString password) {
    //
    qDebug()<<"----auth login"<<account<<"."<<password;

    GTcp *tcp = new GTcp(GAMEHOST, GAMEPORT);
    tcp->clientConnect(account, password);
    return tcp;
}

