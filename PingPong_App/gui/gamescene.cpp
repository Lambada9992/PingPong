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
    setBackgroundBrush(QColor(0, 0, 0, 150));

    this->gameSceneRect->setRect(
                0,
                0,
                game->getBoard().width()  + 2*GuiView::getPaddleWidth() + GuiView::getBallSize(),
                game->getBoard().height() + 2*GuiView::getPaddleWidth() + GuiView::getBallSize()
                );

    this->addItem(gameSceneRect);
    int x,y,w,h;

    score = new QLabel("0:0");
    w = 30;
    h = 30;
    x = this->gameSceneRect->rect().width()/2 - w/2;
    y = this->gameSceneRect->rect().height()/2 - h/2;
    score->setGeometry(x,y,w,h);
    QFont font = score->font();
    font.setPointSize(10);
    font.setBold(true);
    score->setFont(font);
    score->show();


    this->guiBoard = new Gui_board(game,this);
    this->addItem(this->guiBoard);
    this->addWidget(score);
    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()),Qt::BlockingQueuedConnection);
}

void GameScene::update()
{
    score->setText(QString::number(game->getScore().first)+ ":" + QString::number(game->getScore().second));
}
