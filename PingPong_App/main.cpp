#include <QApplication>

#include "game.h"
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    return a.exec();
    //test2
}
