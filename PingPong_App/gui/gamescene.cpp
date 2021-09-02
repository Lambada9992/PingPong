#include "gamescene.h"

GameScene::GameScene(Game *game, GuiView *parent)
{
    this->game = game;

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));
    this->gameSceneRect->setRect(-20,0,game->getBoard().width()+54,game->getBoard().height()+14);
    this->addItem(gameSceneRect);
    this->guiBoard = new Gui_board(game,this);
    //this->guiBoard->setRect(0,0,game->getBoard().width(),game->getBoard().height());
    //this->guiBoard->setRect(this->game->getBoard());
    this->addItem(this->guiBoard);
}
