#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "model/game.h"
#include "gamescene.h"
#include "gui_board.h"
#include "mainmenuscene.h"
#include "settingsscene.h"

#include <QGraphicsView>

/**
 * @brief The GuiView class Klasa odpowiedzialna za wyświetlanie okienka aplikacji
 */
class GuiView : public QGraphicsView
{
    Q_OBJECT
private:
    Game *game;
    MainMenuScene *mainMenuScene;
    SettingsScene *settingsScene;
    GameScene *gameScene;

private:// GUI Properties
    static double paddleWidth;
    static double ballSize;


public:
    /**
     * @brief GuiView konstruktor
     * @param game logika aplikacji
     * @param parent rodzic
     */
    GuiView(Game& game,QWidget *parent = nullptr);

    static double getPaddleWidth();
    static double getBallSize();

public slots:
    /**
     * @brief startSinglePlayer obsługa naciśnięcia przycisku singlePlayer
     */
    void startSinglePlayer();
    /**
     * @brief showMainMenu obsługa naciśnięcia przycisku MainMenu
     */
    void showMainMenu();
    /**
     * @brief showSettings obsługa naciśnięcia przycisku Settings
     */
    void showSettings();

    /**
     * @brief keyPressEvent metoda obsługująca zdarzenia powodowane naciskaniem przycisków na klawiaturze
     * @param event przychodzący event(przycisk)
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief keyReleaseEvent metoda obsługująca zdarzenia powodowane puszczaniem przycisków na klawiaturze
     * @param event przychodzący event(przycisk)
     */
    void keyReleaseEvent(QKeyEvent *event);

    // QWidget interface
protected:
    /**
     * @brief closeEvent metoda obsługująca event zamknięcia aplikacji po przez naciśnięcie przycisku
     * @param event przychodzący event
     */
    void closeEvent(QCloseEvent *event) override;
};

#endif // GUIVIEW_H
