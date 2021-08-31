#include "gui_ball.h"
#include <QDebug>

Gui_ball::Gui_ball(Ball *ball, QGraphicsItem *parent): QGraphicsEllipseItem(parent)
{
    this->ball = ball;
    this->setPos(this->ball->getPosition());
    this->setRect(ball->getPosition().rx(),ball->getPosition().ry(),10,10);

}

void Gui_ball::updatePosition()
{
    this->setPos(this->ball->getPosition());
}
