/********************************************************************************
** Form generated from reading UI file 'techwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TECHWINDOW_H
#define UI_TECHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_techWindow
{
public:
    QLabel *techwelcome;
    QLabel *ticketsWaiting;
    QPushButton *acceptTicket;

    void setupUi(QWidget *techWindow)
    {
        if (techWindow->objectName().isEmpty())
            techWindow->setObjectName("techWindow");
        techWindow->resize(533, 505);
        techwelcome = new QLabel(techWindow);
        techwelcome->setObjectName("techwelcome");
        techwelcome->setGeometry(QRect(180, 30, 181, 20));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        techwelcome->setFont(font);
        techwelcome->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ticketsWaiting = new QLabel(techWindow);
        ticketsWaiting->setObjectName("ticketsWaiting");
        ticketsWaiting->setGeometry(QRect(220, 160, 141, 20));
        acceptTicket = new QPushButton(techWindow);
        acceptTicket->setObjectName("acceptTicket");
        acceptTicket->setGeometry(QRect(210, 220, 141, 32));

        retranslateUi(techWindow);

        QMetaObject::connectSlotsByName(techWindow);
    } // setupUi

    void retranslateUi(QWidget *techWindow)
    {
        techWindow->setWindowTitle(QCoreApplication::translate("techWindow", "Form", nullptr));
        techwelcome->setText(QCoreApplication::translate("techWindow", "Welcome, Techinician", nullptr));
        ticketsWaiting->setText(QCoreApplication::translate("techWindow", "Tickets Waiting: 0", nullptr));
        acceptTicket->setText(QCoreApplication::translate("techWindow", "Accept Next Ticket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class techWindow: public Ui_techWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECHWINDOW_H
