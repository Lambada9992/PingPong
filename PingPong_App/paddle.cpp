#include "paddle.h"

Paddle::Paddle(int x, int y, int w, int h)
{
    this->position.rx() = x;
    this->position.ry() = y;
    this->widht = w;
    this->height = h;
}

void Paddle::move(int direction)
{
    /*y 1
        0
        2
      0 - obecna pozycja*/

    switch(direction){
    case 0:
        break;
    case 1: this->position.ry()++;
        break;
    case 2: this->position.ry()--;
        break;
    }
}
