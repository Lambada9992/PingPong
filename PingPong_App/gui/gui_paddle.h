#ifndef GUI_PADDLE_H
#define GUI_PADDLE_H

#include "MODEL/game.h"
#include <QGraphicsItem>


class Gui_Paddle:public QGraphicsPixmapItem
{
public:
    Gui_Paddle(Paddle *paddle, QString color, QGraphicsItem *parent = nullptr);
    void updatePosition();
    void prepare();
private:
    Paddle *paddle;
    Game::Side side;
    QString color;
};

#endif // GUI_PADDLE_H
