/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_warning
{
public:
    QLabel *label;

    void setupUi(QDialog *warning)
    {
        if (warning->objectName().isEmpty())
            warning->setObjectName(QString::fromUtf8("warning"));
        warning->resize(388, 136);
        label = new QLabel(warning);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 301, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(18);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        retranslateUi(warning);

        QMetaObject::connectSlotsByName(warning);
    } // setupUi

    void retranslateUi(QDialog *warning)
    {
        warning->setWindowTitle(QCoreApplication::translate("warning", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("warning", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215\344\270\215\346\230\257\344\270\200\344\270\252UID\346\210\226\351\202\256\347\256\261\357\274\201</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class warning: public Ui_warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
