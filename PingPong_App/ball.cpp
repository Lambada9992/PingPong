#include "ball.h"
#include <math.h>
#include <QRect>
#include <game.h>

Ball::Ball(Game *game)
{
    this->game = game;
}

// TODO: Dodanie logiki w przypadku uderzenia w Paddle lub score punktu
void Ball::move(double dt)
{
    if(dt <= 0) return;
    QPoint nextPossition = this->position * (this->speed*dt);
    if(this->game->getBoard().contains(nextPossition)){// no hit
        this->position = nextPossition;
    }else {
        if(abs(this->velocity.ry()) > abs(this->velocity.rx())){// wall hit
            double dtLeft;
            QPoint hitPoint;
            if(this->velocity.ry()>0){// upper wall hit
                int mx = (this->game->getBoard().height() - this->position.ry()) * (nextPossition.rx() - this->position.rx())/(nextPossition.ry()-this->position.ry());
                hitPoint = QPoint(this->position.rx()+mx,this->game->getBoard().height());
                dtLeft = dt - (hitPoint - this->position).manhattanLength()/((double)speed);
            }else{//down wall hit
                int mx = this->position.ry() * (nextPossition.rx() - this->position.rx())/(this->position.ry()-nextPossition.ry());
                hitPoint = QPoint(this->position.rx()+mx,0);
                dtLeft = dt - (hitPoint - this->position).manhattanLength()/((double)speed);
            }
            this->position = hitPoint;
            this->velocity.setY(-this->velocity.ry());
            move(dtLeft);
        }else{ //hit padle or score point

            if(this->velocity.rx()>0){// prawo
                Paddle paddle = *this->findPaddle(this->game->getBoard().width());
            }else{// lewo
                Paddle paddle = *this->findPaddle(0);
            }
        }

    }

}

QPoint Ball::getPosition() const
{
    return position;
}

void Ball::setPosition(const QPoint &value)
{
    position = value;
}


void Ball::randomVelocity(double angle)
{
    srand(NULL);
    double randAngle =  -angle + ((double) rand() / (RAND_MAX))*(angle*2); //random angle from <-angle : +angle>
    int direction = ((rand()%2)*2)-1; // random 1 or -1

    double xv = speed * cos(randAngle*M_PI/180) * direction;
    double yv = speed * sin(randAngle*M_PI/180) * direction;

    velocity.setX(xv);
    velocity.setY(yv);
}

double Ball::getAngle()
{
    return atan(((double)this->velocity.ry())/((double)this->velocity.rx()));
}

Paddle *Ball::findPaddle(int possitionX)
{
    QList<Paddle *> paddles = *this->game->getPadles();
    for(int i=0; i< paddles.size(); i++){
        if(paddles[i]->getPosition().rx() == possitionX){
            return paddles[i];
        }
    }
    throw std::invalid_argument("Invalid paddle position.");
}


