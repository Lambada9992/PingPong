#include "gui_board.h"
#include "gui_paddle.h"
#include "guiview.h"

Gui_board::Gui_board(Game *game, QObject *object, QGraphicsItem *parent) : QObject(object), QGraphicsRectItem(parent)
{
    setBrush(QColor(255, 0, 0, 127));
    this->game = game;

    gui_ball = new Gui_ball(game->getBall(),
                            this);
    gui_padles.append(new Gui_Paddle(game->getPadle(Game::LEFT),"red", this));
    gui_padles.append(new Gui_Paddle(game->getPadle(Game::RIGHT),"blue", this));
    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()),Qt::BlockingQueuedConnection);

    prepare();
}

void Gui_board::update()
{
    this->gui_ball->updatePosition();
    this->gui_padles[0]->updatePosition();
    this->gui_padles[1]->updatePosition();
}

void Gui_board::prepare()
{
    this->setRect(
                GuiView::getPaddleWidth(),
                GuiView::getPaddleWidth()-1,
                game->getBoard().width()  + GuiView::getBallSize(),
                game->getBoard().height() + GuiView::getBallSize()
                );
    this->gui_padles[0]->prepare();
    this->gui_padles[1]->prepare();
}
