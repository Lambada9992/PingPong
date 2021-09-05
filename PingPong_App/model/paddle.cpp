#include "paddle.h"
#include "game.h"

Paddle::Direction Paddle::getDirection() const
{
    return direction;
}

void Paddle::setDirection(const Direction &value)
{
    direction = value;
}

void Paddle::setSize(double value)
{
    size = value;
}

double Paddle::getWidth() const
{
    return width;
}

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

void Paddle::move(double dt)
{
    if(direction == UP)
    {
        this->position.ry() = this->position.y() + (this->speed*dt);
        if(this->position.ry() + this->size > this->game->getBoard().height()-1){
            this->position.ry() = this->game->getBoard().height()-1 - size;
        }
    }
    else if(direction == DOWN)
    {
        this->position.ry() = this->position.y() - (this->speed*dt);
        if(this->position.y()-this->size < 0){
            this->position.ry() = size;
        }
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
