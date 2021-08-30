#include "guiview.h"

GuiView::GuiView(Game& game,QWidget *parent) : QGraphicsView(parent)
{
    this->game = &game;
    this->mainMenuScene = new MainMenuScene(game,this);
    this->setScene(mainMenuScene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setFixedSize(1024,900);
}
