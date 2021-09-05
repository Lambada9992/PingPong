#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "model/game.h"
#include "gui_board.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>

class GuiView;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;
    Gui_board *guiBoard;
    QGraphicsRectItem *gameSceneRect;
    QLabel *score;


public:
    explicit GameScene(Game *game,GuiView *parent = nullptr);
    QGraphicsRectItem *getGameSceneRect() const;
private slots:
    void update();
};

#endif // MAINMENUSCENE_H
