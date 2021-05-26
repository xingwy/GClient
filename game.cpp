#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    gTimer = new QTimer(this);
}

Game::~Game()
{
    delete ui;
    delete gTimer;
}

void Game::run() {
//    connect(gTimer, &QTimer::timeout, [=](){
//        this->flush();
//    });

    cout<<"start run"<<endl;
    connect(gTimer, SIGNAL(timeout()), this, SLOT(update()));
    gTimer->setInterval(40);
    gTimer->start();

}
void Game::update() {
    // 获取所有数据刷新显示盘
    cout<<"flush"<<endl;
}
