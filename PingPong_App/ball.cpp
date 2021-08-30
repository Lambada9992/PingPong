#include "ball.h"

Ball::Ball(int x, int y, int w, int h)
{
    this->position.rx() = x;
    this->position.ry() = y;
    this->widht = w;
    this->height = h;
}

void Ball::move(int direction)
{
    /*y 1   2
          0
        3   4 x
      5 - obecna pozycja*/

    switch(direction){
    case 0:
        break;
    case 1: this->position.rx()--; this->position.ry()++;
        break;
    case 2: this->position.rx()++; this->position.ry()++;
        break;
    case 3: this->position.rx()--; this->position.ry()--;
        break;
    case 4: this->position.rx()++; this->position.ry()--;
        break;

    }
}

int Ball::getPositionX(){return this->position.rx();}
int Ball::getPositionY(){return this->position.ry();}
