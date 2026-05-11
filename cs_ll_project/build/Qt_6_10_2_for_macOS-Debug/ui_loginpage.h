/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QLabel *label_password;
    QLineEdit *passwordLineEdit;
    QLineEdit *usernameLineEdit;
    QLabel *label_username;
    QLabel *label;
    QPushButton *loginButton;
    QComboBox *comboBox_role;

    void setupUi(QDialog *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(779, 636);
        label_password = new QLabel(LoginPage);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(230, 320, 71, 16));
        passwordLineEdit = new QLineEdit(LoginPage);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(230, 350, 281, 21));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        usernameLineEdit = new QLineEdit(LoginPage);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(230, 250, 271, 21));
        label_username = new QLabel(LoginPage);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(230, 220, 71, 16));
        label = new QLabel(LoginPage);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 150, 121, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(20);
        label->setFont(font);
        loginButton = new QPushButton(LoginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(380, 400, 100, 32));
        comboBox_role = new QComboBox(LoginPage);
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->setObjectName("comboBox_role");
        comboBox_role->setGeometry(QRect(250, 400, 103, 32));

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QDialog *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Dialog", nullptr));
        label_password->setText(QCoreApplication::translate("LoginPage", "Password: ", nullptr));
        label_username->setText(QCoreApplication::translate("LoginPage", "Username: ", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "Log In", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginPage", "Log in", nullptr));
        comboBox_role->setItemText(0, QCoreApplication::translate("LoginPage", "Technician", nullptr));
        comboBox_role->setItemText(1, QCoreApplication::translate("LoginPage", "Employee", nullptr));

    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
