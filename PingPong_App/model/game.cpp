#include "game.h"

#include <qthread.h>
#include <QDebug>
#include <QKeyEvent>
#include <QtMath>

Game::Game():
    board(0,0,800,200)
{
    this->ball = new Ball(this);
    this->padles = new QList<Paddle *>();
    this->padles->append(new Paddle(this, QPointF(0,board.height()/2), board.height()/8));
    this->padles->append(new Paddle(this, QPointF(board.width()-1,board.height()/2), board.height()/8));
    connect(&server,SIGNAL(messageToInterprete(QString)),this,SLOT(interpreteMessage(QString)),Qt::QueuedConnection);
    startServer();
}

void Game::startGame()
{
    this->getPadle(Game::LEFT)->setPosition(QPoint(0, board.height()/2));
    this->getPadle(Game::RIGHT)->setPosition(QPoint(board.width()-1,board.height()/2));
    this->start();

}

void Game::stopGame()
{
    mutex.lock();
    this->isLive = false;
    mutex.unlock();
}

void Game::startServer()
{
    server.startServer(port);
}

void Game::stopServer()
{
    server.close();
}

void Game::shot(Game::Side side)
{
    Paddle *parent = this->ball->getParent();
    if(parent == NULL) return;
    Side parentSide = getSide(parent);
    if(side != parentSide) return;

    switch(side){
    case Game::LEFT:{
        if(parent->getDirection() == Paddle::UP){
            ball->setVelocityByAngle(qDegreesToRadians(30.0));
        }
        if(parent->getDirection() == Paddle::DOWN){
            ball->setVelocityByAngle(qDegreesToRadians(-30.0));
        }
        if(parent->getDirection() == Paddle::NONE){
            ball->setVelocityByAngle(qDegreesToRadians(0.0));
        }
    }
        break;
    case Game::RIGHT:{
        if(parent->getDirection() == Paddle::UP){
            ball->setVelocityByAngle(qDegreesToRadians(150.0));
        }
        if(parent->getDirection() == Paddle::DOWN){
            ball->setVelocityByAngle(qDegreesToRadians(210.0));
        }
        if(parent->getDirection() == Paddle::NONE){
            ball->setVelocityByAngle(qDegreesToRadians(180.0));
        }
    }
        break;
    }

    this->ball->setParent(NULL);
}

void Game::setPaddleSpeed(double value)
{
    this->getPadle(LEFT)->setSpeed(value);
    this->getPadle(RIGHT)->setSpeed(value);
}

void Game::setPaddleSize(double value)
{
    this->getPadle(LEFT)->setSize(value);
    this->getPadle(RIGHT)->setSize(value);
}

void Game::setBallSpeed(double value)
{
    this->ball->setSpeed(value);
}

void Game::prepareGame()
{
    this->score.first = 0;
    this->score.second = 0;
    this->ball->setPosition(this->board.center());
    this->ball->randomVelocity(45);
    this->getPadle(LEFT)->setPosition(QPoint(0,board.height()/2.0));
    this->getPadle(RIGHT)->setPosition(QPoint(board.width()-1,board.height()/2.0));
}

void Game::scorePoint()
{
    if(this->ball->getPosition().x()<= getBoard().width()/2){
        score.second++;
    }else{
        score.first++;
    }
    qDebug()<< score << " " << this->ball->getPosition();
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
        mutex.lock();
        if(!isLive)break;
        mutex.unlock();
    }
}


void Game::makeMoves(long double dt)
{
    bool point = false;
    this->ball->move(dt,point);
    if(point){
        scorePoint();
    }
    for(int i=0;i<this->padles->size();i++){
        (*this->padles)[i]->move(dt);
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
Paddle *Game:: getPadle(Side side) const
{
    return (*this->padles)[side];
}

Game::Side Game::getSide(Paddle *paddle)
{
    if(paddle == getPadle(LEFT)) return LEFT;
    if(paddle == getPadle(RIGHT)) return RIGHT;
    throw std::invalid_argument("Paddle not found.");
}

Ball *Game::getBall() const
{
    return ball;
}

void Game::setBoardSizeX(int value)
{
    board.setWidth(value);
}

void Game::setBoardSizeY(int value)
{
    board.setHeight(value);
}

Game::~Game()
{
    stopServer();
    delete this->ball;
    while (padles->size() != 0) {
        delete this->padles->takeFirst();

    }
    delete this->padles;
}

void Game::interpreteMessage(QString message)
{
    Paddle *paddle;
    Side side;
    if(message.startsWith("L")){
        paddle = getPadle(Game::LEFT);
        side = Game::LEFT;
    } else {
        paddle = getPadle(Game::RIGHT);
        side = Game::RIGHT;
    }

    if(message.contains("UP")){
        paddle->setDirection(Paddle::DOWN);
    }
    if(message.contains("DOWN")){
        paddle->setDirection(Paddle::UP);
    }
    if(message.contains("NONE")){
        paddle->setDirection(Paddle::NONE);
    }
    if(message.contains("SHOT")){
        shot(side);
    }

}


