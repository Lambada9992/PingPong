#ifndef GUI_BOARD_H
#define GUI_BOARD_H

class Gui_Paddle;
#include "MODEL/game.h"
#include "gui_ball.h"
#include <qgraphicsscene.h>
#include "QDebug"

class Gui_board :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Gui_board(Game *game,QObject *object = nullptr,QGraphicsItem *parent = nullptr);

private:
    Game *game;
    Gui_ball *gui_ball;
    QList<Gui_Paddle *> gui_padles;

public slots:
    void update();
};

#endif // GUI_BOARD_H
