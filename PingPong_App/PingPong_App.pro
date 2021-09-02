QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/gamescene.cpp \
    gui/gui_ball.cpp \
    gui/gui_board.cpp \
    gui/gui_paddle.cpp \
    gui/guiview.cpp \
    gui/mainmenuscene.cpp \
    gui/multiplayermenuscene.cpp \
    gui/settingsscene.cpp \
    main.cpp \
    model/ball.cpp \
    model/game.cpp \
    model/paddle.cpp \
    network/sockethandler.cpp \
    network/tcpserver.cpp

HEADERS += \
    gui/gamescene.h \
    gui/gui_ball.h \
    gui/gui_board.h \
    gui/gui_paddle.h \
    gui/guiview.h \
    gui/mainmenuscene.h \
    gui/multiplayermenuscene.h \
    gui/settingsscene.h \
    model/ball.h \
    model/game.h \
    model/paddle.h \
    network/sockethandler.h \
    network/tcpserver.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
