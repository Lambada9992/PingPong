QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    game.cpp \
    gui_ball.cpp \
    gui_board.cpp \
    guiview.cpp \
    main.cpp \
    mainmenuscene.cpp \
    paddle.cpp \
    sockethandler.cpp \
    tcpserver.cpp

HEADERS += \
    ball.h \
    game.h \
    gui_ball.h \
    gui_board.h \
    guiview.h \
    mainmenuscene.h \
    paddle.h \
    sockethandler.h \
    tcpserver.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
