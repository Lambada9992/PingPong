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

/**
 * @brief The Game class odpowiedzialna za całą logikę aplikacji
 * Klasa ta odpowiedzialna jest za przeprowadzanie całej logiki rozgrywki
 * jak też odpierania połączenia TCP, utrzymwania go oraz interpretowania wiadomosc
 * Dziedziczy po QThread dzięki czemu sama rozgrywa odbywa się na oddzielnym wątku
 */
class Game : public QThread
{
    Q_OBJECT
public:
    enum Side{LEFT=0,RIGHT=1};
private:
    QRect board;
    bool isLive = false;
    bool isFinished = false;
    QMutex mutex;
    Ball *ball;
    QList<Paddle *> *padles;
    QPair<int,int> score;
    int maxScore;

    //NETWORK
    TcpServer server;
    qintptr port = 1234;


public:
    /**
     * @brief Game constructor
     */
    Game();
    ~Game();

    /**
     * @brief startGame metoda odpowiedzialna za wystartowanie rozgrywki
     *
     */
    void startGame();
    /**
     * @brief stopGame metoda odpowiedzialna za wstrzymanie rozgrywki
     */
    void stopGame();

    /**
     * @brief startServer metoda odpalająca serwer na porcie 1234 który oczekuje na połączenia TCP
     */
    void startServer();
    /**
     * @brief stopServer wyłączenie serwera
     */
    void stopServer();

    /**
     * @brief shot chęć wykonania strzłu przez jedną ze stron
     * (w sytuacji w której piłka przyczepiona jest do paletki wykonywany jest strzał)
     * @param side informacja która paletka chce wykonać strzał
     */
    void shot(Side side);
    /**
     * @brief prepareGame metoda służąca do przygotowania rozgrywki (ustawienie piłki oraz paletek na planszy)
     */
    void prepareGame();

    void setPaddleSpeed(double value);
    void setPaddleSize(double value);
    void setBallSpeed(double value);

    QRect getBoard() const;
    QList<Paddle *> *getPadles() const;
    Ball *getBall() const;
    QMutex getMutex() const;
    Paddle *getPadle(Side side) const;
    Side getSide(Paddle *paddle);
    void setBoardSizeX(int value);
    void setBoardSizeY(int value);

    QPair<int, int> getScore() const;

    void setMaxScore(int value);

    int getMaxScore() const;

    bool getIsFinished() const;

    void setIsFinished(bool value);


private:
    void makeMoves(long double dt);
    void scorePoint();
    bool checkScore();
public slots:
    void interpreteMessage(QString message);

signals:
    void updateGui();


    // QThread interface
protected:
    void run();
};

#endif // GAME_H
