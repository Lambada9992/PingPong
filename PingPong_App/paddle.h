#ifndef PADDLE_H
#define PADDLE_H

#include <QPoint>

class Game;

class Paddle
{
private:
    Game *game;
    QPoint position;
    int size;

public:
    Paddle(Game *game);

    void move();
    QPoint getPosition() const;
    void setPosition(const QPoint &value);

};

#endif // PADDLE_H
