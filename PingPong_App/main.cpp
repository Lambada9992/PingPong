#include <QApplication>

#include "game.h"
#include "guiview.h"
#include "tcpserver.h"
#include "math.h"

#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Game game;

//    GuiView mainWindow(game);
//    mainWindow.show();

//    TcpServer server;
//    server.startServer(1234);

    QRect t(0,800,800,800);

    qDebug() << cos(M_PI * 4 );

    return a.exec();
    //test2
}
