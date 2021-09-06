#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "model/game.h"
#include "gui_board.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>

class GuiView;
/**
 * @brief The GameScene class Klasa odpowiedzialna za wyświetlanie sceny gry
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Game *game;
    GuiView *parent;
    Gui_board *guiBoard;
    QGraphicsRectItem *gameSceneRect;
    QLabel *score;
    QPushButton *mainMenuButton;


public:
    explicit GameScene(Game *game,GuiView *parent = nullptr);
    QGraphicsRectItem *getGameSceneRect() const;

    /**
     * @brief prepare metoda odpowiedzialna za przerysowanie od nowa wszystkich elementów sceny które mogły ulec zmianie
     */
    void prepare();
    QLabel *getScore() const;
signals:
    void showMainMenu();
public slots:
    /**
     * @brief update metoda odpowiedzialna za aktualizację stanu graficznego
     */
    void update();
private slots:
    /**
     * @brief mainMenuButtonClicked metoda służąca do obsługi zdarzenia kliknięcia przycisku MainMenu w GUI
     */
    void mainMenuButtonClicked();
};

#endif // MAINMENUSCENE_H
