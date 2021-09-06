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

    //GETERY I SETERY
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
    /**
     * @brief makeMoves Funkcja odpowiedzialna za wykonywanie ruchów w grze
     * @param dt czas ruchów do wykonania
     */
    void makeMoves(long double dt);
    /**
     * @brief scorePoint Metoda odpowiedzialna za przydzielenie punktów odpowiedniemu graczowi
     */
    void scorePoint();
    /**
     * @brief checkScore metoda odpowiedzialna za sprawdzanie czy nie nastąpił koniec gry
     * @return zwraca informację czy gra się zakończyła
     */
    bool checkScore();
public slots:
    /**
     * @brief interpreteMessage metoda odpowiedzialna za interpretację wiadomości przychodzących do aplikacji
     * @param message wiadomość dostarczona przez TCP
     */
    void interpreteMessage(QString message);

signals:
    /**
     * @brief updateGui sygnał informujący Gui o tym że powinno zostać zaktualizowane
     */
    void updateGui();


    // QThread interface
protected:
    /**
     * @brief run wykonywanie ruchów w grze na oddzielnym wątku
     */
    void run();
};

#endif // GAME_H
