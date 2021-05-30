QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/qui.cpp \
    main.cpp \
    game.cpp \
    mi.cpp \
    src/agent.cpp \
    src/base/item.cpp \
    src/base/module_base.cpp \
    src/base/ucbase.cpp \
    src/module/bag.cpp \
    src/singleton/login.cpp \
    src/uc/uclogin.cpp

HEADERS += \
    define/constant.h \
    game.h \
    lib/qui.h \
    mi.h \
    src/agent.h \
    src/base/item.h \
    src/base/module_base.h \
    src/base/ucbase.h \
    src/module/bag.h \
    src/singleton/login.h \
    src/uc/uclogin.h

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

INCLUDEPATH += \
    $$PWD/src/ \
    $$PWD/src/uc \
    $$PWD/define \
    $$PWD/src/base \
    $$PWD/src/module \
    $$PWD/src/singleton \
    $$PWD/src/uc \
    $$PWD/lib
