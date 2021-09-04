#ifndef GUI_SCORE_H
#define GUI_SCORE_H

#include "model/game.h"
#include <qgraphicsitem.h>


class Gui_Score : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Gui_Score(Game *game,QObject *object = nullptr,QGraphicsItem *parent = nullptr);
private:
    Game *game;
};

#endif // GUI_SCORE_H
