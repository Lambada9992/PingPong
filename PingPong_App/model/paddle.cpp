#include "paddle.h"

Paddle::Paddle(Game *game)
{
    this->game = game;
}

void Paddle::move()
{

}

QPointF Paddle::getPosition() const
{
    return position;
}

void Paddle::setPosition(const QPoint &value)
{
    position = value;
}
