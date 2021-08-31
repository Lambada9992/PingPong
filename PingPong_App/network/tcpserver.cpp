#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{

}

void TcpServer::startServer(quint16 port)
{
    if(!this->listen(QHostAddress::Any,port)){
        qDebug() << "Server failed to start";
    }else{
        qDebug() << "Server started";
    }
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << " New connection with socket descriptor: " << socketDescriptor;
    SocketHandler *socketHandler = new SocketHandler(socketDescriptor,this);
    connect(socketHandler,SIGNAL(finished()),socketHandler,SLOT(deleteLater()));
    socketHandler->start();
}
