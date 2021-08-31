#include "gui_paddle.h"

Gui_Paddle::Gui_Paddle(Paddle *paddle, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->paddle = paddle;
    this->setPos(this->paddle->getPosition());
    QPixmap pic = QPixmap(":/new/pics/ball.png");
    pic.size().setWidth(30);
    pic.size().setHeight(30);
    this->setPixmap(pic);


}

void Gui_Paddle::updatePosition()
{
    this->setPos(this->paddle->getPosition());

}
