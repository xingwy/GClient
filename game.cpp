#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    // 设置面板

    g_timer = new QTimer(this);
    agent = new Agent(this->ui->centralwidget);

    // 初始化登录widget
    uc_login = new UCLogin(this->ui->centralwidget);
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

