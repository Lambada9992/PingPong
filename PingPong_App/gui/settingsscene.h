#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H


#include <QGraphicsScene>
#include <QPushButton>
#include <QSpinBox>

#include <model/game.h>

class GuiView;

class SettingsScene : public QGraphicsScene
{
    Q_OBJECT

private:
    Game *game;
    QPushButton *mainMenuButton;
    QPushButton *saveButton;
    QSpinBox *boardSizeXSpinBox;
    QSpinBox *boardSizeYSpinBox;
    QSpinBox *ballSpeedSpinBox;
    QSpinBox *paddleSpeedSpinBox;
    QSpinBox *paddleSizeSpinBox;
    QSpinBox *maxScoreSpinBox;


public:
    SettingsScene(Game *game, GuiView *parent = nullptr);

public slots:
    void mainMenuButtonClicked();
    void saveButtonClicked();

signals:
    void showMainMenu();

};

#endif // SETTINGSSCENE_H
