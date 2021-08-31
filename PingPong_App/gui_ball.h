#ifndef GUI_BALL_H
#define GUI_BALL_H

#include <QGraphicsEllipseItem>
#include "ball.h"


class Gui_ball : public QGraphicsEllipseItem
{
public:
    Gui_ball(Ball &ball);
    void updatePosition();

private:
    Ball *ball;


};

#endif // GUI_BALL_H
