#include "gui_score.h"


Gui_Score::Gui_Score(Game *game, QObject *object, QGraphicsItem *parent) : QObject(object), QGraphicsRectItem(parent)
{
    setBrush(QColor(255, 255, 0, 127));
    this->game = game;
    this->setRect(-30,0,30,game->getBoard().width()+game->getPadle(0)->getWidth()+game->getPadle(1)->getWidth());
}
