#include <QApplication>

#include "model/game.h"
#include "gui/guiview.h"
#include "math.h"

#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));

    Game game;

    GuiView mainWindow(game);
    mainWindow.show();

    return a.exec();
}
