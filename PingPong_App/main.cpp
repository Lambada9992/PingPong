#include <QApplication>

#include "model/game.h"
#include "gui/guiview.h"
#include "math.h"

#include <QTime>

/**
 * @brief main
 * @author Marcin Bobinski, Marcin Korzeniowski
 * @date 06.09.2021r.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));

    Game game;

    GuiView mainWindow(game);
    mainWindow.show();

    return a.exec();
}
