#include <QApplication>

#include "game.h"
#include "guiview.h"
#include "tcpserver.h"
#include "math.h"

#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    GuiView mainWindow(game);
    mainWindow.show();

    return a.exec();
}
