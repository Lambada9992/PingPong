#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

#include "sockethandler.h"

/**
 * @brief The TcpServer class Klasa odpowiedzialna za nasłuchiwanie na danym porcie
 * W przypadku połączenia przychodzącego odbiera je oraz tworzy klasę na nowym wątku obsługującą połaczenie
 */
class TcpServer : public QTcpServer
{
    Q_OBJECT
private:

    QList<SocketHandler *> *handlers;
public:
    /**
     * @brief TcpServer Konstruktor
     * @param parent rodzic
     */
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();
    /**
     * @brief startServer Metoda odpowiedzilna za uruchomienie serwera
     * @param port port na którym serwer ma nasłuchiwać
     */
    void startServer(quint16 port);
    /**
     * @brief stopServer zamknięcie serwera / wyłączenie nasłuchiwana
     */
    void stopServer();

    // gettery
    QList<SocketHandler *> *getHandlers() const;

protected:
    /**
     * @brief incomingConnection metoda odpowiedzialna za obsługę przychodzących połączeń
     * @param socketDescriptor ID socketu
     */
    void incomingConnection(qintptr socketDescriptor) override;

public slots:
    /**
     * @brief interpreteMessage obsługa przychodzących wiadomości od klienta TCP
     * @param message wiadomość
     */
    void interpreteMessage(QString message);


signals:
    void messageToInterprete(QString message);

};

#endif // TCPSERVER_H
