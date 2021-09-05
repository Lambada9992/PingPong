#include "gamescene.h"
#include "guiview.h"

QGraphicsRectItem *GameScene::getGameSceneRect() const
{
    return gameSceneRect;
}

void GameScene::prepare()
{
    this->gameSceneRect->setRect(
                0,
                0,
                game->getBoard().width()  + 2*GuiView::getPaddleWidth() + GuiView::getBallSize(),
                game->getBoard().height() + 2*GuiView::getPaddleWidth() + GuiView::getBallSize()
                );
    guiBoard->prepare();
}

GameScene::GameScene(Game *game, GuiView *parent)
 : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = game;
    this->gameSceneRect = new QGraphicsRectItem();

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));

    this->addItem(gameSceneRect);

    this->guiBoard = new Gui_board(game,this);
    this->addItem(this->guiBoard);

    prepare();
}
