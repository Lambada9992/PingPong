#ifndef PADDLE_H
#define PADDLE_H

#include <QPoint>

class Game;

class Paddle
{
private:
    Game *game;
    QPointF position;
    double size;


public:
    Paddle(Game *game, QPointF position, double size);

    void move(int direction);
    QPointF getPosition() const;
    void setPosition(const QPoint &value);

    double getSize() const;

};

#endif // PADDLE_H
