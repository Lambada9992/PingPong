#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H


#include <QGraphicsScene>
#include <QPushButton>

#include <model/game.h>

class GuiView;

class SettingsScene : public QGraphicsScene
{
    Q_OBJECT

private:
    Game *game;
    QPushButton *mainMenuButton;

public:
    SettingsScene(Game *game, GuiView *parent = nullptr);

public slots:
    void mainMenuButtonClicked();

signals:
    void showMainMenu();

};

#endif // SETTINGSSCENE_H
