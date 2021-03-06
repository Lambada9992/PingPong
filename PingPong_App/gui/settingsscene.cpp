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
    y = 1*m_scale;
    title->setPos(x,y);
    addItem(title);

    QGraphicsTextItem *widthText = new QGraphicsTextItem(QString("Szerokość:"));
    x = this->width()/2 - widthText->boundingRect().width()/2;
    y = 7*m_scale;
    widthText->setPos(x,y);
    addItem(widthText);

    boardSizeXSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 8.5*m_scale;
    boardSizeXSpinBox->setGeometry(x,y,w,h);
    boardSizeXSpinBox->setRange(0,2000);
    boardSizeXSpinBox->setValue(800);

    boardSizeXSpinBox->setAccelerated(true);

    addWidget(boardSizeXSpinBox);

    QGraphicsTextItem *heightText = new QGraphicsTextItem(QString("Wysokość:"));
    title->setFont(titleFont);
    x = this->width()/2 - heightText->boundingRect().width()/2;
    y = 10.5*m_scale;
    heightText->setPos(x,y);
    addItem(heightText);

    boardSizeYSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 12*m_scale;
    boardSizeYSpinBox->setGeometry(x,y,w,h);
    boardSizeYSpinBox->setRange(0,1200);
    boardSizeYSpinBox->setValue(600);
    boardSizeYSpinBox->setAccelerated(true);
    addWidget(boardSizeYSpinBox);

    QGraphicsTextItem *ballSpeedText = new QGraphicsTextItem(QString("Prędkość piłki:"));
    x = this->width()/2 - ballSpeedText->boundingRect().width()/2;
    y = 14*m_scale;
    ballSpeedText->setPos(x,y);
    addItem(ballSpeedText);

    ballSpeedSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 15.5*m_scale;
    ballSpeedSpinBox->setGeometry(x,y,w,h);
    ballSpeedSpinBox->setRange(0,1200);
    ballSpeedSpinBox->setValue(350);
    ballSpeedSpinBox->setAccelerated(true);
    addWidget(ballSpeedSpinBox);

    QGraphicsTextItem *paddleSpeedText = new QGraphicsTextItem(QString("Prędkość paletki:"));
    x = this->width()/2 - paddleSpeedText->boundingRect().width()/2;
    y = 17.5 *m_scale;
    paddleSpeedText->setPos(x,y);
    addItem(paddleSpeedText);

    paddleSpeedSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 19*m_scale;
    paddleSpeedSpinBox->setGeometry(x,y,w,h);
    paddleSpeedSpinBox->setRange(0,1200);
    paddleSpeedSpinBox->setValue(350);
    paddleSpeedSpinBox->setAccelerated(true);
    addWidget(paddleSpeedSpinBox);

    QGraphicsTextItem *paddleSizeText = new QGraphicsTextItem(QString("Rozmiar paletki:"));
    x = this->width()/2 - paddleSizeText->boundingRect().width()/2;
    y = 21*m_scale;
    paddleSizeText->setPos(x,y);
    addItem(paddleSizeText);

    paddleSizeSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 22.5*m_scale;
    paddleSizeSpinBox->setGeometry(x,y,w,h);
    paddleSizeSpinBox->setRange(0,1200);
    paddleSizeSpinBox->setValue(100);
    paddleSizeSpinBox->setAccelerated(true);
    addWidget(paddleSizeSpinBox);

    QGraphicsTextItem *maxScoreText = new QGraphicsTextItem(QString("Maksymalny wynik:"));
    x = this->width()/2 - maxScoreText->boundingRect().width()/2;
    y = 24.5*m_scale;
    maxScoreText->setPos(x,y);
    addItem(maxScoreText);

    maxScoreSpinBox = new QSpinBox();
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 26*m_scale;
    maxScoreSpinBox->setGeometry(x,y,w,h);
    maxScoreSpinBox->setRange(1,100);
    maxScoreSpinBox->setValue(15);
    maxScoreSpinBox->setAccelerated(true);
    addWidget(maxScoreSpinBox);

    saveButton = new QPushButton(QString("Save Changes"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 28.5*m_scale;
    saveButton->setGeometry(x,y,w,h);
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveButtonClicked()));
    addWidget(saveButton);

    mainMenuButton = new QPushButton(QString("Back"));
    w = this->width()/4;
    h = this->height()/18;
    x = this->width()/2 - w/2;
    y = 30.5*m_scale;
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
    game->setMaxScore(maxScoreSpinBox->value());
}
