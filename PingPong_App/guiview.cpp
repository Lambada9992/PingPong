#include "guiview.h"

GuiView::GuiView(Game& game,QWidget *parent) : QGraphicsView(parent)
{
    this->game = &game;
    this->mainMenuScene = new MainMenuScene(game,this);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1024,900);
}
