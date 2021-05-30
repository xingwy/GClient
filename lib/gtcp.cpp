#include "gtcp.h"

GTcp::GTcp(QString host, quint16 port): Net(host, port) {
    g_webSocket = new QWebSocket();
//    connect(g_tcpSocket, &QTcpSocket::errorOccurred, this, &GTcp::error);
    connect(g_webSocket, &QWebSocket::connected, this, &GTcp::onConnected);
    connect(g_webSocket, &QWebSocket::disconnected, this, &GTcp::onDisconnected);
    qDebug()<<"---connect"<<this->host<<":"<<this->port;
    g_webSocket->open(QUrl("ws://127.0.0.1:10001?account=xingwy&password=123456"));
//    g_webSocket->open(QUrl("ws://localhost:8080"));

//    qDebug()<<g_tcpSocket->isOpen();
    QWebSocket::

}

void GTcp::onConnected() {
    qDebug()<<"---connected";
}

void GTcp::onDisconnected() {
    qDebug()<<"---onDisconnected";
}

void GTcp::error(QAbstractSocket::SocketError socketError) {
    qDebug()<<"---error";
}
