#include "mainmenuscene.h"
#include "guiview.h"

MainMenuScene::MainMenuScene(Game &game,GuiView *parent)
    : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = &game;
    this->parent = parent;
}
