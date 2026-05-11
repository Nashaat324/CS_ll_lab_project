#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "INetworkClient.h"
#include "ServerLogic/ServerLogic.h"


namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(INetworkClient* net=nullptr, ServerLogic* log=nullptr, QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginPage *ui;
    INetworkClient* network;
    ServerLogic* logic;
};

#endif // LOGINPAGE_H
