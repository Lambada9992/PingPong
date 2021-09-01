#include "tcpserver.h"

QList<SocketHandler *> *TcpServer::getHandlers() const
{
    return handlers;
}

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
    this->handlers = new QList<SocketHandler *>();
}

TcpServer::~TcpServer()
{
    delete this->handlers;
}

void TcpServer::startServer(quint16 port)
{
    this->close();
    if(!this->listen(QHostAddress::Any,port)){
        qDebug() << "Server failed to start";
    }else{
        qDebug() << "Server started";
    }
}

void TcpServer::stopServer()
{
    this->close();
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << " New connection with socket descriptor: " << socketDescriptor;
    SocketHandler *socketHandler = new SocketHandler(socketDescriptor,this);
    handlers->append(socketHandler);
    connect(socketHandler,SIGNAL(finished()),socketHandler,SLOT(deleteLater()));
    connect(socketHandler,SIGNAL(messageToInterprete(QString)),this,SLOT(interpreteMessage(QString)),Qt::DirectConnection);
    socketHandler->start();
}

void TcpServer::interpreteMessage(QString message)
{
    messageToInterprete(message);
}
