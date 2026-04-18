/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
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
    QListWidget *screen;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *type;
    QPushButton *send;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(718, 468);
        label_2 = new QLabel(Client);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 20, 561, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_2->setFont(font);
        frame = new QFrame(Client);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(80, 40, 571, 321));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        screen = new QListWidget(frame);
        screen->setObjectName("screen");

        verticalLayout->addWidget(screen);

        widget = new QWidget(Client);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 380, 561, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        type = new QLineEdit(widget);
        type->setObjectName("type");

        horizontalLayout->addWidget(type);

        send = new QPushButton(widget);
        send->setObjectName("send");

        horizontalLayout->addWidget(send);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Form", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("Client", "Message:", nullptr));
        send->setText(QCoreApplication::translate("Client", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
