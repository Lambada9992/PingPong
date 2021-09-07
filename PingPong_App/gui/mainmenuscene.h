#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "model/game.h"

#include <QGraphicsScene>
#include <QPushButton>

class GuiView;

/**
 * @brief The MainMenuScene class klasa odpowiedzialna za scenę głównego menu aplikacji
 */
class MainMenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;
    QPushButton *singleplayerButton;
    QPushButton *multiplayerButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
public:
    explicit MainMenuScene(Game *game,GuiView *parent = nullptr);
    
public slots:
    /**
     * @brief singleplayerButtonClicked metoda odpowiedzialna za obsługę naciśnięcia przycisku w GUI
     */
    void singleplayerButtonClicked();
    /**
     * @brief settingsButtonClicked  metoda odpowiedzialna za obsługę naciśnięcia przycisku w GUI
     */
    void settingsButtonClicked();
    void exitButtonClicked();


signals:
    void startSinglePlayer();
    void showSettings();

};

#endif // MAINMENUSCENE_H
