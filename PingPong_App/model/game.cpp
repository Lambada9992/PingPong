#include "game.h"

#include <qthread.h>
#include <QDebug>
#include <QKeyEvent>

void Game::startGame()
{
    this->start();
}

void Game::stopGame()
{
    mutex.lock();
    this->isLive = false;
    mutex.unlock();
}

void Game::prepareGame()
{
    this->score.first = 0;
    this->score.second = 0;
    this->ball->setPosition(this->board.center());
    this->ball->randomVelocity(45);
}

void Game::run()
{
    this->isLive = true;
    auto lastTime = std::chrono::high_resolution_clock::now();
    this->prepareGame();
    while (true) {
        auto dt = std::chrono::high_resolution_clock::now() - lastTime;
        lastTime = std::chrono::high_resolution_clock::now();
        long double dtns = ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count())/1000000000;   //time in s
        makeMoves(dtns);
        emit updateGui();
        //QThread::msleep(100);

        mutex.lock();
        if(!isLive)break;
        mutex.unlock();
    }
}


void Game::makeMoves(long double dt)
{
    this->ball->move(dt);
    for(int i=0;i<this->padles->size();i++){
        //(*this->padles)[i]->move(0);
    }
}

QRect Game::getBoard() const
{
    return board;
}

QList<Paddle *> *Game::getPadles() const
{
    return padles;
}
Paddle *Game:: getPadle(int i) const
{
    return (*this->padles)[i];
}

Ball *Game::getBall() const
{
    return ball;
}

Game::Game():
    board(0,0,800,600)
{
    this->ball = new Ball(this);
    this->padles = new QList<Paddle *>();
    this->padles->append(new Paddle(this, QPointF(0,board.height()/2), board.height()/4));
    this->padles->append(new Paddle(this, QPointF(board.width()-1,board.height()/2), board.height()/4));
}

Game::~Game()
{
    delete this->ball;
    while (padles->size() != 0) {
        delete this->padles->takeFirst();

    }
    delete this->padles;
}

void Game::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
            {
                case Qt::Key_Space:
                {
                qDebug() << "space" ;
                this->getPadle(1)->move(0);
                }
                break;
             }
}

