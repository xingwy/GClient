#include "game.h"
#include "ui_game.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    // 设置面板

    this->resize(GAME_BG_WIDTH, GAME_BG_HEIGHT);
    this->setMinimumSize(GAME_BG_WIDTH, GAME_BG_HEIGHT);
    this->setMaximumSize(GAME_BG_WIDTH, GAME_BG_HEIGHT);

    g_timer = new QTimer(this);

    // TCP连接
    this->_gtcp = new GTcp(this, GAMEHOST, GAMEPORT);
    // 路由器
    this->_grouter = new GRouter(this);
    // 协议管理器
    this->_gprotocol = new GProtocol(this);
    // 角色数据  角色数据最后加载
    this->_agent = new Agent(this);

}

Game::~Game()
{
    g_timer->stop();
    delete ui;
    delete g_timer;
}

GTcp* Game::gtcp()
{
    return this->_gtcp;
}
Agent* Game::agent()
{
    return this->_agent;
}
GRouter* Game::grouter()
{
    return this->_grouter;
}
GProtocol* Game::gprotocol()
{
    return this->_gprotocol;
}

void Game::run()
{

}
void Game::update() {
    // 代理人定时器
    this->_agent->update();
}

void Game::userSend()
{

}

// slot函数
void Game::connectServer()
{
    // 关闭Login
}

void Game::on_uc_login_btn_clicked(bool checked)
{
    ui->uc_login->close();
    ui->uc_hall->update();
    qDebug()<<"on_uc_login_btn_clicked";
//    QString account = ui->uc_login_user->text();
//    QString password = ui->uc_login_password->text();
//    LoginMgr::authLogin(this->gtcp(), account, password);
}


void Game::on_uc_register_btn_clicked(bool checked)
{
    QVariantList ms;
    this->_gtcp->sendMessage(1000, 123123, 12, ms);
}




