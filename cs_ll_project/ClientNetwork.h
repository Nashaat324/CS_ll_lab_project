#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H

#include "INetworkClient.h"

class ClientNetwork : public INetworkClient {
public:
    ClientNetwork();
    void connectToServer(const QString& host, int port) override;
    void sendData(const QByteArray& data) override;
    QByteArray receiveData() override;
    QTcpSocket* getSocket() override;

private:
    QTcpSocket* socket;
};

#endif // CLIENTNETWORK_H
