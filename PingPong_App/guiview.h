#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "game.h"
#include "mainmenuscene.h"

#include <QGraphicsView>

class GuiView : public QGraphicsView
{
    Q_OBJECT
private:
    Game *game;
    MainMenuScene *mainMenuScene;
public:
    GuiView(Game& game,QWidget *parent = nullptr);
};

#endif // GUIVIEW_H
