#include "techwindow.h"
#include "ui_techwindow.h"
#include "technician.h"
#include <QJsonObject>

techWindow::techWindow(INetworkClient* net, ServerLogic* log, int adminId, QString adminName, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::techWindow)
    , network(net)
    , logic(log)
    , myAdminId(adminId)

{
    ui->setupUi(this);
    myAdminName = adminName;
}

techWindow::~techWindow()
{
    delete ui;
}

void techWindow::on_acceptTicket_clicked()
{
    // 1. Get the data from the server
    qDebug() << "--- ACCEPT BUTTON CLICKED! ---"; // Add this
    QJsonObject ticketData = logic->acceptTicket(1);
    qDebug() << "FULL TICKET DATA FROM SERVER:" << ticketData;

    if (ticketData["status"].toString() == "success") {
        // Create the chat window and pass 'logic' and 'myAdminId'
        // These match the 'ServerLogic *l' and 'int adminId' in your constructor
        QString realEmployeeName = ticketData["user"].toString();


        if(realEmployeeName.isEmpty()) {
            qDebug() << "WARNING: Server didn't send an employee name in ticketData!";
            realEmployeeName = "mohamed"; // Temporary fallback for testing
        }
        technician *chat = new technician(this->network, this->logic, this->myAdminId);

        chat->setClientName(realEmployeeName); // So we know WHO we are helping
        chat->setTechName(myAdminName); // So the chat knows WHO we are

        chat->show();
        this->hide();
    }
}

