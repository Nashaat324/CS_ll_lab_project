#ifndef INETWORKCLIENT_H
#define INETWORKCLIENT_H

#include <QTcpSocket>
#include <QString>
#include <QByteArray>

class INetworkClient
{
public:
    virtual ~INetworkClient() {}

    virtual void connectToServer(const QString& host, int port) = 0;
    virtual void sendData(const QByteArray& data) = 0;
    virtual QByteArray receiveData() = 0;
    virtual QTcpSocket* getSocket() = 0;
};

#endif // INETWORKCLIENT_H
