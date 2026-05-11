#include "technician.h"
#include "ui_technician.h"
#include <QJsonObject>
#include <QJsonDocument>


technician::technician(INetworkClient* net, ServerLogic *l, int adminId,  QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::technician),
    network(net),
    logic(l),           // Link the logic
    myAdminId(adminId)   // Save the ID
{
    ui->setupUi(this);
    // Connect the socket to this window's receiver
    if (network && network->getSocket()) {
        connect(network->getSocket(), &QTcpSocket::readyRead, this, &technician::onReadyRead);
    }
}

technician::~technician()
{
    delete ui;
}

void technician::on_pushButton_send_clicked()
{
    QString msg = ui->lineEdit_message->text();
    if (msg.isEmpty()) return;

    QJsonObject json;
    json["type"] = "chat_message";
    json["from"] = "Technician"; // The server uses this to route back to the client
    json["message"] = msg;

    network->sendData(QJsonDocument(json).toJson(QJsonDocument::Compact));

    ui->chatDisplay->addItem("Me: " + msg);
    ui->lineEdit_message->clear();
}



void technician::onReadyRead() {
    QByteArray data = network->receiveData();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    if (obj["type"].toString() == "chat_message") {
        QString sender = obj["from"].toString();
        QString message = obj["message"].toString();

        ui->chatDisplay->addItem(sender + ": " + message);

        // Update local logic for history/archiving
        if(logic) logic->processChatMessage(myAdminId, sender, message);
    }
}

void technician::on_pushButton_2_endChat_clicked()
{

    this->close();
}


