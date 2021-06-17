#include "user.h"
#include <QDebug>

User::User() {
    memset(uid, 0, sizeof(uid));
    memset(email, 0, sizeof(email));
    memset(nickname, 0, sizeof(nickname));
    memset(passwd, 0, sizeof(passwd));
}
User::User(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD, int BALANCE)
    : balance(BALANCE) {
    memset(uid, 0, sizeof(uid)); UID.copy(uid, UID.size());
    memset(email, 0, sizeof(email)); EMAIL.copy(email, EMAIL.size());
    memset(nickname, 0, sizeof(nickname)); NICKNAME.copy(nickname, NICKNAME.size());
    memset(passwd, 0, sizeof(passwd)); PASSWD.copy(passwd, PASSWD.size());
}

User::~User() {}

bool User::checkPasswd(std::string str) {
    if(!strcmp(str.c_str(), passwd)) return true;
    return false;
}

bool User::changePasswd(std::string oldpasswd, std::string newpasswd) {
    if (!checkPasswd(oldpasswd)) {
        printf("Wrong password\n");
        return false;
    }
    memset(passwd, 0, sizeof(passwd));
    newpasswd.copy(passwd, newpasswd.size());
    saveData();
    printf("Success!\n");
    return true;
}

double User::getBalance() {
    printf("You have $%.2f left.\n", balance);
    return balance;
}

double User::recharge(double x) {
    if (x > MONEY_MAX - balance) balance = MONEY_MAX;
    else balance += x;
    saveData();
    printf("Success! You have $%.2f now.\n", balance);
    return balance;
}

/*---------CUSTOMER---------*/

Customer::Customer() {}

Customer::Customer(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD)
    : User(UID, EMAIL, NICKNAME, PASSWD) {}

Customer::~Customer() {}

int Customer::getUserType() {
    printf("Your role is: Customer.\n");
    return 0;
}

void Customer::saveData() {
    int index = atoi(uid) - 100000;
    std::fstream out(USER_FILE[0], std::ios::binary|std::ios::out|std::ios::in);
    out.seekp(index * sizeof(Customer), std::ios::beg);
    out.write((char *)this, sizeof(Customer));
    out.close();
}

/*---------MERCHANT---------*/

Merchant::Merchant() {}

Merchant::Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD)
    : User(UID, EMAIL, NICKNAME, PASSWD) {}

Merchant::~Merchant() {}

int Merchant::getUserType() {
    printf("Your role is: Merchant.\n");
    return 1;
}

void Merchant::saveData() {
    int index = atoi(uid) - 100000;
    std::fstream out(USER_FILE[1], std::ios::binary|std::ios::out|std::ios::in);
    out.seekp(index * sizeof(Merchant), std::ios::beg);
    out.write((char *)this, sizeof(Merchant));
    out.close();
}
