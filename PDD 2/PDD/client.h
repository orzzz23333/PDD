#ifndef CLIENT_H
#define CLIENT_H

#include <bits/stdc++.h>
#include <conio.h>
#include "user.h"
#include "commodity.h"

class Client {
private:
    char uid[LEN_MAX];
    char email[LEN_MAX];
    bool role; // 0: Customer, 1: Merchant
    bool validChar(char ch);
    User *registerAccount();
public:
    Client();
    ~Client();
    void setClient(std::string str);
    bool uidLegal();
    bool emailLegal();
    User *uidQuery();
    User *emailQuery();
    User *Login();
    void Logout();
    Commodity *getCommodityById();
    Commodity *getCommodityByName();
    void methodList();
};




#endif
