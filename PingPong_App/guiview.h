#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "game.h"
#include "gui_board.h"
#include "mainmenuscene.h"

#include <QGraphicsView>

class GuiView : public QGraphicsView
{
    Q_OBJECT
private:
    Game *game;
    MainMenuScene *mainMenuScene;
    Gui_board *gui_board;

public:
    GuiView(Game& game,QWidget *parent = nullptr);
public slots:
    void startSinglePlayer();
};

#endif // GUIVIEW_H
