/********************************************************************************
** Form generated from reading UI file 'manageuser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEUSER_H
#define UI_MANAGEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageUser
{
public:
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *changePasswdButton;
    QLineEdit *nickname;
    QLabel *label_2;
    QLineEdit *oldPasswdInput;
    QLabel *label_4;
    QLineEdit *newPasswdInput;
    QLabel *label_5;
    QLineEdit *balance;
    QLabel *label_6;
    QLineEdit *rechargeInput;
    QPushButton *rechargeButton;

    void setupUi(QWidget *ManageUser)
    {
        if (ManageUser->objectName().isEmpty())
            ManageUser->setObjectName(QString::fromUtf8("ManageUser"));
        ManageUser->resize(582, 400);
        pushButton_2 = new QPushButton(ManageUser);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 300, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(12);
        pushButton_2->setFont(font);
        label_3 = new QLabel(ManageUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 150, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font1.setPointSize(18);
        label_3->setFont(font1);
        changePasswdButton = new QPushButton(ManageUser);
        changePasswdButton->setObjectName(QString::fromUtf8("changePasswdButton"));
        changePasswdButton->setEnabled(true);
        changePasswdButton->setGeometry(QRect(80, 300, 121, 41));
        changePasswdButton->setFont(font);
        nickname = new QLineEdit(ManageUser);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setEnabled(false);
        nickname->setGeometry(QRect(200, 50, 221, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(12);
        nickname->setFont(font2);
        label_2 = new QLabel(ManageUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 50, 61, 31));
        label_2->setFont(font1);
        oldPasswdInput = new QLineEdit(ManageUser);
        oldPasswdInput->setObjectName(QString::fromUtf8("oldPasswdInput"));
        oldPasswdInput->setGeometry(QRect(200, 150, 221, 31));
        oldPasswdInput->setFont(font2);
        label_4 = new QLabel(ManageUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 200, 81, 31));
        label_4->setFont(font1);
        newPasswdInput = new QLineEdit(ManageUser);
        newPasswdInput->setObjectName(QString::fromUtf8("newPasswdInput"));
        newPasswdInput->setGeometry(QRect(200, 200, 221, 31));
        newPasswdInput->setFont(font2);
        label_5 = new QLabel(ManageUser);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 100, 61, 31));
        label_5->setFont(font1);
        balance = new QLineEdit(ManageUser);
        balance->setObjectName(QString::fromUtf8("balance"));
        balance->setEnabled(false);
        balance->setGeometry(QRect(200, 100, 221, 31));
        balance->setFont(font2);
        label_6 = new QLabel(ManageUser);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 250, 111, 31));
        label_6->setFont(font1);
        rechargeInput = new QLineEdit(ManageUser);
        rechargeInput->setObjectName(QString::fromUtf8("rechargeInput"));
        rechargeInput->setGeometry(QRect(200, 250, 221, 31));
        rechargeInput->setFont(font2);
        rechargeButton = new QPushButton(ManageUser);
        rechargeButton->setObjectName(QString::fromUtf8("rechargeButton"));
        rechargeButton->setEnabled(true);
        rechargeButton->setGeometry(QRect(220, 300, 121, 41));
        rechargeButton->setFont(font);

        retranslateUi(ManageUser);

        QMetaObject::connectSlotsByName(ManageUser);
    } // setupUi

    void retranslateUi(QWidget *ManageUser)
    {
        ManageUser->setWindowTitle(QCoreApplication::translate("ManageUser", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ManageUser", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QCoreApplication::translate("ManageUser", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        changePasswdButton->setText(QCoreApplication::translate("ManageUser", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        nickname->setText(QString());
        label_2->setText(QCoreApplication::translate("ManageUser", "\346\230\265\347\247\260\357\274\232", nullptr));
        oldPasswdInput->setText(QString());
        label_4->setText(QCoreApplication::translate("ManageUser", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        newPasswdInput->setText(QString());
        label_5->setText(QCoreApplication::translate("ManageUser", "\344\275\231\351\242\235\357\274\232", nullptr));
        balance->setText(QString());
        label_6->setText(QCoreApplication::translate("ManageUser", "\345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", nullptr));
        rechargeInput->setText(QString());
        rechargeButton->setText(QCoreApplication::translate("ManageUser", "\345\205\205\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageUser: public Ui_ManageUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEUSER_H
