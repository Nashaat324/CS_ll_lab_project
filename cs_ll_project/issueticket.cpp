#include "issueticket.h"
#include "ui_issueticket.h"

IssueTicket::IssueTicket(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IssueTicket)
{
    ui->setupUi(this);
}

IssueTicket::~IssueTicket()
{
    delete ui;
}
