#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "model/game.h"

#include <QGraphicsScene>
#include <QPushButton>

class GuiView;

class MainMenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;
    QPushButton *singleplayerButton;
    QPushButton *multiplayerButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
public:
    explicit MainMenuScene(Game *game,GuiView *parent = nullptr);
    
public slots:
    void singleplayerButtonClicked();
    void settingsButtonClicked();
    void exitButtonClicked();


signals:
    void startSinglePlayer();
    void showSettings();

};

#endif // MAINMENUSCENE_H
