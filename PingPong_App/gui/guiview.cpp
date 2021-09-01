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

    this->multiplayerMenuScene = new MultiplayerMenuScene(this->game,this);


    this->gameScene = new GameScene(this->game,this);

    showMainMenu();
}

void GuiView::startSinglePlayer()
{
    setFixedSize(game->getBoard().width()+58,game->getBoard().height()+58);
    this->setScene(gameScene);
    game->startGame();

}

void GuiView::showMultiplayerMenu()
{
    this->setScene(this->multiplayerMenuScene);
}

void GuiView::showMainMenu()
{
    this->setScene(this->mainMenuScene);
}

void GuiView::closeEvent(QCloseEvent *event)
{
    this->game->stopGame();
    event->accept();
}
