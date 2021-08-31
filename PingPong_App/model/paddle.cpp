#include "paddle.h"

double Paddle::getSize() const
{
    return size;
}

Paddle::Paddle(Game *game, QPointF position, double size)
{
    this->game = game;
    this->position = position;
    this->size = size;
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
