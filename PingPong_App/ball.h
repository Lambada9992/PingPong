#ifndef BALL_H
#define BALL_H

#include <QPoint>

class Ball
{
public:

    Ball();

    void getPositionX();
    void getPositionY();
    void move();

private:

    QPoint position;


};

#endif // BALL_H
