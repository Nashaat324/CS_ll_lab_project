/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_firstline;
    QLabel *label_secondline;
    QLabel *label_thirdline;
    QRadioButton *radioButton_verypoor;
    QRadioButton *radioButton_poor;
    QRadioButton *radioButton_Fair;
    QRadioButton *radioButton_Good;
    QRadioButton *radioButton_VeryGood;
    QPushButton *Button_sharemyfeedback;
    QTextEdit *textEdit_writtenfeedback;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_firstline = new QLabel(centralwidget);
        label_firstline->setObjectName("label_firstline");
        label_firstline->setGeometry(QRect(330, 40, 131, 16));
        label_secondline = new QLabel(centralwidget);
        label_secondline->setObjectName("label_secondline");
        label_secondline->setGeometry(QRect(270, 100, 271, 16));
        label_thirdline = new QLabel(centralwidget);
        label_thirdline->setObjectName("label_thirdline");
        label_thirdline->setGeometry(QRect(260, 170, 281, 16));
        radioButton_verypoor = new QRadioButton(centralwidget);
        radioButton_verypoor->setObjectName("radioButton_verypoor");
        radioButton_verypoor->setGeometry(QRect(210, 130, 99, 20));
        radioButton_poor = new QRadioButton(centralwidget);
        radioButton_poor->setObjectName("radioButton_poor");
        radioButton_poor->setGeometry(QRect(310, 130, 99, 20));
        radioButton_Fair = new QRadioButton(centralwidget);
        radioButton_Fair->setObjectName("radioButton_Fair");
        radioButton_Fair->setGeometry(QRect(380, 130, 99, 20));
        radioButton_Good = new QRadioButton(centralwidget);
        radioButton_Good->setObjectName("radioButton_Good");
        radioButton_Good->setGeometry(QRect(450, 130, 99, 20));
        radioButton_VeryGood = new QRadioButton(centralwidget);
        radioButton_VeryGood->setObjectName("radioButton_VeryGood");
        radioButton_VeryGood->setGeometry(QRect(520, 130, 99, 20));
        Button_sharemyfeedback = new QPushButton(centralwidget);
        Button_sharemyfeedback->setObjectName("Button_sharemyfeedback");
        Button_sharemyfeedback->setGeometry(QRect(330, 360, 141, 32));
        textEdit_writtenfeedback = new QTextEdit(centralwidget);
        textEdit_writtenfeedback->setObjectName("textEdit_writtenfeedback");
        textEdit_writtenfeedback->setGeometry(QRect(270, 200, 261, 151));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_firstline->setText(QCoreApplication::translate("MainWindow", "Your opinion matters!", nullptr));
        label_secondline->setText(QCoreApplication::translate("MainWindow", "How would you rate your overall experience?", nullptr));
        label_thirdline->setText(QCoreApplication::translate("MainWindow", "Kindly take a moment to tell us what you think.", nullptr));
        radioButton_verypoor->setText(QCoreApplication::translate("MainWindow", "Very poor", nullptr));
        radioButton_poor->setText(QCoreApplication::translate("MainWindow", "Poor", nullptr));
        radioButton_Fair->setText(QCoreApplication::translate("MainWindow", "Fair", nullptr));
        radioButton_Good->setText(QCoreApplication::translate("MainWindow", "Good", nullptr));
        radioButton_VeryGood->setText(QCoreApplication::translate("MainWindow", "Very Good", nullptr));
        Button_sharemyfeedback->setText(QCoreApplication::translate("MainWindow", "Share my feedback", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
