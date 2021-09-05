#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "model/game.h"
#include "gamescene.h"
#include "gui_board.h"
#include "mainmenuscene.h"
#include "settingsscene.h"

#include <QGraphicsView>

class GuiView : public QGraphicsView
{
    Q_OBJECT
private:
    Game *game;
    MainMenuScene *mainMenuScene;
    SettingsScene *settingsScene;
    GameScene *gameScene;

private:// GUI Properties
    static double paddleWidth;
    static double ballSize;


public:
    GuiView(Game& game,QWidget *parent = nullptr);

    static double getPaddleWidth();
    static double getBallSize();

public slots:
    void startSinglePlayer();
    void showMainMenu();
    void showSettings();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // GUIVIEW_H
