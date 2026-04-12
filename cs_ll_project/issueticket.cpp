#include "issueticket.h"
#include "ui_issueticket.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>

int IssueTicket::generalQueue = 0;
int IssueTicket::ahmedQueue = 0;
int IssueTicket::omarQueue = 0;
int IssueTicket::youssefQueue = 0;
int IssueTicket::mahmoudQueue = 0;
int IssueTicket::karimQueue = 0;

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

void IssueTicket::setUsername(QString username)
{
    currentUsername = username;

    ui->label_welcome->setText("Welcome, " + username + "! Please specify the reason for your ticket.");
}
void IssueTicket::on_pushButton_submit_clicked()
{
    QString category = ui->comboBox_category->currentText();
    if (category == "Select Category") {
        QMessageBox::critical(this, "Error", "Please select a category.");
        return;
    }

    QString sub = ui->comboBox_sub_category->currentText();
    if (sub == "Select your specific hardware problem" ||
        sub == "Select your specific software problem") {
        QMessageBox::critical(this, "Error", "Please select a specific problem.");
        return;
    }

    QString description = ui->lineEdit_issue->text();
    if (description.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please enter a description.");
        return;
    }

    QString technician = ui->comboBox_tech->currentText();
    int queueNumber = 0;



     if (technician == "IT Support - Ahmed Hassan") {
        ahmedQueue++;
        queueNumber = ahmedQueue;
    }
    else if (technician == "IT Support - Omar Khaled") {
        omarQueue++;
        queueNumber = omarQueue;
    }
    else if (technician == "Network Specialist - Youssef Ali") {
        youssefQueue++;
        queueNumber = youssefQueue;
    }
    else if (technician == "Systems Engineer - Mahmoud Ibrahim") {
        mahmoudQueue++;
        queueNumber = mahmoudQueue;
    }
    else if (technician == "Hardware Technician - Karim Mostafa") {
        karimQueue++;
        queueNumber = karimQueue;
    }
    else{
        generalQueue++;
        queueNumber = generalQueue;
    }

    QString ticketID;

    if (queueNumber < 10) {
        ticketID = "T-00" + QString::number(queueNumber);
    }
    else if (queueNumber < 100) {
        ticketID = "T-0" + QString::number(queueNumber);
    }
    else {
        ticketID = "T-" + QString::number(queueNumber);
    }

    int estimatedTime = queueNumber * 5;

    QJsonObject json;
    json["type"] = "Ticket_Request";
    json["username"] = currentUsername;
    json["category"] = category;
    json["problem"] = sub;
    json["description"] = description;
    json["technician"] = technician;
    json["queue"] = queueNumber;
    json["estimated_time"] = estimatedTime;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();




    QString message =
        "Ticket submitted successfully!\n\n"
        "Ticket ID: " + ticketID + "\n"
        "Your number in queue is: " + QString::number(queueNumber)+"\n"
        "Estimated wait time: " + QString::number(estimatedTime) + " minutes";

    QMessageBox::information(this, "Success", message);


    ui->comboBox_category->setCurrentIndex(0);
    ui->comboBox_sub_category->clear();
    ui->comboBox_sub_category->setEnabled(false);
    ui->comboBox_tech->setCurrentIndex(0);
    ui->lineEdit_issue->clear();

}
void IssueTicket::on_comboBox_category_currentTextChanged(const QString &category)
{
    ui->comboBox_sub_category->clear();


    if (category == "Hardware") {
        ui->comboBox_sub_category->setEnabled(true);
        ui->comboBox_sub_category->addItem("Select your specific hardware problem");
        ui->comboBox_sub_category->addItem("Printer not working");
        ui->comboBox_sub_category->addItem("Keyboard malfunction");
        ui->comboBox_sub_category->addItem("Mouse not responding");
        ui->comboBox_sub_category->addItem("Monitor display issue");
        ui->comboBox_sub_category->addItem("Laptop overheating");
        ui->comboBox_sub_category->addItem("Battery charging problem");
    }
    else if (category == "Software") {
        ui->comboBox_sub_category->setEnabled(true);
        ui->comboBox_sub_category->addItem("Select your specific software problem");
        ui->comboBox_sub_category->addItem("Login or authentication issue");
        ui->comboBox_sub_category->addItem("Application crash");
        ui->comboBox_sub_category->addItem("Software installation failure");
        ui->comboBox_sub_category->addItem("System running slow");
        ui->comboBox_sub_category->addItem("Update or compatibility issue");
        ui->comboBox_sub_category->addItem("Permission or access denied");
    }
    else {
        ui->comboBox_sub_category->setEnabled(false);
    }
}


void IssueTicket::on_pushButton_reset_clicked()
{
    ui->comboBox_category->setCurrentIndex(0);

    ui->comboBox_sub_category->clear();

    ui->comboBox_sub_category->setEnabled(false);

    ui->comboBox_tech->setCurrentIndex(0);

    ui->lineEdit_issue->clear();
}

