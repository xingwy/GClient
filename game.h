#ifndef GAME_H
#define GAME_H


#include <QTimer>
#include <QImage>
#include <iostream>
#include <QMainWindow>
#include <QAbstractButton>

#include "gtcp.h"
#include "agent.h"
#include "ucbase.h"
#include "uclogin.h"
#include "grouter.h"
#include "constant.h"
#include "login_mgr.h"
#include "gprotocol.h"


using namespace std;

class GTcp;
class Agent;
class GRouter;
class GProtocol;


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
    void run();
    // 连接到服务器
    void connectServer();
    // 注册模块
    void registerHandler();
    // 分发消息
    void distribute();

    // set/get
    GTcp* gtcp();
    Agent* agent();
    GRouter* grouter();
    GProtocol* gprotocol();

public slots:
    void update();
    void userSend();

private slots:
    void on_uc_login_btn_clicked(bool checked);
    void on_uc_register_btn_clicked(bool checked);


private:
    Ui::Game *ui;
    QTimer *g_timer;
    QImage *m_img;

    UCLogin *uc_login;

    GTcp *_gtcp;
    Agent *_agent;
    GRouter *_grouter;
    GProtocol *_gprotocol;

};
#endif // GAME_H
