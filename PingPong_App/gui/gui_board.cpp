#include "gui_board.h"
#include "gui_paddle.h"

Gui_board::Gui_board(Game *game, QObject *object, QGraphicsItem *parent) : QObject(object), QGraphicsRectItem(parent)
{
    this->game = game;
    this->setRect(0,0,game->getBoard().width()+14,game->getBoard().height()+14);

    gui_ball = new Gui_ball(game->getBall(), this);
    gui_padles.append(new Gui_Paddle(game->getPadle(0),"red", this));
    gui_padles.append(new Gui_Paddle(game->getPadle(1),"blue", this));
    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()),Qt::BlockingQueuedConnection);
}

void Gui_board::update()
{
    this->gui_ball->updatePosition();
    this->gui_padles[0]->updatePosition();
    this->gui_padles[1]->updatePosition();
}
