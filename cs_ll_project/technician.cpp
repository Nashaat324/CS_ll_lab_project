#include "technician.h"
#include "ui_technician.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>
#include <QTimer>

technician::technician(INetworkClient* net, ServerLogic *log, int adminId,  QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::technician),
    network(net),
    logic(log),           // Link the logic
    myAdminId(adminId)   // Save the ID
{
    ui->setupUi(this);
    ui->label_2->setText("Chat with Client");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        ui->chatDisplay->clear();
        ui->chatDisplay->addItems(
            logic->getChatLog(1).split("\n", Qt::SkipEmptyParts)
            );
    });
    timer->start(500);

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


    logic->processChatMessage(1, "Technician", msg);

    ui->chatDisplay->clear();
    ui->chatDisplay->addItems(logic->getChatLog(1).split("\n", Qt::SkipEmptyParts));


    QJsonObject json;
    json["type"] = "chat_message";
    json["from"] = "Technician"; // The server uses this to route back to the client
    json["message"] = msg;

    network->sendData(QJsonDocument(json).toJson(QJsonDocument::Compact));


    ui->lineEdit_message->clear();
}



void technician::onReadyRead() {

    QByteArray data = network->receiveData();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isObject()) return;

    QJsonObject obj = doc.object();

    if (obj["type"].toString() == "chat_message") {
        QString sender = obj["from"].toString();
        QString message = obj["message"].toString();

        logic->processChatMessage(1, sender, message);

        ui->chatDisplay->clear();
        ui->chatDisplay->addItems(
            logic->getChatLog(1).split("\n", Qt::SkipEmptyParts)
            );

            }
}

void technician::on_pushButton_2_endChat_clicked()
{

    this->close();
}


void technician::setClientName(const QString &name)
{
    clientName = name;
    ui->label_2->setText("Chat with Client: " + clientName);
}

void technician::refreshChat()
{
    ui->chatDisplay->clear();
    ui->chatDisplay->addItems(
        logic->getChatLog(1).split("\n", Qt::SkipEmptyParts)
        );
}

