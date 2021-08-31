#include "gamescene.h"

GameScene::GameScene(Game *game, GuiView *parent)
{
    this->game = game;

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::darkGray,Qt::SolidPattern));

    this->guiBoard = new Gui_board(game,this);
    this->guiBoard->setRect(0,0,800,800);
    //this->guiBoard->setRect(this->game->getBoard());
    this->addItem(this->guiBoard);
}
