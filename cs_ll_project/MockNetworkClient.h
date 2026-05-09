#ifndef MOCKNETWORKCLIENT_H
#define MOCKNETWORKCLIENT_H

#include <gmock/gmock.h>
#include "INetworkClient.h"

class MockNetworkClient : public INetworkClient
{
public:

    MOCK_METHOD(
        void,
        connectToServer,
        (const QString& host, int port),
        (override)
        );

    MOCK_METHOD(
        void,
        sendData,
        (const QByteArray& data),
        (override)
        );

    MOCK_METHOD(
        QByteArray,
        receiveData,
        (),
        (override)
        );
    MOCK_METHOD(QTcpSocket*, getSocket, (), (override));
};

#endif // MOCKNETWORKCLIENT_H
