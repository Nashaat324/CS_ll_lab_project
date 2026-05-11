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

    network->connectToServer("127.0.0.1", 54321);


    QTimer::singleShot(100, this, [=]() {
        QJsonObject loginJson;
        loginJson["type"] = "login";
        loginJson["user"] = myName; // Ensure 'user' is the key your server wants!

        QJsonDocument doc(loginJson);
        network->sendData(doc.toJson(QJsonDocument::Compact));

        qDebug() << "Sent Login JSON to server";
    });
}

technician::~technician()
{
    delete ui;
}

void technician::on_pushButton_send_clicked()
{
    qDebug() << "Send button was clicked!";
    qDebug() << "TECH DEBUG: Sending message to:" << clientName;
    QString msg = ui->lineEdit_message->text();



    if (msg.isEmpty()) return;


    logic->processChatMessage(1, "Technician", msg);

    ui->chatDisplay->clear();
    ui->chatDisplay->addItems(logic->getChatLog(1).split("\n", Qt::SkipEmptyParts));

    qDebug() << "TECH WINDOW ATTEMPTING TO SEND TO:" << clientName;
    QJsonObject json;
    json["type"] = "chat_message"; // Server checks this first
    json["from"] = myName; // Server needs this to print 'sender'
    json["to"] = clientName; // Server needs this to route the message
    json["message"] = msg; // Server needs this to print the actual text

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


void technician::setTechName(const QString &name)
{
    myName = name; // Now 'myName' is no longer empty
}

void technician::refreshChat()
{
    ui->chatDisplay->clear();
    ui->chatDisplay->addItems(
        logic->getChatLog(1).split("\n", Qt::SkipEmptyParts)
        );
}
