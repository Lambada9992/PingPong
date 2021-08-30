#ifndef BALL_H
#define BALL_H

#include <QPoint>

class Game;

class Ball
{
private:
    Game *game;
    QPoint position;
    QPointF velocity;
    int speed;


public:

    Ball(Game *game);

    void move(double dt);

    QPoint getPosition() const;
    void setPosition(const QPoint &value);

    void randomVelocity(double angle);

};

#endif // BALL_H
