#include "login_mgr.h"

LoginMgr::LoginMgr() {

}

bool LoginMgr::authLogin(Agent *agent) {
    //
    qDebug()<<"----auth login";

    GTcp *tcp = new GTcp(HOST, PORT);

    return true;
}

