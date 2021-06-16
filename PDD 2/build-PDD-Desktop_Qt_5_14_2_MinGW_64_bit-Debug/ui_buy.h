/********************************************************************************
** Form generated from reading UI file 'buy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUY_H
#define UI_BUY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buy
{
public:
    QLineEdit *inventory;
    QLineEdit *IDInput;
    QLabel *label_6;
    QLineEdit *type;
    QLabel *label_2;
    QLineEdit *merchant;
    QPushButton *buyButton;
    QLabel *label_3;
    QLineEdit *info;
    QLabel *label_4;
    QLineEdit *price;
    QLineEdit *name;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLineEdit *numInput;
    QLabel *label_9;

    void setupUi(QWidget *Buy)
    {
        if (Buy->objectName().isEmpty())
            Buy->setObjectName(QString::fromUtf8("Buy"));
        Buy->resize(694, 559);
        inventory = new QLineEdit(Buy);
        inventory->setObjectName(QString::fromUtf8("inventory"));
        inventory->setEnabled(false);
        inventory->setGeometry(QRect(270, 350, 221, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        inventory->setFont(font);
        IDInput = new QLineEdit(Buy);
        IDInput->setObjectName(QString::fromUtf8("IDInput"));
        IDInput->setEnabled(true);
        IDInput->setGeometry(QRect(270, 50, 221, 31));
        IDInput->setFont(font);
        label_6 = new QLabel(Buy);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 400, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font1.setPointSize(18);
        label_6->setFont(font1);
        type = new QLineEdit(Buy);
        type->setObjectName(QString::fromUtf8("type"));
        type->setEnabled(false);
        type->setGeometry(QRect(270, 150, 221, 31));
        type->setFont(font);
        label_2 = new QLabel(Buy);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 50, 131, 31));
        label_2->setFont(font1);
        merchant = new QLineEdit(Buy);
        merchant->setObjectName(QString::fromUtf8("merchant"));
        merchant->setEnabled(false);
        merchant->setGeometry(QRect(270, 300, 221, 31));
        merchant->setFont(font);
        buyButton = new QPushButton(Buy);
        buyButton->setObjectName(QString::fromUtf8("buyButton"));
        buyButton->setGeometry(QRect(170, 450, 121, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(12);
        buyButton->setFont(font2);
        label_3 = new QLabel(Buy);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 300, 111, 31));
        label_3->setFont(font1);
        info = new QLineEdit(Buy);
        info->setObjectName(QString::fromUtf8("info"));
        info->setEnabled(false);
        info->setGeometry(QRect(270, 400, 221, 31));
        info->setFont(font);
        label_4 = new QLabel(Buy);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 350, 111, 31));
        label_4->setFont(font1);
        price = new QLineEdit(Buy);
        price->setObjectName(QString::fromUtf8("price"));
        price->setEnabled(false);
        price->setGeometry(QRect(270, 250, 221, 31));
        price->setFont(font);
        name = new QLineEdit(Buy);
        name->setObjectName(QString::fromUtf8("name"));
        name->setEnabled(false);
        name->setGeometry(QRect(270, 200, 221, 31));
        name->setFont(font);
        label_7 = new QLabel(Buy);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 200, 131, 31));
        label_7->setFont(font1);
        label_8 = new QLabel(Buy);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(140, 150, 131, 31));
        label_8->setFont(font1);
        pushButton_2 = new QPushButton(Buy);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 450, 121, 41));
        pushButton_2->setFont(font2);
        label_5 = new QLabel(Buy);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 250, 101, 31));
        label_5->setFont(font1);
        numInput = new QLineEdit(Buy);
        numInput->setObjectName(QString::fromUtf8("numInput"));
        numInput->setEnabled(true);
        numInput->setGeometry(QRect(270, 100, 221, 31));
        numInput->setFont(font);
        label_9 = new QLabel(Buy);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 100, 131, 31));
        label_9->setFont(font1);

        retranslateUi(Buy);

        QMetaObject::connectSlotsByName(Buy);
    } // setupUi

    void retranslateUi(QWidget *Buy)
    {
        Buy->setWindowTitle(QCoreApplication::translate("Buy", "Form", nullptr));
        inventory->setText(QString());
        IDInput->setText(QString());
        label_6->setText(QCoreApplication::translate("Buy", "\345\225\206\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        type->setText(QString());
        label_2->setText(QCoreApplication::translate("Buy", "\345\225\206\345\223\201ID\357\274\232", nullptr));
        merchant->setText(QString());
        buyButton->setText(QCoreApplication::translate("Buy", "\350\264\255\344\271\260", nullptr));
        label_3->setText(QCoreApplication::translate("Buy", "\345\225\206\345\256\266\357\274\232", nullptr));
        info->setText(QString());
        label_4->setText(QCoreApplication::translate("Buy", "\345\272\223\345\255\230\357\274\232", nullptr));
        price->setText(QString());
        name->setText(QString());
        label_7->setText(QCoreApplication::translate("Buy", "\345\225\206\345\223\201\345\220\215\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("Buy", "\347\247\215\347\261\273\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Buy", "\345\217\226\346\266\210", nullptr));
        label_5->setText(QCoreApplication::translate("Buy", "\347\216\260\344\273\267\357\274\232", nullptr));
        numInput->setText(QString());
        label_9->setText(QCoreApplication::translate("Buy", "\350\264\255\344\271\260\344\273\266\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buy: public Ui_Buy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUY_H
