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

    bool sendData();

private slots:
    void onConnected();
    void onDisconnected();
    void onMessage();
//    void disconnect();
    void error(QAbstractSocket::SocketError socketError);


private:
    QStringList m_oData;
    QWebSocket* g_webSocket;

    QVariantList setFixedData(QByteArray data);
    QByteArray buildFixedData(qint32 from, qint32 opcode, qint8 flag, QByteArray content);
};

#endif // GTCP_H
