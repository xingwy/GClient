#ifndef NET_H
#define NET_H

#include <QObject>
#include <QIODevice>
#include <QWebSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QAbstractSocket>

#include <iostream>

using namespace std;

class Game;

class Net: public QObject
{
public:
    Net(QString host, quint16 port);
protected:
    QString host;
    qint16 port;
};

#endif // NET_H
