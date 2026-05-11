#include <QMessageBox>
#include "loginpage.h"
#include "ui_loginpage.h"
#include "issueticket.h"
#include "techwindow.h"

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

    this->hide();
}





