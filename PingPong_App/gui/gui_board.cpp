#include "gui_board.h"

Gui_board::Gui_board(Game *game, QObject *object, QGraphicsItem *parent) : QObject(object), QGraphicsRectItem(parent)
{
    this->game = game;
    this->setRect(this->game->getBoard());
    gui_ball = new Gui_ball(game->getBall(), this);
    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()),Qt::BlockingQueuedConnection);
}

void Gui_board::update()
{
    this->gui_ball->updatePosition();
}
