#ifndef BALL_H
#define BALL_H

#include "paddle.h"

#include <QPoint>

class Game;

/**
 * @brief The Ball class klasa odpowiedzialna za reprezentacje logiki piłeczki w grze
 */
class Ball
{
private:
    Game *game;
    QPointF position;
    QPointF velocity;
    int size = 14;
    double speed;

    Paddle *parent;

public:

    /**
     * @brief Ball konstruktor
     * @param game wskaźnik na grę reprezentującą całą logikę aplikacji
     */
    Ball(Game *game);

    /**
     * @brief move metoda odpowiedzialna za wykonanie ruchu piłeczki
     * @param dt czas ruchu jaki ma zostać wykonany
     * @param point parametr przez który jest zwracana informacja czy piłka wypadła poza pole rozgrywki
     */
    void move(double dt,bool &point);
    /**
     * @brief getAngle metoda zwracająca kąt w którym kólka się porusza
     * @return kąt w radianach
     */
    double getAngle();

    /**
     * @brief setVelocityByAngle metoda ustawiająca prędkość pod danym kątem
     * @param angle kąt w radianach
     */
    void setVelocityByAngle(double angle);
    /**
     * @brief randomVelocity metoda losująca kąt poruszania piłki
     * @param angle maksymalny kąt odchylenia od osi poziomej
     */
    void randomVelocity(double angle);


    //gettery i settery
    QPointF getPosition() const;
    void setPosition(const QPoint &value);

    int getSize() const;

    Paddle *getParent() const;
    void setParent(Paddle *value);

    void setSpeed(double value);
};

#endif // BALL_H
