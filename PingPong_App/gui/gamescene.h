#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "model/game.h"
#include "gui_board.h"

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

public:
    explicit GameScene(Game *game,GuiView *parent = nullptr);
};

#endif // MAINMENUSCENE_H
