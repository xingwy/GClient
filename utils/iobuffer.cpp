#include "iobuffer.h"
#include <QDebug>

namespace IOBuffer {
    QByteArray qint32ToByte(qint32 i)
    {
        QByteArray types;
        types.resize(4);
        types[0] = (uchar) (0x000000ff & i);
        types[1] = (uchar) ((0x0000ff00 & i) >> 8);
        types[2] = (uchar) ((0x00ff0000 & i) >> 16);
        types[3] = (uchar) ((0xff000000 & i) >> 24);
        return types;
    }

    QByteArray qint8ToByte(qint8 i)
    {
        QByteArray types;
        types.resize(1);
        types[0] = (uchar) (0x000000ff & i);
        return types;
    }


    qint8 bytesToQint8(QByteArray bytes) {
        int addr = bytes[0] & 0x000000FF;
        return addr;
    }

    qint32 bytesToQint32(QByteArray bytes) {
        int addr = bytes[0] & 0x000000FF;
        addr |= ((bytes[1] << 8) & 0x0000FF00);
        addr |= ((bytes[2] << 16) & 0x00FF0000);
        addr |= ((bytes[3] << 24) & 0xFF000000);
        return addr;
    }
}
