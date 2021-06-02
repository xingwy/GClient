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
    this->_agent = new Agent(this);

    // 初始化登录widget

    // 路由器
    this->_grouter = new GRouter(this);

    // 协议管理器
    this->_protocol = new GProtocol(this);
}

Game::~Game()
{
    g_timer->stop();
    delete ui;
    delete g_timer;
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
    this->_gtcp->sendMessage(1000, 123123, 12, ms);
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
    this->_gtcp = LoginMgr::authLogin(this, account, password);

}


void Game::on_uc_register_btn_clicked(bool checked)
{
    qDebug()<<"on_uc_register_btn_clicked-"<<checked;
    QVariantList ms;
    this->_gtcp->sendMessage(1000, 123123, 12, ms);
}




