#ifndef GUI_BALL_H
#define GUI_BALL_H

#include <QGraphicsEllipseItem>
#include "model/ball.h"


class Gui_ball : public QGraphicsPixmapItem
{
public:
    Gui_ball(Ball *ball,QPointF translation,QGraphicsItem *parent = nullptr);
    void updatePosition();

private:
    Ball *ball;
    QPointF translationFromGlobal;

};

#endif // GUI_BALL_H
