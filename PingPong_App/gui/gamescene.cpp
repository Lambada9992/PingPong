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


//    this->gameSceneRect->setRect(
//                -game->getPadle(Game::LEFT)->getWidth(),
//                -20,
//                game->getBoard().width()+(game->getPadle(Game::LEFT)->getWidth()),
//                game->getBoard().height()+game->getBall()->getSize()+20);

    this->addItem(gameSceneRect);
    this->guiBoard = new Gui_board(game,this);
    this->guiScore = new Gui_Score(game,this);
    this->gameSceneRect->setRect(-game->getPadle(Game::LEFT)->getWidth(),
                                 -guiScore->rect().height(),
                                 game->getBoard().width()+(game->getPadle(Game::LEFT)->getWidth()),
                                 game->getBoard().height()+game->getBall()->getSize()+guiScore->rect().height());

    this->addItem(this->guiBoard);
    this->addItem(this->guiScore);
}
