#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>

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
    QTimer *gTimer;


};
#endif // GAME_H
