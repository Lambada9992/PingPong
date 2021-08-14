#ifndef MYSERVERSOCKET_H
#define MYSERVERSOCKET_H

#include <QObject>

class MyServerSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyServerSocket(QObject *parent = nullptr);

signals:

};

#endif // MYSERVERSOCKET_H
