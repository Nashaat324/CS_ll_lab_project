/********************************************************************************
** Form generated from reading UI file 'FeedbackPage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACKPAGE_H
#define UI_FEEDBACKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FeedbackPage
{
public:
    QTextEdit *textEdit_writtenfeedback;
    QRadioButton *radioButton_poor;
    QLabel *label_thirdline;
    QRadioButton *radioButton_verypoor;
    QLabel *label_secondline;
    QLabel *label_firstline;
    QRadioButton *radioButton_Fair;
    QPushButton *Button_sharemyfeedback;
    QRadioButton *radioButton_Good_2;
    QRadioButton *radioButton_VeryGood;

    void setupUi(QDialog *FeedbackPage)
    {
        if (FeedbackPage->objectName().isEmpty())
            FeedbackPage->setObjectName("FeedbackPage");
        FeedbackPage->resize(1043, 661);
        textEdit_writtenfeedback = new QTextEdit(FeedbackPage);
        textEdit_writtenfeedback->setObjectName("textEdit_writtenfeedback");
        textEdit_writtenfeedback->setGeometry(QRect(380, 320, 261, 151));
        radioButton_poor = new QRadioButton(FeedbackPage);
        radioButton_poor->setObjectName("radioButton_poor");
        radioButton_poor->setGeometry(QRect(420, 250, 99, 20));
        label_thirdline = new QLabel(FeedbackPage);
        label_thirdline->setObjectName("label_thirdline");
        label_thirdline->setGeometry(QRect(370, 290, 281, 16));
        radioButton_verypoor = new QRadioButton(FeedbackPage);
        radioButton_verypoor->setObjectName("radioButton_verypoor");
        radioButton_verypoor->setGeometry(QRect(320, 250, 99, 20));
        label_secondline = new QLabel(FeedbackPage);
        label_secondline->setObjectName("label_secondline");
        label_secondline->setGeometry(QRect(380, 220, 271, 16));
        label_firstline = new QLabel(FeedbackPage);
        label_firstline->setObjectName("label_firstline");
        label_firstline->setGeometry(QRect(440, 160, 131, 16));
        radioButton_Fair = new QRadioButton(FeedbackPage);
        radioButton_Fair->setObjectName("radioButton_Fair");
        radioButton_Fair->setGeometry(QRect(490, 250, 99, 20));
        Button_sharemyfeedback = new QPushButton(FeedbackPage);
        Button_sharemyfeedback->setObjectName("Button_sharemyfeedback");
        Button_sharemyfeedback->setGeometry(QRect(440, 480, 141, 32));
        radioButton_Good_2 = new QRadioButton(FeedbackPage);
        radioButton_Good_2->setObjectName("radioButton_Good_2");
        radioButton_Good_2->setGeometry(QRect(550, 250, 99, 20));
        radioButton_VeryGood = new QRadioButton(FeedbackPage);
        radioButton_VeryGood->setObjectName("radioButton_VeryGood");
        radioButton_VeryGood->setGeometry(QRect(630, 250, 99, 20));

        retranslateUi(FeedbackPage);

        QMetaObject::connectSlotsByName(FeedbackPage);
    } // setupUi

    void retranslateUi(QDialog *FeedbackPage)
    {
        FeedbackPage->setWindowTitle(QCoreApplication::translate("FeedbackPage", "Dialog", nullptr));
        radioButton_poor->setText(QCoreApplication::translate("FeedbackPage", "Poor", nullptr));
        label_thirdline->setText(QCoreApplication::translate("FeedbackPage", "Kindly take a moment to tell us what you think.", nullptr));
        radioButton_verypoor->setText(QCoreApplication::translate("FeedbackPage", "Very poor", nullptr));
        label_secondline->setText(QCoreApplication::translate("FeedbackPage", "How would you rate your overall experience?", nullptr));
        label_firstline->setText(QCoreApplication::translate("FeedbackPage", "Your opinion matters!", nullptr));
        radioButton_Fair->setText(QCoreApplication::translate("FeedbackPage", "Fair", nullptr));
        Button_sharemyfeedback->setText(QCoreApplication::translate("FeedbackPage", "Share my feedback", nullptr));
        radioButton_Good_2->setText(QCoreApplication::translate("FeedbackPage", "Good", nullptr));
        radioButton_VeryGood->setText(QCoreApplication::translate("FeedbackPage", "Very Good", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeedbackPage: public Ui_FeedbackPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACKPAGE_H
