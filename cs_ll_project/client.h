#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include "INetworkClient.h"
#include "ServerLogic/ServerLogic.h"


namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(INetworkClient* net, ServerLogic *l, int id, QWidget *parent = nullptr);
    ~Client();

    void setTechnician(const QString& tech);
    void setUsername(const QString& name);

public slots:
    void on_send_clicked();
    void onReadyRead();
    void on_End_Chat_clicked();

private:
    Ui::Client *ui;
    INetworkClient* network;

    QString username;
    QString technician;

    ServerLogic *logic;
    int myId;

};

#endif
