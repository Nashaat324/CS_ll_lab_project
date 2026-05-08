#include "client.h"
#include "FeedbackPage.h"
#include "ui_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <boost/json.hpp>

Client::Client(INetworkClient* net,
               QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    network = net;

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
    qDebug() << "FROM SERVER:" << data;
    ui->screen->addItem("Server: " + QString(data));
}




void Client::on_End_Chat_clicked()
{
    hide();
    FeedbackPage* FP = new FeedbackPage(this);
    FP->show();
}

