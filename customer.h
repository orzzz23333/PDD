#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <bits/stdc++.h>
#include "user.h"
#include <limits>

class Customer : public User {
private:
    int balance;
public:
    Customer();
    Customer(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Customer();
    int getUserType();
    int getBalance();
    int recharge();
    void saveData();
    void methodList();
};

#endif