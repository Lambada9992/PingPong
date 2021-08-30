#include "game.h"

void Game::startGame()
{
    this->isLive = true;
    auto lastTime = std::chrono::high_resolution_clock::now();
    this->prepareGame();

    while (isLive) {
        auto dt = std::chrono::high_resolution_clock::now() - lastTime;
        lastTime = std::chrono::high_resolution_clock::now();
        long double dtns = ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count())/1000000;      //time in s
        makeMoves(dtns);
        emit updateGui();
    }
}

void Game::stopGame()
{
    this->isLive = false;
}

void Game::prepareGame()
{
    this->score.first = 0;
    this->score.second = 0;
    this->ball->setPosition(this->board.center());
    this->ball->randomVelocity(45);
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
