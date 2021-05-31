QT       += core gui network websockets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMSGPACK_PATH = $$PWD/res-lib/qmsgpack

SOURCES += \
    $$QMSGPACK_PATH/src/msgpack.cpp \
    $$QMSGPACK_PATH/src/msgpackcommon.cpp \
    $$QMSGPACK_PATH/src/private/pack_p.cpp \
    $$QMSGPACK_PATH/src/private/unpack_p.cpp \
    $$QMSGPACK_PATH/src/stream/time.cpp \
    $$QMSGPACK_PATH/src/private/qt_types_p.cpp \
    $$QMSGPACK_PATH/src/msgpackstream.cpp \
    lib/gtcp.cpp \
    lib/net.cpp \
    lib/qui.cpp \
    main.cpp \
    game.cpp \
    mi.cpp \
    src/agent.cpp \
    src/base/item.cpp \
    src/base/module_base.cpp \
    src/base/ucbase.cpp \
    src/module/bag.cpp \
    src/singleton/login_mgr.cpp \
    src/uc/uclogin.cpp \
    utils/formatdata.cpp


HEADERS += \
    define/constant.h \
    $$QMSGPACK_PATH/src/msgpack.h \
    $$QMSGPACK_PATH/src/private/pack_p.h \
    $$QMSGPACK_PATH/src/private/unpack_p.h \
    $$QMSGPACK_PATH/src/private/qt_types_p.h \
    $$QMSGPACK_PATH/src/endianhelper.h \
    $$QMSGPACK_PATH/src/msgpackcommon.h \
    $$QMSGPACK_PATH/src/msgpack_export.h \
    $$QMSGPACK_PATH/src/msgpackstream.h \
    game.h \
    lib/gtcp.h \
    lib/net.h \
    lib/qui.h \
    mi.h \
    src/agent.h \
    src/base/item.h \
    src/base/module_base.h \
    src/base/ucbase.h \
    src/module/bag.h \
    src/singleton/login_mgr.h \
    src/uc/uclogin.h \
    utils/formatdata.h



FORMS += \
    game.ui

TRANSLATIONS += \

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/img.qrc

DISTFILES +=

DEFINES += MSGPACK_MAKE_LIB

INCLUDEPATH += \
    $$PWD/src/ \
    $$PWD/src/uc \
    $$PWD/define \
    $$PWD/src/base \
    $$PWD/src/module \
    $$PWD/src/singleton \
    $$PWD/src/uc \
    $$PWD/lib \
    $$PWD/utils \
    $$QMSGPACK_PATH/src \
