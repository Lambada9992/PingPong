#include "gamescene.h"
#include "guiview.h"

QGraphicsRectItem *GameScene::getGameSceneRect() const
{
    return gameSceneRect;
}

GameScene::GameScene(Game *game, GuiView *parent)
 : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = game;
    this->gameSceneRect = new QGraphicsRectItem();

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));


//    this->gameSceneRect->setRect(
//                -game->getPadle(Game::LEFT)->getWidth(),
//                -20,
//                game->getBoard().width()+(game->getPadle(Game::LEFT)->getWidth()),
//                game->getBoard().height()+game->getBall()->getSize()+20);
    this->gameSceneRect->setRect(
                0,
                0,
                game->getBoard().width()  + 2*GuiView::getPaddleWidth() + GuiView::getBallSize(),
                game->getBoard().height() + 2*GuiView::getPaddleWidth() + GuiView::getBallSize()
                );


    this->addItem(gameSceneRect);
    this->guiBoard = new Gui_board(game,this);
    this->guiScore = new Gui_Score(game,this);
//    this->gameSceneRect->setRect(
//                -game->getPadle(Game::LEFT)->getWidth(),
//                -guiScore->rect().height(),
//                game->getBoard().width()+(game->getPadle(Game::LEFT)->getWidth()),
//                game->getBoard().height()+game->getBall()->getSize()+guiScore->rect().height()
//                );
    //this->guiBoard->setRect(0,0,game->getBoard().width(),game->getBoard().height());
    //this->guiBoard->setRect(this->game->getBoard());
    this->addItem(this->guiBoard);
    //this->addItem(this->guiScore);
}
