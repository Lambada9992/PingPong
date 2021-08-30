#include <QApplication>

#include "game.h"
#include "guiview.h"
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    GuiView mainWindow(game);
    mainWindow.show();

    TcpServer server;
    server.startServer(1234);

    return a.exec();
    //test2
}
