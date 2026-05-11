#ifndef TECHWINDOW_H
#define TECHWINDOW_H

#include <QWidget>
#include "ServerLogic/ServerLogic.h"
#include <QJsonObject>
#include "INetworkClient.h"

namespace Ui {
class techWindow;
}

class techWindow : public QWidget
{
    Q_OBJECT

public:
    explicit techWindow(QWidget *parent = nullptr);
    ~techWindow();

private slots:
    void on_acceptTicket_clicked();

private:
    Ui::techWindow *ui;
    ServerLogic *logic; // Add a pointer to your logic class
    int myAdminId;      // Store the logged-in tech's ID
    INetworkClient* network;
};

#endif // TECHWINDOW_H
