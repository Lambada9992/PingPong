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
public:
    explicit MainMenuScene(Game *game,GuiView *parent = nullptr);
    
public slots:
    void singleplayerButtonClicked();
    void settingsButtonClicked();

signals:
    void startSinglePlayer();
    void showSettings();

};

#endif // MAINMENUSCENE_H
