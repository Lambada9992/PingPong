#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "game.h"

#include <QGraphicsScene>

class GuiView;

class MainMenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;

public:
    explicit MainMenuScene(Game &game,GuiView *parent = nullptr);

signals:

};

#endif // GUI_MAINMENUSCENE_H
