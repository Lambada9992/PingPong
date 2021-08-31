#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "game.h"
#include "gamescene.h"
#include "gui_board.h"
#include "mainmenuscene.h"

#include <QGraphicsView>

class GuiView : public QGraphicsView
{
    Q_OBJECT
private:
    Game *game;
    MainMenuScene *mainMenuScene;
    GameScene *gameScene;

public:
    GuiView(Game& game,QWidget *parent = nullptr);
public slots:
    void startSinglePlayer();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // GUIVIEW_H
