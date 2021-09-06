#ifndef PADDLE_H
#define PADDLE_H

#include <QPoint>

class Game;

/**
 * @brief The Paddle class Klasa reprezentująca logikę paletki w grze
 */
class Paddle
{
public:
    /**
     * @brief The Direction enum kierunek ruchu paletki
     */
    enum Direction{UP,NONE,DOWN};
private:
    Game *game;
    QPointF position;
    double size;
    double width = 15;
    double speed = 400;
    Direction direction = NONE;

public:
    /**
     * @brief Paddle konstruktor
     * @param game wskaźnik na klasę game przechowującą logikę całej aplikacji
     * @param position pozycja początkowa paletki
     * @param size wysokość paletki
     */
    Paddle(Game *game, QPointF position, double size);

    /**
     * @brief move wykonanie ruchu paletki
     * @param dt czas ruchu do wykonania
     */
    void move(double dt);

    //Gettery i settery
    QPointF getPosition() const;
    void setPosition(const QPoint &value);

    double getSize() const;

    Direction getDirection() const;

    void setDirection(const Direction &value);
    void setSize(double value);
    double getWidth() const;
    void setSpeed(double value);
};

#endif // PADDLE_H
