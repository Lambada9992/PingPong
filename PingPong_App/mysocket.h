#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>

class MySocket : public QObject
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = nullptr);

signals:

};

#endif // MYSOCKET_H
