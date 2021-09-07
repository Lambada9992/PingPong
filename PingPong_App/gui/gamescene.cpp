#include "gamescene.h"
#include "guiview.h"

QGraphicsRectItem *GameScene::getGameSceneRect() const
{
    return gameSceneRect;
}

void GameScene::prepare()
{
    this->gameSceneRect->setRect(
                -1,
                -1,
                game->getBoard().width()  + 2*GuiView::getPaddleWidth() + GuiView::getBallSize(),
                game->getBoard().height() + 2*GuiView::getPaddleWidth() + GuiView::getBallSize()
                );
    int x,y,w,h;
    w = 200;
    h = 30;
    x = this->gameSceneRect->rect().width()/2 - w/2;
    y = this->gameSceneRect->rect().height();
    score->setGeometry(x,y,w,h);

    w = 150;
    h = 30;
    x = this->gameSceneRect->rect().width() - w;
    y = this->gameSceneRect->rect().height();
    mainMenuButton->setGeometry(x,y,w,h);
    guiBoard->prepare();
}

QLabel *GameScene::getScore() const
{
    return score;
}

GameScene::GameScene(Game *game, GuiView *parent)
    : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = game;
    this->gameSceneRect = new QGraphicsRectItem();

    //bg patern and color
    setBackgroundBrush(QColor(0, 0, 0, 150));

    this->addItem(gameSceneRect);
    this->guiBoard = new Gui_board(game,this);
    this->addItem(this->guiBoard);

    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()),Qt::BlockingQueuedConnection);

    score = new QLabel("0:0");
    mainMenuButton = new QPushButton(QString("Back to Menu"));
    prepare();

    int x,y,w,h;

    w = 200;
    h = 30;
    x = this->gameSceneRect->rect().width()/2 - w/2;
    y = this->gameSceneRect->rect().height();

    score->setGeometry(x,y,w,h);
    QFont font = score->font();
    font.setPointSize(20);
    font.setBold(true);
    score->setAlignment(Qt::AlignCenter);
    score->setFont(font);
    this->addWidget(score);



    w = 150;
    h = 30;
    x = this->gameSceneRect->rect().width() - w;
    y = this->gameSceneRect->rect().height();
    mainMenuButton->setGeometry(x,y,w,h);
    connect(mainMenuButton,SIGNAL(clicked()),this,SLOT(mainMenuButtonClicked()));
    addWidget(mainMenuButton);
}

void GameScene::update()
{
    score->setText(QString::number(game->getScore().first)+ ":" + QString::number(game->getScore().second));

    prepare();
}

void GameScene::mainMenuButtonClicked()
{
    emit showMainMenu();
}
