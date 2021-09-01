#ifndef MULTIPLAYERMENUSCENE_H
#define MULTIPLAYERMENUSCENE_H


#include <QGraphicsScene>
#include <QPushButton>

#include <model/game.h>

class GuiView;

class MultiplayerMenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    QPushButton *mainMenuButton;
public:
    MultiplayerMenuScene(Game *game,GuiView *parent = nullptr);

public slots:
    void mainMenuButtonClicked();
    void hostButtonClicked();
    void joinButtonClicked();
signals:
    void showMainMenu();

};

#endif // MULTIPLAYERMENUSCENE_H
