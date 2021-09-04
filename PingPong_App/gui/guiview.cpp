#include "guiview.h"

#include <QMainWindow>
#include <QCloseEvent>

GuiView::GuiView(Game &game,QWidget *parent) : QGraphicsView(parent)
{

    this->game = &game;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignTop|Qt::AlignLeft);
    setFixedSize(500,500);

    this->mainMenuScene = new MainMenuScene(this->game,this);
    connect(this->mainMenuScene,SIGNAL(startSinglePlayer()),this,SLOT(startSinglePlayer()));
    connect(this->mainMenuScene,SIGNAL(showMultiplayerMenu()),this,SLOT(showMultiplayerMenu()));
    connect(this->mainMenuScene,SIGNAL(showSettings()),this,SLOT(showSettings()));

    this->multiplayerMenuScene = new MultiplayerMenuScene(this->game,this);
    connect(this->multiplayerMenuScene,SIGNAL(showMainMenu()),this,SLOT(showMainMenu()));

    this->settingsScene = new SettingsScene(this->game,this);
    connect(this->settingsScene,SIGNAL(showMainMenu()),this,SLOT(showMainMenu()));

    this->gameScene = new GameScene(this->game,this);

    showMainMenu();
}

void GuiView::startSinglePlayer()
{
    setFixedSize(gameScene->getGameSceneRect()->rect().width()+(2*game->getPadle(0)->getWidth()),gameScene->getGameSceneRect()->rect().height());
    this->setScene(gameScene);
    game->startGame();
    //this->scale(1.5,1.5);
    //setFixedSize((game->getBoard().width()+58)*1.5,(game->getBoard().height()+14)*1.5);

}

void GuiView::showMultiplayerMenu()
{
    this->setScene(this->multiplayerMenuScene);
}

void GuiView::showMainMenu()
{
    this->setScene(this->mainMenuScene);
}
void GuiView::showSettings()
{
    this->setScene(this->settingsScene);
}

void GuiView::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_S:
    {
        this->game->getPadle(0)->setDirection(Paddle::UP);
    }
        break;
    case Qt::Key_W:
    {
        this->game->getPadle(0)->setDirection(Paddle::DOWN);
    }
        break;
    case Qt::Key_Down:
    {
        this->game->getPadle(1)->setDirection(Paddle::UP);
    }
        break;
    case Qt::Key_Up:
    {
        this->game->getPadle(1)->setDirection(Paddle::DOWN);
    }
        break;
    }
}

void GuiView::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
    {
        this->game->getPadle(0)->setDirection(Paddle::NONE);
    }
        break;
    case Qt::Key_S:
    {
        this->game->getPadle(0)->setDirection(Paddle::NONE);
    }
        break;
    case Qt::Key_Up:
    {
        this->game->getPadle(1)->setDirection(Paddle::NONE);
    }
        break;
    case Qt::Key_Down:
    {
        this->game->getPadle(1)->setDirection(Paddle::NONE);
    }
        break;
    }
}


void GuiView::closeEvent(QCloseEvent *event)
{
    this->game->stopGame();
    event->accept();
}
