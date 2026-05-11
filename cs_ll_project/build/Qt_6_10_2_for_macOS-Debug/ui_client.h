/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLabel *label_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QListWidget *chatDisplay;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *type;
    QPushButton *send;
    QPushButton *End_Chat;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(1079, 681);
        label_2 = new QLabel(Client);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 110, 561, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_2->setFont(font);
        frame = new QFrame(Client);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(270, 130, 571, 321));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        chatDisplay = new QListWidget(frame);
        chatDisplay->setObjectName("chatDisplay");

        verticalLayout->addWidget(chatDisplay);

        layoutWidget = new QWidget(Client);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(280, 470, 561, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        type = new QLineEdit(layoutWidget);
        type->setObjectName("type");

        horizontalLayout->addWidget(type);

        send = new QPushButton(layoutWidget);
        send->setObjectName("send");

        horizontalLayout->addWidget(send);

        End_Chat = new QPushButton(Client);
        End_Chat->setObjectName("End_Chat");
        End_Chat->setGeometry(QRect(520, 530, 71, 31));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Form", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("Client", "Message:", nullptr));
        send->setText(QCoreApplication::translate("Client", "Send", nullptr));
        End_Chat->setText(QCoreApplication::translate("Client", "End Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
