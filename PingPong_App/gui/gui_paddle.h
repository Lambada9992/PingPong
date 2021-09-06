#ifndef GUI_PADDLE_H
#define GUI_PADDLE_H

#include "MODEL/game.h"
#include <QGraphicsItem>

/**
 * @brief The Gui_Paddle class klasa odpowiedzialna za reprezentacje graficzną paletki z gry
 */
class Gui_Paddle:public QGraphicsPixmapItem
{
public:
    Gui_Paddle(Paddle *paddle, QString color, QGraphicsItem *parent = nullptr);
    /**
     * @brief updatePosition odswiezenie pozycji paletki
     */
    void updatePosition();
    /**
     * @brief prepare stworzenie wyglądu paletki na nowo
     */
    void prepare();
private:
    Paddle *paddle;
    Game::Side side;
    QString color;
};

#endif // GUI_PADDLE_H
