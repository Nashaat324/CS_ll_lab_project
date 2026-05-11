/********************************************************************************
** Form generated from reading UI file 'technician.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TECHNICIAN_H
#define UI_TECHNICIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_technician
{
public:
    QListWidget *chatDisplay;
    QLabel *message;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_send;
    QPushButton *pushButton_2_endChat;

    void setupUi(QWidget *technician)
    {
        if (technician->objectName().isEmpty())
            technician->setObjectName("technician");
        technician->resize(936, 685);
        chatDisplay = new QListWidget(technician);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setGeometry(QRect(230, 100, 531, 361));
        message = new QLabel(technician);
        message->setObjectName("message");
        message->setGeometry(QRect(230, 470, 81, 20));
        QFont font;
        font.setBold(true);
        message->setFont(font);
        lineEdit_message = new QLineEdit(technician);
        lineEdit_message->setObjectName("lineEdit_message");
        lineEdit_message->setGeometry(QRect(300, 470, 351, 21));
        pushButton_send = new QPushButton(technician);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setGeometry(QRect(660, 470, 100, 32));
        pushButton_2_endChat = new QPushButton(technician);
        pushButton_2_endChat->setObjectName("pushButton_2_endChat");
        pushButton_2_endChat->setGeometry(QRect(450, 510, 100, 32));

        retranslateUi(technician);

        QMetaObject::connectSlotsByName(technician);
    } // setupUi

    void retranslateUi(QWidget *technician)
    {
        technician->setWindowTitle(QCoreApplication::translate("technician", "Form", nullptr));
        message->setText(QCoreApplication::translate("technician", "Message:", nullptr));
        pushButton_send->setText(QCoreApplication::translate("technician", "Send", nullptr));
        pushButton_2_endChat->setText(QCoreApplication::translate("technician", "End Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class technician: public Ui_technician {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECHNICIAN_H
