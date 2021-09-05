#include "gui_score.h"


Gui_Score::Gui_Score(Game *game, QObject *object, QGraphicsItem *parent) : QObject(object), QGraphicsRectItem(parent)
{
    setBrush(QColor(255, 255, 255, 127));
    this->game = game;

    this->setRect(-game->getPadle(0)->getWidth(),-30,game->getBoard().width()+(2*game->getPadle(0)->getWidth())+14,30);

    this->setRect(-30,0,30,game->getBoard().width()+game->getPadle(Game::LEFT)->getWidth()+game->getPadle(Game::RIGHT)->getWidth());

}
