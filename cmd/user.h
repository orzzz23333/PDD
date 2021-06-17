#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include <limits>

#include "commodity.h"

const double MONEY_MAX = 1e10;
const int ITEM_MAX = 100;
const int LEN_MAX = 50;

const char COMMODITY_FILE[3][40] = {
    "data/commodity/book.dat",
    "data/commodity/clothing.dat",
    "data/commodity/electronic.dat"
};
const char USER_FILE[2][30] = {
    "data/user/customer.dat",
    "data/user/merchant.dat"
};

class User {
private:
    char nickname[LEN_MAX];
    char passwd[LEN_MAX];
    double balance;
public:
    char uid[LEN_MAX];
    char email[LEN_MAX];
    User();
    User(std::string uid, std::string email, std::string nickname, std::string passwd, int balance = 0);
    bool checkPasswd(std::string str);
    virtual ~User();
    virtual int getUserType() = 0;
    virtual void methodList() = 0;
    virtual void saveData() = 0;
    void quit();
    void changePasswd();
    double getBalance();
    double recharge();
};

class Customer : public User {
private:
public:
    Customer();
    Customer(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Customer();
    int getUserType();
    void saveData();
    void methodList();
};

class Merchant : public User {
private:
    int list[ITEM_MAX];
public:
    Merchant();
    Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Merchant();
    int getUserType();
    void methodList();
    void stock();
    void changeInfo();
    Commodity *addItem(std::string name, int type);
    Commodity *search();
    void saveData();
};

#endif