#ifndef GTCP_H
#define GTCP_H

#include <QIODevice>
#include <QWebSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>


#include <net.h>
#include <constant.h>

class GTcp: public Net
{
public:
    GTcp(QString host, quint16 port);

private slots:
    void onConnected();
    void onDisconnected();
//    void disconnect();
    void error(QAbstractSocket::SocketError socketError);

private:
    QStringList m_oData;
    QWebSocket* g_webSocket;
};

#endif // GTCP_H
