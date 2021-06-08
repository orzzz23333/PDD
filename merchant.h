#ifndef MERCHANT_H
#define MERCHANT_H

#include <bits/stdc++.h>
#include "user.h"

class Merchant : public User {
private:
public:
    Merchant();
    Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD);
    ~Merchant();
    int getUserType();
    void methodList();
    void saveData();
};

#endif