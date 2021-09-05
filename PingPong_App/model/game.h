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

#include <network/tcpserver.h>


class Game : public QThread
{
    Q_OBJECT
public:
    enum Side{LEFT=0,RIGHT=1};
private:
    QRect board;
    bool isLive = false;
    QMutex mutex;
    Ball *ball;
    QList<Paddle *> *padles;
    QPair<int,int> score;

    //NETWORK
    TcpServer server;
    qintptr port = 1234;

public:
    Game();
    ~Game();

    void startGame();
    void stopGame();

    void startServer();
    void stopServer();

    void shot(Side side);

    QRect getBoard() const;
    QList<Paddle *> *getPadles() const;
    Ball *getBall() const;
    QMutex getMutex() const;
    Paddle *getPadle(Side side) const;
    Side getSide(Paddle *paddle);
    void setBoardSizeX(int value);
    void setBoardSizeY(int value);
    void prepareGame();
private:
    void makeMoves(long double dt);
    void scorePoint();
public slots:
    void interpreteMessage(QString message);

signals:
    void updateGui();


    // QThread interface
protected:
    void run();
};

#endif // GAME_H
