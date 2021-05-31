#include "gtcp.h"

#include <QByteArray>
#include "msgpack.h"

GTcp::GTcp(QString host, quint16 port): Net(host, port) {
    g_webSocket = new QWebSocket();
//    connect(g_tcpSocket, &QTcpSocket::errorOccurred, this, &GTcp::error);
    connect(g_webSocket, &QWebSocket::connected, this, &GTcp::onConnected);
    connect(g_webSocket, &QWebSocket::disconnected, this, &GTcp::onDisconnected);
    qDebug()<<"---connect"<<this->host<<":"<<this->port;
    QUrl *url = new QUrl("ws://127.0.0.1:10001/?account=xingwy&password=123456");
    qDebug()<<url->query();
    g_webSocket->open(*url);
//    g_webSocket->open(QUrl("ws://localhost:8080"));

//    qDebug()<<g_tcpSocket->isOpen();
    qDebug()<<g_webSocket->isValid();

}

void GTcp::onConnected() {
    qDebug()<<"---connected";
    this->sendData();
}

void GTcp::onDisconnected() {
    qDebug()<<"---onDisconnected";
}

void GTcp::error(QAbstractSocket::SocketError socketError) {
    qDebug()<<"---error";
}

bool GTcp::sendData() {
    qDebug()<<"---sendData";
//    this->g_webSocket->sendTextMessage("aaaaab");

    QVariantList list;
    list << 1 << "hello" << 3;
    QByteArray arr = MsgPack::pack(list);

    for (int i=0; i<arr.size(); i++) {
        qDebug()<<arr[i];
    }
    this->g_webSocket->sendBinaryMessage(arr);
    qDebug()<<arr;
    return true;
}

void GTcp::onMessage() {
    qDebug()<<"---sendData";
    // 收到消息后 转换格式后调用指定方法

}


