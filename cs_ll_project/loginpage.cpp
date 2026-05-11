#include <QMessageBox>
#include "loginpage.h"
#include "ui_loginpage.h"
#include "issueticket.h"
#include "techwindow.h"

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
<<<<<<< HEAD
    int id = 1;
    hide();
    IssueTicket *it = new IssueTicket(this->network, this->logic, id);
    it->show();
=======
    QString password = ui->passwordLineEdit->text();
    QString role = ui->roleComboBox->currentText();

    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter username and password");
        return;
    }

    if(role == "Employee")
    {
        IssueTicket *ticketWindow = new IssueTicket();
        ticketWindow->show();
    }
    else if(role == "Technician")
    {
        TechWindow *techWindow = new TechWindow();
        techWindow->show();
    }

>>>>>>> Update-Login
    this->hide();
}





