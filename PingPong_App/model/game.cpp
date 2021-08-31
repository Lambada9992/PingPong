#include "game.h"

#include <qthread.h>
#include <QDebug>

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
        //QThread::msleep(500);

        mutex.lock();
        if(!isLive)break;
        mutex.unlock();
    }
}


void Game::makeMoves(long double dt)
{
    this->ball->move(dt);
    for(int i=0;i<this->padles->size();i++){
        (*this->padles)[i]->move();
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

Ball *Game::getBall() const
{
    return ball;
}

Game::Game():
    board(0,0,800,800)
{
    this->ball = new Ball(this);
    this->padles = new QList<Paddle *>();
}

Game::~Game()
{
    delete this->ball;
    while (padles->size() != 0) {
        delete this->padles->takeFirst();

    }
    delete this->padles;
}
