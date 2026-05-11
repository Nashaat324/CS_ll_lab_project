#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <QWidget>
#include "INetworkClient.h"
#include "ServerLogic/ServerLogic.h"

namespace Ui {
class technician;
}

class technician : public QWidget
{
    Q_OBJECT

public:
    explicit technician(INetworkClient* net, ServerLogic *l, int adminId, QWidget *parent = nullptr);
    ~technician();
    void setClientName(const QString &name);
    void setTechName(const QString &name);

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_2_endChat_clicked();

    void onReadyRead();               // To receive messages

private:
    Ui::technician *ui;
    INetworkClient *network;
    ServerLogic *logic; // This stores the connection to the server
    int myAdminId;      // This stores who is logged in
    QString myName;
    QString clientName = "Client";
    void refreshChat();

};

#endif // TECHNICIAN_H
