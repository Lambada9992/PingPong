#ifndef PADDLE_H
#define PADDLE_H

#include <QPoint>

class Paddle
{
public:
    Paddle(int x, int y, int w, int h);

    int getPositionX();
    int getPositionY();
    void move(int direction);
private:
    QPoint position;

    int widht;
    int height;

    int speed;

};

#endif // PADDLE_H
