/********************************************************************************
** Form generated from reading UI file 'warn.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARN_H
#define UI_WARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Warn
{
public:

    void setupUi(QDialog *Warn)
    {
        if (Warn->objectName().isEmpty())
            Warn->setObjectName(QString::fromUtf8("Warn"));
        Warn->resize(400, 300);

        retranslateUi(Warn);

        QMetaObject::connectSlotsByName(Warn);
    } // setupUi

    void retranslateUi(QDialog *Warn)
    {
        Warn->setWindowTitle(QCoreApplication::translate("Warn", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warn: public Ui_Warn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARN_H
