#include "gui_ball.h"

Gui_ball::Gui_ball(Ball *ball)
{
    this->ball = ball;
    this->setX(ball->getPosition().rx());
    this->setY(ball->getPosition().ry());
}

void Gui_ball::updatePosition()
{
    this->setX(ball->getPosition().rx());
    this->setY(ball->getPosition().ry());
}
