#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QThread>
#include <QTcpSocket>

class SocketHandler : public QThread
{
    Q_OBJECT
private:
    qintptr socketDescriptor;
    QTcpSocket *socket;
public:
    SocketHandler(qintptr socketDescriptor, QObject *parent = nullptr);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();
};

#endif // SOCKETHANDLER_H
