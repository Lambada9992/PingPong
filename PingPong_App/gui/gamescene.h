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
    QPushButton *mainMenuButton;


public:
    explicit GameScene(Game *game,GuiView *parent = nullptr);
    QGraphicsRectItem *getGameSceneRect() const;

    void prepare();
    QLabel *getScore() const;
signals:
    void showMainMenu();
public slots:
    void update();
private slots:
    void mainMenuButtonClicked();
};

#endif // MAINMENUSCENE_H
