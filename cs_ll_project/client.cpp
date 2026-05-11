#include "client.h"
#include "FeedbackPage.h"
#include "ui_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
//#include <boost/json.hpp>

Client::Client(INetworkClient* net, ServerLogic *l, int id, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
    , network(net)
    , logic(l)
    , myId(id)
{
    ui->setupUi(this);

    network = net;

    if (network->getSocket()) {
        connect(network->getSocket(), &QTcpSocket::readyRead,
                this, &Client::onReadyRead);
    }

    network->connectToServer(
        "127.0.0.1",
        54321
        );
}

Client::~Client()
{
    delete ui;
}

void Client::setTechnician(const QString &tech)
{
    technician = tech;
    ui->label_2->setText("Chat with " + tech);
}

void Client::setUsername(const QString &name)
{
    username = name;
}

void Client::on_send_clicked()
{
    QString msg = ui->type->text();
    if (msg.isEmpty()) {
        //QMessageBox::critical(this, "Error", "Message is empty");
        return;
    }

    QString timestamp = QDateTime::currentDateTime().toString(Qt::ISODate);

    QJsonObject json;
    json["type"] = "chat_message";
    json["from"] = username;
    json["to"] = technician;
    json["message"] = msg;
    json["timestamp"] = timestamp;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    network->sendData(data);
    qDebug() << "SENT TO SERVER:" << data;
    ui->screen->addItem("Me: " + msg + "\nTime: " + timestamp);
    ui->type->clear();
}

void Client::onReadyRead()
{
    QByteArray data = network->receiveData();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    if (obj.contains("status")) {

        QString status = obj["status"].toString();
        ui->screen->addItem("System: Message " + status + "!");
    } else {

        ui->screen->addItem("Server: " + QString(data));
    }

}




void Client::on_End_Chat_clicked()
{
    // 1. Ask for confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "End Session", "Has your issue been resolved?");

    if (reply == QMessageBox::Yes) {
        // 2. Tell the server to save this specific chat to the history

        if(logic != nullptr) {
            logic->archiveTicket(myId);
        }

        // 3. Notify the Server via Network
        QJsonObject json;
        json["type"] = "session_end";
        json["userId"] = myId;
        network->sendData(QJsonDocument(json).toJson(QJsonDocument::Compact));

        this->hide();
        FeedbackPage* FP = new FeedbackPage(nullptr, this->logic, this->myId);
        FP->show();
}
}
