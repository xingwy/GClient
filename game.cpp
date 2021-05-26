#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    g_timer = new QTimer(this);
    m_img = new QImage("C:/Users/Administrator/Desktop/workspace/GClient/res/images/tank.jpg");

}

Game::~Game()
{
    delete ui;
    delete g_timer;
}

void Game::run() {
//    connect(gTimer, &QTimer::timeout, [=](){
//        this->flush();
//    });

    cout<<"start run"<<endl;
    connect(g_timer, SIGNAL(timeout()), this, SLOT(update()));
    g_timer->setInterval(40);
    g_timer->start();

}
void Game::update() {
    // 获取所有数据刷新显示盘
    this->ui->centralwidget->update();

}

