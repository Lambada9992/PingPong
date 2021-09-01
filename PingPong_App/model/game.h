#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "paddle.h"

#include <QObject>
#include <QList>
#include <QRect>
#include <QThread>
#include <QMutex>
#include <QWidget>


class Game : public QThread
{
    Q_OBJECT
private:
    QRect board;
    bool isLive = false;
    QMutex mutex;
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

    Ball *getBall() const;

    QMutex getMutex() const;

    Paddle *getPadle(int i) const;
private:
    void makeMoves(long double dt);
    void prepareGame();
    void keyPressEvent(QKeyEvent *event);
signals:
    void updateGui();


    // QThread interface
protected:
    void run();
};

#endif // GAME_H
