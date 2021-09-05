#include "gui_paddle.h"
#include "guiview.h"

Gui_Paddle::Gui_Paddle(Paddle *paddle, QString color, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->paddle = paddle;
    updatePosition();
    this->color = color;
    prepare();
}

void Gui_Paddle::updatePosition()
{
    if(this->paddle->getPosition().rx() == 0 )
    {
        this->setPos(this->paddle->getPosition()-QPointF(0,paddle->getSize()) + QPointF(0,GuiView::getPaddleWidth()));
    }
    else if(this->paddle->getPosition().rx() != 0)
    {
        this->setPos(this->paddle->getPosition()-QPointF(0,paddle->getSize()) + QPointF(GuiView::getBallSize() + GuiView::getPaddleWidth(),GuiView::getPaddleWidth()));
    }

}

void Gui_Paddle::prepare()
{
    QPixmap *pic = new QPixmap(":/new/pics/"+ color +"_paddle.png");
    this->setPixmap(pic->scaled(GuiView::getPaddleWidth(),(paddle->getSize())*2 + GuiView::getBallSize(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
