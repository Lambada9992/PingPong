#ifndef PADDLE_H
#define PADDLE_H

#include <QPoint>

class Game;

class Paddle
{
public:
    enum Direction{UP,NONE,DOWN};
private:
    Game *game;
    QPointF position;
    double size;
    double speed = 200;
    Direction direction = NONE;

public:
    Paddle(Game *game, QPointF position, double size);

    void move(double dt);
    QPointF getPosition() const;
    void setPosition(const QPoint &value);

    double getSize() const;

    Direction getDirection() const;
    void setDirection(const Direction &value);
};

#endif // PADDLE_H
