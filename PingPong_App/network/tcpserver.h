#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

#include "sockethandler.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
private:

public:
    explicit TcpServer(QObject *parent = nullptr);
    void startServer(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public slots:

signals:

};

#endif // TCPSERVER_H
