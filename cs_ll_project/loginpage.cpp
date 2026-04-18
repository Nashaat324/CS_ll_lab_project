#include "loginpage.h"
#include "ui_loginpage.h"
#include "issueticket.h"

LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
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

    hide();
    IssueTicket* issuetick = new IssueTicket(nullptr);
    issuetick->setUsername(username);
    issuetick -> show();
}





