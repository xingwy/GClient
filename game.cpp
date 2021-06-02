#include "game.h"
#include "ui_game.h"

void func1(QVariantList list) {
    qDebug()<<"func1";
}

void func2(QVariantList list) {
    qDebug()<<"func2";
}

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

    // 角色数据
    this->_agent = new Agent(this);
    // TCP连接
    this->_gtcp = new GTcp(this, GAMEHOST, GAMEPORT);
    // 路由器
    this->_grouter = new GRouter(this);
    // 协议管理器
    this->_gprotocol = new GProtocol(this);

    //test
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
    // 游戏定时器设置
    connect(g_timer, SIGNAL(timeout()), this, SLOT(update()));
    g_timer->setInterval(40);
    g_timer->start();

    // 设置窗体大小

}
void Game::update() {
    // 代理人定时器

    this->_agent->update();
}

void Game::userSend()
{
    QVariantList ms;
    ms<<2;
    ms<<"2123";
    qDebug()<<ms;
//    this->_gtcp->sendMessage(1000, 123123, 12, ms);
}

// slot函数
void Game::connectServer()
{
    qDebug()<<"game connect";
    // 关闭Login
    ui->uc_login->close();
}

void Game::on_uc_login_btn_clicked(bool checked)
{
    qDebug()<<"on_uc_register_btn_clicked-"<<checked;
    QString account = ui->uc_login_user->text();
    QString password = ui->uc_login_password->text();
    qDebug()<<account<<"--"<<password;
    LoginMgr::authLogin(this->gtcp(), account, password);

}


void Game::on_uc_register_btn_clicked(bool checked)
{
    qDebug()<<"on_uc_register_btn_clicked-"<<checked;
    QVariantList ms;
    this->_gtcp->sendMessage(1000, 123123, 12, ms);
}




