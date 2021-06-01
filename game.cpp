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
    agent = new Agent(this->ui->centralwidget);

    // 初始化登录widget
//    uc_login = new UCLogin(this->ui->centralwidget);
    qDebug()<< ui->uc_login_btn->parent()->objectName();

    ui->uc_login_btn->update();

}

Game::~Game()
{
    g_timer->stop();
    delete ui;
    delete g_timer;
}

void Game::run() {
    // 游戏定时器设置
    connect(g_timer, SIGNAL(timeout()), this, SLOT(update()));
    g_timer->setInterval(40);
    g_timer->start();

    // 设置窗体大小

}
void Game::update() {
    // 代理人定时器

    agent->update();
}

void Game::on_uc_login_btn_clicked(bool checked)
{
    USER_STATE state = this->agent->getAuthState();

//    if (state != USER_NOTAUTH) {
//        return;
//    }

    QString account = ui->uc_login_user->text();
    QString password = ui->uc_login_password->text();
    qDebug()<<account<<"--"<<password;
    this->_tcpSession = LoginMgr::authLogin(account, password);

}


void Game::on_uc_register_btn_clicked(bool checked)
{
    QVariantList ms;
    ms<<2;
    ms<<"2123";
    this->_tcpSession->sendMessage(1000, 123123, 12, ms);
}

void Game::userSend()
{
    QVariantList ms;
    ms<<2;
    ms<<"2123";
    this->_tcpSession->sendMessage(1000, 123123, 12, ms);
}


