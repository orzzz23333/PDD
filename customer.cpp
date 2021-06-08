#include "customer.h"

Customer::Customer() {}

Customer::Customer(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD)
    : balance(0), User(UID, EMAIL, NICKNAME, PASSWD) {}

Customer::~Customer() {}

int Customer::getUserType() {
    printf("Your role is: Customer.\n");
    return 0;
}

int Customer::getBalance() {
    printf("You have $%d left.\n", balance);
    return balance;
}

int Customer::recharge() {
    printf("Input a number you want to recharge.\n");
    int x;
    while(true) {
        if (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    if (x > INT32_MAX - balance) balance = INT32_MAX;
    else if (x < 0) {
        printf("Can't be negative number.\n");
        return balance;
    }
    else balance += x;
    printf("Success! You have $%d now.\n", balance);
    return balance;
}

void Customer::saveData() {
    int index = atoi(uid) - 100000;
    std::fstream out("data/customer.dat", std::ios::binary|std::ios::out|std::ios::in);
    out.seekp(index * sizeof(Customer), std::ios::beg);
    out.write((char *)this, sizeof(Customer));
    out.close();
}

void Customer::methodList() {
    printf("B: Check balance\n");
    printf("C: Change password\n");
    printf("H: Help\n");
    printf("R: Recharge\n");
    printf("Q: Logout\n");
    char ch;
    while (true) {
        std::cin >> ch;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (ch == 'B' || ch == 'b') {
            getBalance();
        }
        else if (ch == 'C' || ch == 'c') {
            changePasswd(); saveData();
        }
        else if (ch == 'H' || ch == 'h') {
            methodList(); return;
        }
        else if (ch == 'R' || ch == 'r') {
            recharge(); saveData();
        }
        else if (ch == 'Q' || ch == 'q') {
            quit();return;
        }
        else printf("Command not exist.\n");
    }
}