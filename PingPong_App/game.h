#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "paddle.h"

#include <QObject>
#include <QList>
#include <QRect>

class Game : public QObject
{
    Q_OBJECT
private:
    QRect board;
    bool isLive = false;
    Ball *ball;
    QList<Paddle *> *padles;
    QPair<int,int> score;

public:
    Game();
    ~Game();
    void startGame();
    void stopGame();

    QRect getBoard() const;

    QList<Paddle *> *getPadles() const;

private:
    void makeMoves(long double dt);
    void prepareGame();

signals:
    void updateGui();

};

#endif // GAME_H
