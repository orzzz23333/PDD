#include "merchant.h"

Merchant::Merchant() {}

Merchant::Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD)
    : User(UID, EMAIL, NICKNAME, PASSWD) {}

Merchant::~Merchant() {}

int Merchant::getUserType() {
    printf("Your role is: Merchant.\n");
    return 1;
}

void Merchant::methodList() {
    printf("C: Change password\n");
    printf("H: help\n");
    char ch;
    while (true) {
        std::cin >> ch;
        if (ch == 'C' || ch == 'c') {
            changePasswd(); return;
        }
        else if (ch == 'H' || ch == 'h') {
            methodList(); return;
        }
        else printf("Command not exist.\n");
    }
}