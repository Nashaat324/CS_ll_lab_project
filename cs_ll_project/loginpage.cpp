#include <QMessageBox>
#include "loginpage.h"
#include "ui_loginpage.h"
#include "issueticket.h"
#include "techwindow.h"


LoginPage::LoginPage(INetworkClient* net, ServerLogic* log, QWidget *parent)
    : QDialog(parent)

    , ui(new Ui::LoginPage)
    ,network(net)
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
    QString password = ui->passwordLineEdit->text();
    QString role = ui->comboBox_role->currentText();
    int id = 1;



    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter username and password");
        return;
    }

    if(role == "Employee")
    {
        IssueTicket *it = new IssueTicket(this->network, this->logic, id);
        it->setUsername(username);
        it->show();
        this->hide();
    }
    else if(role == "Technician")
    {
        QString nameFromBox = ui->usernameLineEdit->text();
        techWindow *tw = new techWindow(this->network, this->logic, id, nameFromBox);
        tw->show();
        this->hide();

    }

}





