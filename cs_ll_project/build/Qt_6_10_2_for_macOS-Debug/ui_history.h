/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_History
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *History)
    {
        if (History->objectName().isEmpty())
            History->setObjectName("History");
        History->resize(803, 455);
        label = new QLabel(History);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 120, 211, 16));
        label_2 = new QLabel(History);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 210, 401, 16));
        pushButton = new QPushButton(History);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 240, 131, 41));

        retranslateUi(History);

        QMetaObject::connectSlotsByName(History);
    } // setupUi

    void retranslateUi(QDialog *History)
    {
        History->setWindowTitle(QCoreApplication::translate("History", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("History", "Thanks for sharing your feedback!", nullptr));
        label_2->setText(QCoreApplication::translate("History", "You can access your chat history by clicking on this button!", nullptr));
        pushButton->setText(QCoreApplication::translate("History", "Check my history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class History: public Ui_History {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
