#include "gui_ball.h"
#include <QDebug>

Gui_ball::Gui_ball(Ball *ball, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    this->ball = ball;
    this->setPos(this->ball->getPosition());
    QPixmap *pic = new QPixmap(":/new/pics/ball.png");


    this->setPixmap(pic->scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


}

void Gui_ball::updatePosition()
{
    this->setPos(this->ball->getPosition());
}
