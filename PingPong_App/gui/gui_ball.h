#ifndef GUI_BALL_H
#define GUI_BALL_H

#include <QGraphicsEllipseItem>
#include "model/ball.h"

/**
 * @brief The Gui_ball class klasa odpowiedzialna za reprezentację graficzną piłeczki z gry
 */
class Gui_ball : public QGraphicsPixmapItem
{
public:
    Gui_ball(Ball *ball,QGraphicsItem *parent = nullptr);
    /**
     * @brief updatePosition aktualizacja pozycji piłeczki
     */
    void updatePosition();

private:
    Ball *ball;
    QPointF translationFromGlobal;

};

#endif // GUI_BALL_H
