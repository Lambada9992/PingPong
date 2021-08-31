#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include "game.h"
#include "gui_ball.h"
#include <qgraphicsscene.h>
#include "QDebug"

class Gui_board : public QGraphicsScene
{
public:

    Gui_board(Game &game);

private:
    Game *game;
    Gui_ball *gui_ball;
public slots:
    void update();
};

#endif // GUI_BOARD_H
