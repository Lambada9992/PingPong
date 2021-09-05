#include "ball.h"
#include <QtMath>
#include <QRect>
#include "model/game.h"
#include <QDebug>

int Ball::getSize() const
{
    return size;
}

Paddle *Ball::getParent() const
{
    return parent;
}

void Ball::setParent(Paddle *value)
{
    parent = value;
}

Ball::Ball(Game *game)
{
    this->game = game;
    this->speed = 100; //how many pixels per sec
    this->parent = NULL;
}

// TODO: Dodanie logiki w przypadku uderzenia w Paddle lub score punktu
void Ball::move(double dt,bool &point)
{
    if(dt <= 0) return;
    if(parent != NULL){
        this->position = parent->getPosition();
        return;
    }

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
            move(vdtLeft,point);
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
                    this->velocity.rx() *= -1;
                    int side = (this->game->getSide(paddle)*2 -1)*-1;
                    double angleToAdd = 0;
                    angleToAdd += ((this->position.y() - paddle->getPosition().y())/paddle->getSize())*5*side;
                    if(paddle->getDirection() == Paddle::DOWN){angleToAdd -= 5;}
                    if(paddle->getDirection() == Paddle::UP){angleToAdd += 5;}
                    if(qDegreesToRadians(angleToAdd) + getAngle() != M_PI_2 &&
                            qDegreesToRadians(angleToAdd) + getAngle() != M_PI_2 + M_PI){ //against vertical bouncing
                        this->setVelocityByAngle(this->getAngle()+(qDegreesToRadians(angleToAdd)));
                    }
                    move(hdtLeft,point);
                }else{
                    //score point
                    point = true;
                    this->parent = paddle;
                }
            }else{
                //score point
                point = true;
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
    setVelocityByAngle(qDegreesToRadians(randAngle));
    int direction = ((rand()%2)*2)-1; // random 1 or -1
    velocity *= direction;
}

double Ball::getAngle()
{  
    if(velocity.y() == 0){
        if(velocity.x() > 0){
            return 0;
        }else if(velocity.x() <0){
            return M_PI;
        }else{
            throw std::invalid_argument("Cant count angle because velocity is equal (0,0)");
        }
    }

    if(velocity.x() == 0){
        if(velocity.y() > 0){
            return M_PI_2;
        }else if(velocity.y() < 0){
            return M_PI+M_PI_2;
        }else{
            throw std::invalid_argument("Cant count angle because velocity is equal (0,0)");
        }
    }

    if(velocity.y()>0){
        if(velocity.x()>=0){
            return atan(abs(this->velocity.ry())/abs(this->velocity.rx()));
        }else{
            return atan(abs(this->velocity.x())/abs(this->velocity.y())) + M_PI_2;
        }
    }else{
        if(velocity.x()<0){
            return atan(abs(this->velocity.ry())/abs(this->velocity.rx())) + M_PI;
        }else{
            return atan(abs(this->velocity.x())/abs(this->velocity.y())) + M_PI + M_PI_2;
        }
    }
}

void Ball::setVelocityByAngle(double angle)
{
    velocity.setX(speed * cos(angle));
    velocity.setY(speed * sin(angle));
}



