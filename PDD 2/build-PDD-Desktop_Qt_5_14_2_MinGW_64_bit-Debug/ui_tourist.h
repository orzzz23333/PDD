/********************************************************************************
** Form generated from reading UI file 'tourist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURIST_H
#define UI_TOURIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tourist
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tourist)
    {
        if (Tourist->objectName().isEmpty())
            Tourist->setObjectName(QString::fromUtf8("Tourist"));
        Tourist->resize(600, 450);
        centralwidget = new QWidget(Tourist);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Tourist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tourist);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 23));
        Tourist->setMenuBar(menubar);
        statusbar = new QStatusBar(Tourist);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tourist->setStatusBar(statusbar);

        retranslateUi(Tourist);

        QMetaObject::connectSlotsByName(Tourist);
    } // setupUi

    void retranslateUi(QMainWindow *Tourist)
    {
        Tourist->setWindowTitle(QCoreApplication::translate("Tourist", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tourist: public Ui_Tourist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURIST_H
