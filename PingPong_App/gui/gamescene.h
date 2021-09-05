#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "model/game.h"
#include "gui_board.h"
#include "gui_score.h"

#include <QGraphicsScene>
#include <QPushButton>

class GuiView;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;
    Gui_board *guiBoard;
    Gui_Score *guiScore;
    QGraphicsRectItem *gameSceneRect = new QGraphicsRectItem();

public:
    explicit GameScene(Game *game,GuiView *parent = nullptr);
    QGraphicsRectItem *getGameSceneRect() const;
};

#endif // MAINMENUSCENE_H
