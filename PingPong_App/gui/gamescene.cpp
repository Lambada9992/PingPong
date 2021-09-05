#include "gamescene.h"

QGraphicsRectItem *GameScene::getGameSceneRect() const
{
    return gameSceneRect;
}

GameScene::GameScene(Game *game, GuiView *parent)
{
    this->game = game;

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));
    this->addItem(gameSceneRect);
    this->guiBoard = new Gui_board(game,this);
    this->guiScore = new Gui_Score(game,this);
    this->gameSceneRect->setRect(-game->getPadle(0)->getWidth(),-guiScore->rect().height(),game->getBoard().width()+(game->getPadle(0)->getWidth()),game->getBoard().height()+game->getBall()->getSize()+guiScore->rect().height());
    //this->guiBoard->setRect(0,0,game->getBoard().width(),game->getBoard().height());
    //this->guiBoard->setRect(this->game->getBoard());
    this->addItem(this->guiBoard);
    this->addItem(this->guiScore);
}
