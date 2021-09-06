#ifndef GUI_BOARD_H
#define GUI_BOARD_H

class Gui_Paddle;
#include "MODEL/game.h"
#include "gui_ball.h"
#include <qgraphicsscene.h>
#include "QDebug"

/**
 * @brief The Gui_board class klasa odpowiedzialna za wyświetlanie pola rozgrywki
 */
class Gui_board :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Gui_board(Game *game,QObject *object = nullptr,QGraphicsItem *parent = nullptr);

private:
    Game *game;
    Gui_ball *gui_ball;
    QList<Gui_Paddle *> gui_padles;

public slots:
    /**
     * @brief update metoda odpowiedzilna za aktualizację graficznego stanu rozgrywki
     */
    void update();
    /**
     * @brief prepare metoda odpowiedzialna za przerysowanie elementów graficznych gry na nowo
     */
    void prepare();
};

#endif // GUI_BOARD_H
