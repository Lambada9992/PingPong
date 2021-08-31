#include "guiview.h"

GuiView::GuiView(Game& game,QWidget *parent) : QGraphicsView(parent)
{

    this->game = &game;
    this->mainMenuScene = new MainMenuScene(game,this);
    connect(this->mainMenuScene,SIGNAL(startSinglePlayer()),this,SLOT(startSinglePlayer()));
    this->setScene(mainMenuScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setFixedSize(1024,900);
}

void GuiView::startSinglePlayer()
{
    Gui_board = new class Gui_board(game);
    this->setScene(Gui_board);
}
