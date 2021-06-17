#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include <conio.h>
#include "user.h"
#include "commodity.h"
#include "warning.h"
#include "register.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void setLogin(std::string str);
    bool uidLegal()const;
    bool emailLegal()const;
    void uidQuery();
    void emailQuery();
    void login();
    void logout();
    Commodity *getCommodityById();
    Commodity *getCommodityByName();
    void methodList();
    int getUserType();
    User *u;

private slots:
    void on_pushButton_clicked();
    void on_isCustomer_stateChanged(int arg1);

    void on_isMerchant_stateChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    char uid[LEN_MAX];
    char email[LEN_MAX];
    int role; // 0: Customer, 1: Merchant
    bool validChar(char ch)const;
    void *registerAccount();
    warning *warn;
    Register *reg;
};
#endif // LOGIN_H
