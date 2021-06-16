#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include <limits>

#include "commodity.h"
#include "form.h"

const double MONEY_MAX = 1e10;
const int ITEM_MAX = 100;
const int LEN_MAX = 50;

const char COMMODITY_FILE[3][60] = {
    "C:/Users/orzzz/Desktop/PDD/data/commodity/book.dat",
    "C:/Users/orzzz/Desktop/PDD/data/commodity/clothing.dat",
    "C:/Users/orzzz/Desktop/PDD/data/commodity/electronic.dat"
};
const char USER_FILE[2][60] = {
    "C:/Users/orzzz/Desktop/PDD/data/user/customer.dat",
    "C:/Users/orzzz/Desktop/PDD/data/user/merchant.dat"
};

class User {
private:
    char passwd[LEN_MAX];
    double balance;
public:
    char nickname[LEN_MAX];
    char uid[LEN_MAX];
    char email[LEN_MAX];
    Form *f;
    User();
    User(std::string uid, std::string email, std::string nickname, std::string passwd, int balance = 0);
    bool checkPasswd(std::string str);
    virtual ~User();
    virtual int getUserType() = 0;
    virtual void saveData() = 0;
    void quit();
    bool changePasswd(std::string oldpasswd, std::string newpasswd);
    double getBalance();
    double recharge(double x);
};

class Customer : public User {
private:
public:
    Customer();
    Customer(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Customer();
    int getUserType();
    void saveData();
};

class Merchant : public User {
private:
public:
    Merchant();
    Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Merchant();
    int getUserType();
    void stock();
    void changeInfo();
    void saveData();
};

#endif
