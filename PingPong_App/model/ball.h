#ifndef BALL_H
#define BALL_H

#include "paddle.h"

#include <QPoint>

class Game;

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

    Ball(Game *game);

    void move(double dt,bool &point);
    double getAngle();

    void setVelocityByAngle(double angle);

    QPointF getPosition() const;
    void setPosition(const QPoint &value);

    void randomVelocity(double angle);
    int getSize() const;

    Paddle *getParent() const;
    void setParent(Paddle *value);

};

#endif // BALL_H
