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

    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Ustawienia"));
    QFont titleFont("comic sans",m_scale*2,QFont::Bold);
    title->setFont(titleFont);
    x = this->width()/2 - title->boundingRect().width()/2;
    y = 3*m_scale;
    title->setPos(x,y);
    addItem(title);

    QSpinBox *boardSizeXSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 12*m_scale;
    boardSizeXSpinBox->setGeometry(x,y,w,h);
    boardSizeXSpinBox->setRange(0,2000);
    boardSizeXSpinBox->setValue(800);
    addWidget(boardSizeXSpinBox);

    QSpinBox *boardSizeYSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 15*m_scale;
    boardSizeYSpinBox->setGeometry(x,y,w,h);
    boardSizeYSpinBox->setRange(0,1200);
    boardSizeYSpinBox->setValue(600);
    addWidget(boardSizeYSpinBox);

    QPushButton *saveButton = new QPushButton(QString("Save Changes"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 18*m_scale;
    saveButton->setGeometry(x,y,w,h);
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveButtonClicked()));
    addWidget(saveButton);

    QPushButton *mainMenuButton = new QPushButton(QString("Back"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 21*m_scale;
    mainMenuButton->setGeometry(x,y,w,h);
    connect(mainMenuButton,SIGNAL(clicked()),this,SLOT(mainMenuButtonClicked()));
    addWidget(mainMenuButton);
}
void SettingsScene::mainMenuButtonClicked()
{
    emit showMainMenu();
}
void SettingsScene::saveButtonClicked()
{
    game->setBoardSizeX(boardSizeXSpinBox->value());
    game->setBoardSizeY(boardSizeYSpinBox->value());
}
