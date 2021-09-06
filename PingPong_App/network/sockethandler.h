#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QThread>
#include <QTcpSocket>

/**
 * @brief The SocketHandler class Klasa odpowiedzialna za obsługę sockety TCP
 * Działa na oddzielnym wątku, i obsługuje infromacje przychodzące do aplikacji
 */
class SocketHandler : public QThread
{
    Q_OBJECT
private:
    qintptr socketDescriptor;
    QTcpSocket *socket;
public:
    /**
     * @brief SocketHandler kostruktor
     * @param socketDescriptor socket descrtiptor na podstawie którego otrzyjmujemy odpowiedni socket
     * @param parent rodzic
     */
    SocketHandler(qintptr socketDescriptor, QObject *parent = nullptr);

    /**
     * @brief run metoda odpowiedzialna za prace na nowym wątku
     */
    void run() override;

signals:
    void error(QTcpSocket::SocketError socketerror);
    void messageToInterprete(QString message);
public slots:
    /**
     * @brief readyRead metoda obsługująca przychodzące wiadomości
     */
    void readyRead();
    /**
     * @brief disconnected metoda obsługująca rozłączenie się klienta TCP
     */
    void disconnected();
};

#endif // SOCKETHANDLER_H
