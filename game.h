#ifndef GAME_H
#define GAME_H


#include <QTimer>
#include <QImage>
#include <iostream>
#include <QMainWindow>
#include <QAbstractButton>

#include <agent.h>
#include <ucbase.h>
#include <uclogin.h>
#include <constant.h>

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

private slots:

    void on_uc_login_btn_clicked(bool checked);

    void on_uc_register_btn_clicked(bool checked);

private:
    Ui::Game *ui;
    QTimer *g_timer;
    QImage *m_img;

    Agent *agent;

    UCLogin *uc_login;

};
#endif // GAME_H
