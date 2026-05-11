#include "techwindow.h"
#include "ui_techwindow.h"
#include "technician.h"
#include <QJsonObject>

techWindow::techWindow(INetworkClient* net, ServerLogic* log, int adminId, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::techWindow)
    , network(net)
    , logic(log)
    , myAdminId(adminId)

{
    ui->setupUi(this);
}

techWindow::~techWindow()
{
    delete ui;
}

void techWindow::on_acceptTicket_clicked()
{
    // 1. Get the data from the server
    QJsonObject ticketData = logic->acceptTicket(myAdminId);

    if (ticketData["status"].toString() == "success") {
        // Create the chat window and pass 'logic' and 'myAdminId'
        // These match the 'ServerLogic *l' and 'int adminId' in your constructor
        technician *chat = new technician(this->network, this->logic, this->myAdminId, nullptr);


        chat->show();
        this->hide();
    }
}

