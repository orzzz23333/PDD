#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "login.h"
#include "user.h"
#include "manageuser.h"
#include "managecommodity.h"
#include "commodity.h"
#include "warning.h"
#include "register.h"
#include "buy.h"
#include "cart.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
    bool checkLogin();
    void showTable();

private slots:
    void on_loginButton_clicked();
    void find();
    void on_logoutButton_clicked();

    void on_userButton_clicked();

    void on_mineButton_clicked();

    void on_allButton_clicked();

    void on_commodityButton_clicked();

    void on_cartButton_clicked();

    void generateModel();
signals:
    void finished();
private:
    Ui::MainWindow *ui;
    Login *log;
    warning *warn;
    ManageUser *mu;
    ManageCommodity *cu;
    Cart *cart;
    Client *client;
    QStringList model;
};
#endif // MAINWINDOW_H
