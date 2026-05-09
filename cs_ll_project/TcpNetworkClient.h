#ifndef TCPNETWORKCLIENT_H
#define TCPNETWORKCLIENT_H

#include "INetworkClient.h"
#include <QTcpSocket>

class TcpNetworkClient : public INetworkClient
{
private:
    QTcpSocket socket;

public:

    void connectToServer(
        const QString& host,
        int port
        ) override
    {
        socket.connectToHost(host, port);
    }

    void sendData(
        const QByteArray& data
        ) override
    {
        socket.write(data);
    }

    QByteArray receiveData() override
    {
        return socket.readAll();
    }
    QTcpSocket* getSocket() override { return &socket; }
};

#endif
