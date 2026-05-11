#include "loginpage.h"
#include "ui_loginpage.h"
#include "issueticket.h"

LoginPage::LoginPage(INetworkClient* net, ServerLogic* log, QWidget *parent)
    : QDialog(parent)
    ,network(net)
    , ui(new Ui::LoginPage)
    ,logic(log)

{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}







void LoginPage::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    int id = 1;
    hide();
    IssueTicket *it = new IssueTicket(this->network, this->logic, id);
    it->show();
    this->hide();
}





