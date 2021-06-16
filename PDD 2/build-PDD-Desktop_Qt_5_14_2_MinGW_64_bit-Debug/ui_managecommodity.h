/********************************************************************************
** Form generated from reading UI file 'managecommodity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGECOMMODITY_H
#define UI_MANAGECOMMODITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageCommodity
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLineEdit *discountInput;
    QLineEdit *priceInput;
    QLabel *label_3;
    QPushButton *modifyButton;
    QLineEdit *IDInput;
    QLineEdit *infoInput;
    QLineEdit *inventoryInput;
    QPushButton *addButton;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *name;
    QLabel *label_7;
    QLineEdit *type;
    QLabel *label_8;
    QPushButton *discountButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageCommodity)
    {
        if (ManageCommodity->objectName().isEmpty())
            ManageCommodity->setObjectName(QString::fromUtf8("ManageCommodity"));
        ManageCommodity->resize(605, 501);
        centralwidget = new QWidget(ManageCommodity);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 390, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(12);
        pushButton_2->setFont(font);
        discountInput = new QLineEdit(centralwidget);
        discountInput->setObjectName(QString::fromUtf8("discountInput"));
        discountInput->setGeometry(QRect(230, 240, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        discountInput->setFont(font1);
        priceInput = new QLineEdit(centralwidget);
        priceInput->setObjectName(QString::fromUtf8("priceInput"));
        priceInput->setEnabled(true);
        priceInput->setGeometry(QRect(230, 190, 221, 31));
        priceInput->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 240, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(18);
        label_3->setFont(font2);
        modifyButton = new QPushButton(centralwidget);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setEnabled(true);
        modifyButton->setGeometry(QRect(40, 390, 121, 41));
        modifyButton->setFont(font);
        IDInput = new QLineEdit(centralwidget);
        IDInput->setObjectName(QString::fromUtf8("IDInput"));
        IDInput->setEnabled(true);
        IDInput->setGeometry(QRect(230, 40, 221, 31));
        IDInput->setFont(font1);
        infoInput = new QLineEdit(centralwidget);
        infoInput->setObjectName(QString::fromUtf8("infoInput"));
        infoInput->setGeometry(QRect(230, 340, 221, 31));
        infoInput->setFont(font1);
        inventoryInput = new QLineEdit(centralwidget);
        inventoryInput->setObjectName(QString::fromUtf8("inventoryInput"));
        inventoryInput->setGeometry(QRect(230, 290, 221, 31));
        inventoryInput->setFont(font1);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setEnabled(true);
        addButton->setGeometry(QRect(180, 390, 121, 41));
        addButton->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 40, 131, 31));
        label_2->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 190, 101, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 340, 161, 31));
        label_6->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 290, 111, 31));
        label_4->setFont(font2);
        name = new QLineEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setEnabled(false);
        name->setGeometry(QRect(230, 140, 221, 31));
        name->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(80, 140, 131, 31));
        label_7->setFont(font2);
        type = new QLineEdit(centralwidget);
        type->setObjectName(QString::fromUtf8("type"));
        type->setEnabled(false);
        type->setGeometry(QRect(230, 90, 221, 31));
        type->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 90, 131, 31));
        label_8->setFont(font2);
        discountButton = new QPushButton(centralwidget);
        discountButton->setObjectName(QString::fromUtf8("discountButton"));
        discountButton->setGeometry(QRect(460, 390, 121, 41));
        discountButton->setFont(font);
        ManageCommodity->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ManageCommodity);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManageCommodity->setStatusBar(statusbar);

        retranslateUi(ManageCommodity);

        QMetaObject::connectSlotsByName(ManageCommodity);
    } // setupUi

    void retranslateUi(QMainWindow *ManageCommodity)
    {
        ManageCommodity->setWindowTitle(QCoreApplication::translate("ManageCommodity", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ManageCommodity", "\345\217\226\346\266\210", nullptr));
        discountInput->setText(QString());
        priceInput->setText(QString());
        label_3->setText(QCoreApplication::translate("ManageCommodity", "\346\212\230\346\211\243\357\274\232", nullptr));
        modifyButton->setText(QCoreApplication::translate("ManageCommodity", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        IDInput->setText(QString());
        infoInput->setText(QString());
        inventoryInput->setText(QString());
        addButton->setText(QCoreApplication::translate("ManageCommodity", "\346\267\273\345\212\240\346\226\260\345\223\201", nullptr));
        label_2->setText(QCoreApplication::translate("ManageCommodity", "\345\225\206\345\223\201ID\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ManageCommodity", "\345\216\237\344\273\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("ManageCommodity", "\345\225\206\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ManageCommodity", "\345\272\223\345\255\230\357\274\232", nullptr));
        name->setText(QString());
        label_7->setText(QCoreApplication::translate("ManageCommodity", "\345\225\206\345\223\201\345\220\215\357\274\232", nullptr));
        type->setText(QString());
        label_8->setText(QCoreApplication::translate("ManageCommodity", "\347\247\215\347\261\273\357\274\232", nullptr));
        discountButton->setText(QCoreApplication::translate("ManageCommodity", "\344\270\200\351\224\256\346\211\223\346\212\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageCommodity: public Ui_ManageCommodity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGECOMMODITY_H
