/********************************************************************************
** Form generated from reading UI file 'issueticket.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUETICKET_H
#define UI_ISSUETICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IssueTicket
{
public:
    QLabel *label_welcome;
    QComboBox *comboBox_category;
    QLabel *label_category;
    QComboBox *comboBox_sub_category;
    QLabel *label_sub_category;
    QLabel *label_issue;
    QLineEdit *lineEdit_issue;
    QLabel *label_2_tech;
    QComboBox *comboBox_tech;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_reset;

    void setupUi(QWidget *IssueTicket)
    {
        if (IssueTicket->objectName().isEmpty())
            IssueTicket->setObjectName("IssueTicket");
        IssueTicket->setEnabled(true);
        IssueTicket->resize(938, 666);
        label_welcome = new QLabel(IssueTicket);
        label_welcome->setObjectName("label_welcome");
        label_welcome->setGeometry(QRect(260, 40, 511, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        label_welcome->setFont(font);
        label_welcome->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox_category = new QComboBox(IssueTicket);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");
        comboBox_category->setGeometry(QRect(290, 140, 103, 32));
        label_category = new QLabel(IssueTicket);
        label_category->setObjectName("label_category");
        label_category->setGeometry(QRect(40, 140, 251, 31));
        QFont font1;
        font1.setPointSize(16);
        label_category->setFont(font1);
        comboBox_sub_category = new QComboBox(IssueTicket);
        comboBox_sub_category->setObjectName("comboBox_sub_category");
        comboBox_sub_category->setEnabled(true);
        comboBox_sub_category->setGeometry(QRect(300, 200, 103, 32));
        label_sub_category = new QLabel(IssueTicket);
        label_sub_category->setObjectName("label_sub_category");
        label_sub_category->setGeometry(QRect(40, 210, 251, 16));
        label_sub_category->setFont(font1);
        label_issue = new QLabel(IssueTicket);
        label_issue->setObjectName("label_issue");
        label_issue->setGeometry(QRect(40, 260, 201, 21));
        label_issue->setFont(font1);
        lineEdit_issue = new QLineEdit(IssueTicket);
        lineEdit_issue->setObjectName("lineEdit_issue");
        lineEdit_issue->setGeometry(QRect(250, 260, 113, 21));
        label_2_tech = new QLabel(IssueTicket);
        label_2_tech->setObjectName("label_2_tech");
        label_2_tech->setGeometry(QRect(40, 310, 461, 31));
        label_2_tech->setFont(font1);
        comboBox_tech = new QComboBox(IssueTicket);
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->addItem(QString());
        comboBox_tech->setObjectName("comboBox_tech");
        comboBox_tech->setGeometry(QRect(510, 310, 103, 32));
        pushButton_submit = new QPushButton(IssueTicket);
        pushButton_submit->setObjectName("pushButton_submit");
        pushButton_submit->setGeometry(QRect(720, 460, 100, 32));
        pushButton_reset = new QPushButton(IssueTicket);
        pushButton_reset->setObjectName("pushButton_reset");
        pushButton_reset->setGeometry(QRect(600, 460, 100, 32));

        retranslateUi(IssueTicket);

        QMetaObject::connectSlotsByName(IssueTicket);
    } // setupUi

    void retranslateUi(QWidget *IssueTicket)
    {
        IssueTicket->setWindowTitle(QCoreApplication::translate("IssueTicket", "Form", nullptr));
        label_welcome->setText(QCoreApplication::translate("IssueTicket", "Welcome, User! Please specify the reason for your ticket.", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("IssueTicket", "Select Category", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("IssueTicket", "Hardware", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("IssueTicket", "Software", nullptr));

        label_category->setText(QCoreApplication::translate("IssueTicket", "What type of issue are you facing?", nullptr));
        label_sub_category->setText(QCoreApplication::translate("IssueTicket", "Select the specific device/software:", nullptr));
        label_issue->setText(QCoreApplication::translate("IssueTicket", "Briefly describe your issue:", nullptr));
        label_2_tech->setText(QCoreApplication::translate("IssueTicket", "If you want a specific technician, please choose from the given list", nullptr));
        comboBox_tech->setItemText(0, QCoreApplication::translate("IssueTicket", "Select your preferred technician ", nullptr));
        comboBox_tech->setItemText(1, QCoreApplication::translate("IssueTicket", "General technician", nullptr));
        comboBox_tech->setItemText(2, QCoreApplication::translate("IssueTicket", "IT Support - Ahmed Hassan", nullptr));
        comboBox_tech->setItemText(3, QCoreApplication::translate("IssueTicket", "IT Support - Omar Khaled", nullptr));
        comboBox_tech->setItemText(4, QCoreApplication::translate("IssueTicket", "Network Specialist - Youssef Ali", nullptr));
        comboBox_tech->setItemText(5, QCoreApplication::translate("IssueTicket", "Systems Engineer - Mahmoud Ibrahim", nullptr));
        comboBox_tech->setItemText(6, QCoreApplication::translate("IssueTicket", "Hardware Technician - Karim Mostafa", nullptr));

        pushButton_submit->setText(QCoreApplication::translate("IssueTicket", "Submit", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("IssueTicket", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IssueTicket: public Ui_IssueTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUETICKET_H
