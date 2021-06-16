/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QCheckBox *isCustomer;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *nameInput;
    QLineEdit *passwdInput;
    QCheckBox *isMerchant;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(676, 430);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 200, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(18);
        label_2->setFont(font);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(160, 280, 121, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font1.setPointSize(12);
        pushButton->setFont(font1);
        isCustomer = new QCheckBox(Login);
        isCustomer->setObjectName(QString::fromUtf8("isCustomer"));
        isCustomer->setEnabled(true);
        isCustomer->setGeometry(QRect(140, 60, 201, 41));
        isCustomer->setFont(font1);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 130, 121, 31));
        label->setFont(font);
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 280, 121, 41));
        pushButton_2->setFont(font1);
        nameInput = new QLineEdit(Login);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        nameInput->setGeometry(QRect(270, 130, 221, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(12);
        nameInput->setFont(font2);
        passwdInput = new QLineEdit(Login);
        passwdInput->setObjectName(QString::fromUtf8("passwdInput"));
        passwdInput->setGeometry(QRect(270, 200, 221, 31));
        passwdInput->setFont(font2);
        isMerchant = new QCheckBox(Login);
        isMerchant->setObjectName(QString::fromUtf8("isMerchant"));
        isMerchant->setGeometry(QRect(370, 60, 191, 41));
        isMerchant->setFont(font1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225/\346\263\250\345\206\214", nullptr));
        isCustomer->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\346\266\210\350\264\271\350\200\205", nullptr));
        label->setText(QCoreApplication::translate("Login", "\351\202\256\347\256\261/UID\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
        nameInput->setText(QString());
        passwdInput->setText(QString());
        isMerchant->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\345\225\206\345\256\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
