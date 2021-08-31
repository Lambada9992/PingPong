#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include "game.h"
#include <qgraphicsscene.h>


class Gui_board : public QGraphicsScene
{
public:
    Gui_board(Game *game);
private:
    Game *game;
};

#endif // GUI_BOARD_H
