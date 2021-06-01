#include "gtcp.h"

#include <QByteArray>
#include <QBuffer>
#include "msgpack.h"
#include <iobuffer.h>
using namespace IOBuffer;

GTcp::GTcp(QString host, quint16 port): Net(host, port) {

}

bool GTcp::clientConnect(QString account, QString password) {
    QUrl url(this->host + ":" + QString::number(this->port, 10) + "/?account=" + account + "&password=" + password);
    g_webSocket = new QWebSocket(url.toString());
    connect(g_webSocket, &QWebSocket::connected, this, &GTcp::onConnected);
    connect(g_webSocket, &QWebSocket::disconnected, this, &GTcp::onDisconnected);
    connect(g_webSocket, &QWebSocket::destroyed, this, &GTcp::onClosed);
//    connect(g_webSocket, &QWebSocket::sslErrors, this, &GTcp::onError);

    // 建立连接
    g_webSocket->open(url);
    return g_webSocket->isValid();
}

void GTcp::onConnected() {
    connect(g_webSocket, &QWebSocket::binaryMessageReceived,
                this, &GTcp::onMessage);
}

void GTcp::onDisconnected() {
    qDebug()<<"---onDisconnected";
}

void GTcp::onError(QAbstractSocket::SocketError error) {
    qDebug()<<"---error"<<error;
}

void GTcp::onClosed() {
    qDebug()<<"---error";
}

bool GTcp::sendMessage(quint32 from, quint32 opcode, quint8 flag, QVariantList list) {
    QByteArray content = MsgPack::pack(list);
    QByteArray pack = this->setFixedData(from, opcode, flag, content);
    this->g_webSocket->sendBinaryMessage(pack);
    this->buildFixedData(pack);
    return true;
}

void GTcp::onMessage(QByteArray msg) {
    qDebug()<<"---sendData";
    // 收到消息后 转换格式后调用指定方法
    QVariantList content = this->buildFixedData(msg);

    // 根据opcode 分发到不同模块
    QVariant from = content[0];
    QVariant opcode = content[1];
    QVariant flag = content[2];
    QVariant tuple = content[3];

}
// 分解包内容
QVariantList GTcp::buildFixedData(QByteArray data) {
    QVariantList content;
    quint32 offset = 0;
    // 先使用无缓冲模式
    qint32 size =  bytesToQint32(data.mid(offset, 4));
    offset += 4;
    if (data.size() < size) {
        // error
        return content;
    }
    // from
    content.append(bytesToQint32(data.mid(offset, 4)));
    offset += 4;
    // opcode
    content.append(bytesToQint32(data.mid(offset, 4)));
    offset += 4;
    // flag
    content.append(bytesToQint8(data.mid(offset, 1)));
    offset += 1;
    // tuple
    content.append(data.mid(offset));
    return content;
}

// 设置包内容
QByteArray GTcp::setFixedData(qint32 from, qint32 opcode, qint8 flag, QByteArray content) {

    QByteArray pack;
    qint32 len = PACKAGE_HEAD_LEN + content.size();
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


