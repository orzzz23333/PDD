/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nameInput;
    QLineEdit *passwdInput;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(612, 456);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 60, 381, 62));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 160, 91, 31));
        label_2->setFont(font);
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 230, 91, 31));
        label_3->setFont(font);
        nameInput = new QLineEdit(Register);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        nameInput->setGeometry(QRect(210, 160, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        nameInput->setFont(font1);
        passwdInput = new QLineEdit(Register);
        passwdInput->setObjectName(QString::fromUtf8("passwdInput"));
        passwdInput->setGeometry(QRect(210, 230, 221, 31));
        passwdInput->setFont(font1);
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(150, 300, 121, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 300, 121, 41));
        pushButton_2->setFont(font2);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p>\344\273\245\346\255\244\351\202\256\347\256\261\345\210\233\345\273\272\344\270\200\344\270\252\346\226\260\350\264\246\346\210\267</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", nullptr));
        nameInput->setText(QString());
        passwdInput->setText(QString());
        pushButton->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
