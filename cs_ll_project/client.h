#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include "INetworkClient.h"

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(INetworkClient* net,
             QWidget *parent = nullptr);
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
};

#endif
