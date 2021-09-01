#ifndef MULTIPLAYERMENUSCENE_H
#define MULTIPLAYERMENUSCENE_H


#include <QGraphicsScene>

#include <model/game.h>

class GuiView;

class MultiplayerMenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
public:
    MultiplayerMenuScene(Game *game,GuiView *parent = nullptr);

public slots:

};

#endif // MULTIPLAYERMENUSCENE_H
