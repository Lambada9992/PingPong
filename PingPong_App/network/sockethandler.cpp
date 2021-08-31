#include "sockethandler.h"

SocketHandler::SocketHandler(qintptr socketDescriptor, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
}

void SocketHandler::run()
{
    qDebug() << "starting new thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    exec();
}

void SocketHandler::readyRead()
{
    QByteArray data = socket->readAll();
    socket->write(data);
    qDebug() << data;
    socket->flush();
}

void SocketHandler::disconnected()
{
    socket->deleteLater();
    exit(0);
}
