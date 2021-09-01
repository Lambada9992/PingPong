#include "paddle.h"

Paddle::Paddle(Game *game, QPointF position, double size)
{
    this->game = game;
    this->position = position;
    this->size = size;
}

double Paddle::getSize() const
{
    return size;
}

void Paddle::move(int direction)
{
    if(direction == 0)
    {
        this->position.ry()++;
    }
    else if(direction == 1)
    {
        this->position.ry()--;
    }

}

QPointF Paddle::getPosition() const
{
    return position;
}

void Paddle::setPosition(const QPoint &value)
{
    position = value;
}
