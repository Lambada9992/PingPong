#include "settingsscene.h"
#include "guiview.h"

SettingsScene::SettingsScene(Game *game, GuiView *parent)
    : QGraphicsScene(reinterpret_cast<QObject *>(parent))
{
    this->game = game;
    setBackgroundBrush(QBrush(Qt::darkGray,Qt::SolidPattern));

    int m_scale = 15;
    setSceneRect(0,0,43*m_scale,33*m_scale);
    int x,y,w,h;

    QPushButton *mainMenuButton = new QPushButton(QString("Back"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 15*m_scale;
    mainMenuButton->setGeometry(x,y,w,h);
    connect(mainMenuButton,SIGNAL(clicked()),this,SLOT(mainMenuButtonClicked()));
    addWidget(mainMenuButton);
}
void SettingsScene::mainMenuButtonClicked()
{
    emit showMainMenu();
}
