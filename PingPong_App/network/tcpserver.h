#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

#include "sockethandler.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
private:

    QList<SocketHandler *> *handlers;
public:
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();
    void startServer(quint16 port);
    void stopServer();

    QList<SocketHandler *> *getHandlers() const;

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public slots:
    void interpreteMessage(QString message);


signals:
    void messageToInterprete(QString message);

};

#endif // TCPSERVER_H
