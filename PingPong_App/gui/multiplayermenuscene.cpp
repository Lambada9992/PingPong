#include "multiplayermenuscene.h"

MultiplayerMenuScene::MultiplayerMenuScene(Game *game, GuiView *parent)
    : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    //bg patern and color
    setBackgroundBrush(QBrush(Qt::darkGray,Qt::SolidPattern));

    int m_scale = 15;
    setSceneRect(0,0,43*m_scale,33*m_scale);
    int x,y,w,h;

    //Host Button
    QPushButton *hostGameButton = new QPushButton(QString("Host Game"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 12*m_scale;
    hostGameButton->setGeometry(x,y,w,h);
    connect(hostGameButton,SIGNAL(clicked()),this,SLOT(hostButtonClicked()));//////do poprawy
    addWidget(hostGameButton);

    //Join Button
    QPushButton *joinGameButton = new QPushButton(QString("Join as a viewer"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 15*m_scale;
    joinGameButton->setGeometry(x,y,w,h);
    connect(joinGameButton,SIGNAL(clicked()),this,SLOT(joinButtonClicked()));//////do poprawy
    addWidget(joinGameButton);

    mainMenuButton = new QPushButton(QString("Back"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 18*m_scale;
    mainMenuButton->setGeometry(x,y,w,h);
    connect(mainMenuButton,SIGNAL(clicked()),this,SLOT(mainMenuButtonClicked()));
    addWidget(mainMenuButton);

}

void MultiplayerMenuScene::mainMenuButtonClicked()
{
    showMainMenu();
}

void MultiplayerMenuScene::hostButtonClicked()
{

}

void MultiplayerMenuScene::joinButtonClicked()
{

}
