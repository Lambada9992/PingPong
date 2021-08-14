#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QObject>

class SocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit SocketHandler(QObject *parent = nullptr);

signals:

};

#endif // SOCKETHANDLER_H
