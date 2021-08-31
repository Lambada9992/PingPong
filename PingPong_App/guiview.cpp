#include "guiview.h"

#include <QMainWindow>
#include <QCloseEvent>

GuiView::GuiView(Game &game,QWidget *parent) : QGraphicsView(parent)
{

    this->game = &game;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignTop|Qt::AlignLeft);
    setFixedSize(800,800);

    this->mainMenuScene = new MainMenuScene(this->game,this);
    connect(this->mainMenuScene,SIGNAL(startSinglePlayer()),this,SLOT(startSinglePlayer()));
    this->setScene(mainMenuScene);

    this->gameScene = new GameScene(this->game,this);
}

void GuiView::startSinglePlayer()
{
    this->setScene(gameScene);
    game->startGame();
}

void GuiView::closeEvent(QCloseEvent *event)
{
    this->game->stopGame();
    //this->game->wait();
    event->accept();
}
