#ifndef NET_H
#define NET_H

#include <QObject>
#include <QtNetwork/QHostAddress>

#include <iostream>

using namespace std;

class Net: public QObject
{
public:
    Net(QString host, quint16 port);
protected:
    QString host;
    qint16 port;
};

#endif // NET_H
