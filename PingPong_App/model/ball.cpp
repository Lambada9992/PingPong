#include "ball.h"
#include <math.h>
#include <QRect>
#include <model/game.h>
#include <QDebug>

Ball::Ball(Game *game)
{
    this->game = game;
    this->speed = 500; //how many pixels per sec
}

// TODO: Dodanie logiki w przypadku uderzenia w Paddle lub score punktu
void Ball::move(double dt)
{

    //    qDebug() << "dt" << dt;
    //    qDebug() << "speed" <<  speed;
    //    qDebug() << "distance" <<  speed * dt;

    if(dt <= 0) return;

    QPointF nextPossition = (this->position + (this->velocity*dt));
    double nX = nextPossition.rx();
    double nY = nextPossition.ry();

    if(nX>0 && nY>0 && nX<game->getBoard().width()-1 && nY<game->getBoard().height()-1){
        this->position = nextPossition;
    }else {
        double vdtLeft = 0;
        double hdtLeft = 0;
        QPointF vHitPoint;
        QPointF hHitPoint;

        //vertical hit point
        if(velocity.ry()>0){
            double mx = (this->game->getBoard().height()-1 - this->position.ry()) * (nX - this->position.rx())/(nY-this->position.ry());
            vHitPoint = QPointF(this->position.rx()+mx,this->game->getBoard().height()-1);
            vdtLeft = dt - (vHitPoint - this->position).manhattanLength()/speed;
        }else if(velocity.ry() != 0){
            double mx = this->position.ry() * (nX - this->position.rx())/(this->position.ry()-nY);
            vHitPoint = QPointF(this->position.rx()+mx,0);
            vdtLeft = dt - (vHitPoint - this->position).manhattanLength()/speed;
        }

        //horizontal hit point
        if(velocity.rx()>0){
            double my = (nY-position.ry()) *(game->getBoard().width()-1-position.rx()) /(nX-position.rx());
            hHitPoint = QPointF(game->getBoard().width()-1,this->position.ry()+my);
            hdtLeft = dt - (hHitPoint - position).manhattanLength()/speed;
        }else if (velocity.x() != 0){
            double my = (nY-position.ry())*this->position.rx()/(position.rx()-nX);// y mx/x
            hHitPoint = QPointF(0,this->position.ry()+my);
            hdtLeft = dt - (hHitPoint - position).manhattanLength()/speed;
        }

        //Decyzja gdzie uderzyło
        if(vdtLeft>hdtLeft){//uderzenie w pionie
            this->position = vHitPoint;
            this->velocity.setY(-this->velocity.ry());
            move(vdtLeft);
        }else{// uderzenie w poziomie
            Paddle *paddle = NULL;
            for(auto *_paddle : *this->game->getPadles()){
                if(_paddle->getPosition().x()==hHitPoint.x()){
                    paddle = _paddle;
                }
            }
            if(paddle != NULL){
                if(abs(paddle->getPosition().ry() - position.ry())<paddle->getSize()){
                    this->position = hHitPoint;
                    this->velocity.setX(-this->velocity.rx());
                    move(hdtLeft);
                }else{
                    //score point
                    this->position = this->game->getBoard().center();
                    this->randomVelocity(45);
                }
            }else{
                // score point
                this->position = this->game->getBoard().center();
                this->randomVelocity(45);
            }
        }
    }
}

QPointF Ball::getPosition() const
{
    return position;
}

void Ball::setPosition(const QPoint &value)
{
    position = value;
}


void Ball::randomVelocity(double angle)
{
    double randAngle =  -angle + ((double) rand() / (RAND_MAX))*(angle*2); //random angle from <-angle : +angle>
    qDebug() << randAngle;
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


