#include "gtcp.h"

#include <QByteArray>
#include <QBuffer>
#include <QDataStream>
#include "msgpack.h"
#include <iobuffer.h>
using namespace IOBuffer;

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
    qint32 size = 1;
    qint32 offset = 2;
    qint8 flag = 3;
    list << size << offset << flag;
    QByteArray arr = MsgPack::pack(list);
    QByteArray pack = this->buildFixedData(101, 103210, flag, arr);
    this->g_webSocket->sendBinaryMessage(pack);
    return true;
}

void GTcp::onMessage() {
    qDebug()<<"---sendData";
    // 收到消息后 转换格式后调用指定方法

}

QVariantList GTcp::setFixedData(QByteArray content) {
    QVariantList list;
//    qDebug()<<content;

//    qDebug()<<content.size();

//    qint32 size;
//    qint32 offset;
//    qint8 flag;
//    memcpy(&size, &content.data()[0], 4);
//    memcpy(&offset, &content.data()[4], 4);
//    memcpy(&flag, &content.data()[3], 1);



//    offset += 4;
//    if (size !== content.length) {
//        // 校验数据长度
//        console.log("消息长度不足");
//        throw(new Error("消息长度不足"));
//    }
//    let opcode = content.readUInt32LE(offset);
//    offset += 4;
//    let flag = content.readUInt8(offset);
//    offset += 1;
//    let tuple = content.slice(offset);
    return list;
}

QByteArray GTcp::buildFixedData(qint32 from, qint32 opcode, qint8 flag, QByteArray content) {

    QByteArray pack;
    qint32 len = PACKAGE_HEAD_LEN + content.size();
    qDebug()<< "to hex init:"<<pack.toHex();
    int offset = 0;
    pack.insert(offset, qint32ToByte(len));
    offset += 4;
    pack.insert(offset, qint32ToByte(from));
    offset += 4;
    pack.insert(offset, qint32ToByte(opcode));
    offset += 4;
    pack.insert(offset, qint8ToByte(flag));
    offset += 1;
    pack.insert(offset, content);
    qDebug()<< "hex size:"<<pack.toHex();
    return pack;

}


