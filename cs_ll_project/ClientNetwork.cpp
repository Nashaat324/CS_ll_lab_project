#include "ClientNetwork.h"

ClientNetwork::ClientNetwork() {
    socket = new QTcpSocket();
}

void ClientNetwork::connectToServer(const QString& host, int port) {
    socket->connectToHost(host, port);
}

void ClientNetwork::sendData(const QByteArray& data) {
    if(socket->isOpen()) {
        socket->write(data);
        socket->flush(); // Ensure it actually leaves the buffer
    }
}

QByteArray ClientNetwork::receiveData() {
    return socket->readAll();
}

QTcpSocket* ClientNetwork::getSocket() {
    return socket;
}
