/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QPushButton *userButton;
    QPushButton *logoutButton;
    QTableView *tableView;
    QLineEdit *findNameText;
    QPushButton *commodityButton;
    QPushButton *mineButton;
    QPushButton *allButton;
    QPushButton *buyButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(982, 576);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(740, 30, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(12);
        loginButton->setFont(font);
        userButton = new QPushButton(centralwidget);
        userButton->setObjectName(QString::fromUtf8("userButton"));
        userButton->setGeometry(QRect(610, 30, 121, 41));
        userButton->setFont(font);
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(860, 30, 111, 41));
        logoutButton->setFont(font);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 90, 961, 401));
        tableView->setFont(font);
        findNameText = new QLineEdit(centralwidget);
        findNameText->setObjectName(QString::fromUtf8("findNameText"));
        findNameText->setGeometry(QRect(10, 30, 231, 41));
        findNameText->setFont(font);
        commodityButton = new QPushButton(centralwidget);
        commodityButton->setObjectName(QString::fromUtf8("commodityButton"));
        commodityButton->setGeometry(QRect(10, 500, 121, 41));
        commodityButton->setFont(font);
        mineButton = new QPushButton(centralwidget);
        mineButton->setObjectName(QString::fromUtf8("mineButton"));
        mineButton->setGeometry(QRect(150, 500, 121, 41));
        mineButton->setFont(font);
        allButton = new QPushButton(centralwidget);
        allButton->setObjectName(QString::fromUtf8("allButton"));
        allButton->setGeometry(QRect(260, 30, 121, 41));
        allButton->setFont(font);
        buyButton = new QPushButton(centralwidget);
        buyButton->setObjectName(QString::fromUtf8("buyButton"));
        buyButton->setGeometry(QRect(850, 500, 121, 41));
        buyButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225/\346\263\250\345\206\214", nullptr));
        userButton->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        commodityButton->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        mineButton->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\345\225\206\345\223\201", nullptr));
        allButton->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\345\225\206\345\223\201", nullptr));
        buyButton->setText(QCoreApplication::translate("MainWindow", "\350\264\255\344\271\260/\350\264\255\347\211\251\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
