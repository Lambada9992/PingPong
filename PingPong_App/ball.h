#ifndef BALL_H
#define BALL_H

#include <QPoint>

class Ball
{
public:

    Ball(int x, int y, int w, int h);

    int getPositionX();
    int getPositionY();
    void move(int direction);


private:

    QPoint position;

    int widht;
    int height;

    int speed;


};

#endif // BALL_H
