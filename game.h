#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include <iostream>

#include "./src/agent.h"
#include "./src/base/ucbase.h"
#include "./src/uc/uclogin.h"

using namespace std;

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

public slots:
    void update();

private:
    Ui::Game *ui;
    QTimer *g_timer;
    QImage *m_img;

    Agent *agent;

    UCLogin *uc_login;

};
#endif // GAME_H
