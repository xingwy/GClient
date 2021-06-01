#ifndef IOBUFFER_H
#define IOBUFFER_H
#include <QByteArray>

namespace IOBuffer {
    QByteArray qint8ToByte(qint8 i);
    QByteArray qint32ToByte(qint32 i);
    qint8 bytesToQint8(QByteArray bytes);
    qint32 bytesToQint32(QByteArray bytes);
}

#endif // IOBUFFER_H
