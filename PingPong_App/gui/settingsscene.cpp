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

    QGraphicsTextItem *widthText = new QGraphicsTextItem(QString("Szerokość:"));
    x = this->width()/2 - widthText->boundingRect().width()/2;
    y = 6*m_scale;
    widthText->setPos(x,y);
    addItem(widthText);

    boardSizeXSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 7.5*m_scale;
    boardSizeXSpinBox->setGeometry(x,y,w,h);
    boardSizeXSpinBox->setRange(0,2000);
    boardSizeXSpinBox->setValue(800);
    addWidget(boardSizeXSpinBox);

    QGraphicsTextItem *heightText = new QGraphicsTextItem(QString("Wysokość:"));
    title->setFont(titleFont);
    x = this->width()/2 - heightText->boundingRect().width()/2;
    y = 9.5*m_scale;
    heightText->setPos(x,y);
    addItem(heightText);

    boardSizeYSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 11*m_scale;
    boardSizeYSpinBox->setGeometry(x,y,w,h);
    boardSizeYSpinBox->setRange(0,1200);
    boardSizeYSpinBox->setValue(600);
    addWidget(boardSizeYSpinBox);

    QGraphicsTextItem *ballSpeedText = new QGraphicsTextItem(QString("Prędkość piłki:"));
    x = this->width()/2 - ballSpeedText->boundingRect().width()/2;
    y = 13*m_scale;
    ballSpeedText->setPos(x,y);
    addItem(ballSpeedText);

    ballSpeedSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 14.5*m_scale;
    ballSpeedSpinBox->setGeometry(x,y,w,h);
    ballSpeedSpinBox->setRange(0,1200);
    ballSpeedSpinBox->setValue(350);
    addWidget(ballSpeedSpinBox);

    QGraphicsTextItem *paddleSpeedText = new QGraphicsTextItem(QString("Prędkość paletki:"));
    x = this->width()/2 - paddleSpeedText->boundingRect().width()/2;
    y = 16.5*m_scale;
    paddleSpeedText->setPos(x,y);
    addItem(paddleSpeedText);

    paddleSpeedSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 18*m_scale;
    paddleSpeedSpinBox->setGeometry(x,y,w,h);
    paddleSpeedSpinBox->setRange(0,1200);
    paddleSpeedSpinBox->setValue(350);
    addWidget(paddleSpeedSpinBox);

    QGraphicsTextItem *paddleSizeText = new QGraphicsTextItem(QString("Rozmiar paletki:"));
    x = this->width()/2 - paddleSizeText->boundingRect().width()/2;
    y = 20*m_scale;
    paddleSizeText->setPos(x,y);
    addItem(paddleSizeText);

    paddleSizeSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 21.5*m_scale;
    paddleSizeSpinBox->setGeometry(x,y,w,h);
    paddleSizeSpinBox->setRange(0,1200);
    paddleSizeSpinBox->setValue(100);
    addWidget(paddleSizeSpinBox);

    saveButton = new QPushButton(QString("Save Changes"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 25.5*m_scale;
    saveButton->setGeometry(x,y,w,h);
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveButtonClicked()));
    addWidget(saveButton);

    mainMenuButton = new QPushButton(QString("Back"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 28.5*m_scale;
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
    game->setPaddleSize(paddleSizeSpinBox->value());
    game->setPaddleSpeed(paddleSpeedSpinBox->value());
    game->setBallSpeed(ballSpeedSpinBox->value());
}
