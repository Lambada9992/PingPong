#ifndef GUI_PADDLE_H
#define GUI_PADDLE_H

#include "model/paddle.h"
#include <QGraphicsItem>


class Gui_Paddle:public QGraphicsPixmapItem
{
public:
    Gui_Paddle(Paddle *paddle, QGraphicsItem *parent = nullptr);
    void updatePosition();
private:
    Paddle *paddle;
};

#endif // GUI_PADDLE_H
