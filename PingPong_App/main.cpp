#include <QApplication>

#include "game.h"
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    TcpServer server;
    server.startServer(1234);
    server.close();

    return a.exec();
}
