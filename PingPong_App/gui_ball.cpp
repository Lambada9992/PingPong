#include "gui_ball.h"

Gui_ball::Gui_ball(Ball &ball) : ball(&ball)
{


    this->setX(ball.getPosition().rx());
    this->setY(ball.getPosition().ry());
    this->setRect(ball.getPosition().rx(),ball.getPosition().ry(),20,20);

}

void Gui_ball::updatePosition()
{
    this->setX(ball->getPosition().rx());
    this->setY(ball->getPosition().ry());
}
