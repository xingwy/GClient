#ifndef GTCP_H
#define GTCP_H

#include <QIODevice>
#include <QWebSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>


#include "net.h"
#include "constant.h"
#include "iobuffer.h"

class Game;

class GTcp: public Net
{
public:
    GTcp(Game *g, QString host, quint16 port);

    bool sendMessage(quint32 from, quint32 opcode, quint8 flag, QVariantList list);
    bool clientConnect(QString user, QString password);

private slots:
    void onConnected();
    void onDisconnected();
    void onMessage(QByteArray msg);
    void onClosed();
    void onError(QAbstractSocket::SocketError error);

private:
    QStringList m_oData;
    QWebSocket* g_webSocket;

    // Methods
    QVariantList buildFixedData(QByteArray data);
    QByteArray setFixedData(qint32 from, qint32 opcode, qint8 flag, QByteArray content);

    Game *_game;
};

#endif // GTCP_H
