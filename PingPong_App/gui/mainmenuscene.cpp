#include "mainmenuscene.h"
#include "guiview.h"

#include <QGraphicsTextItem>
#include <QPushButton>

MainMenuScene::MainMenuScene(Game *game, GuiView *parent)
    : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = game;
    this->parent = parent;
    ///
    int m_scale = 15;
    setSceneRect(0,0,43*m_scale,33*m_scale);

    //bg patern and color
    setBackgroundBrush(QBrush(Qt::darkGray,Qt::SolidPattern));

    int x,y,w,h;

    //title "PingPong"
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("PingPong"));
    QFont titleFont("comic sans",m_scale*4,QFont::Bold);
    title->setFont(titleFont);
    x = this->width()/2 - title->boundingRect().width()/2;
    y = m_scale;
    title->setPos(x,y);
    addItem(title);


    //singleplayer button
    singleplayerButton = new QPushButton(QString("Start Game"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 12*m_scale;
    singleplayerButton->setGeometry(x,y,w,h);
    connect(singleplayerButton,SIGNAL(clicked()),this,SLOT(singleplayerButtonClicked()));
    addWidget(singleplayerButton);

    settingsButton = new QPushButton(QString("Settings"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 15*m_scale;
    settingsButton->setGeometry(x,y,w,h);
    connect(settingsButton,SIGNAL(clicked()),this,SLOT(settingsButtonClicked()));
    addWidget(settingsButton);

    exitButton = new QPushButton(QString("Exit"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 18*m_scale;
    exitButton->setGeometry(x,y,w,h);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(exitButtonClicked()));
    addWidget(exitButton);

}

void MainMenuScene::singleplayerButtonClicked()
{
    startSinglePlayer();
}

void MainMenuScene::settingsButtonClicked()
{
    emit showSettings();
}
void MainMenuScene::exitButtonClicked()
{
    exit(0);
}
