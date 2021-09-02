#include "gui_paddle.h"

Gui_Paddle::Gui_Paddle(Paddle *paddle, QString color, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->paddle = paddle;
    updatePosition();
    QPixmap *pic = new QPixmap(":/new/pics/"+ color +"_paddle.png");
    this->setPixmap(pic->scaled(15,paddle->getSize()*2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}

void Gui_Paddle::updatePosition()
{
    if(this->paddle->getPosition().rx() == 0 )
    {
        this->setPos(this->paddle->getPosition() - QPointF(15,paddle->getSize()));
    }
    else if(this->paddle->getPosition().rx() != 0)
    {
        this->setPos(this->paddle->getPosition() - QPointF(-17,paddle->getSize()));
    }


}
