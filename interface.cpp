#include "interface.h"
#include "user.h"

char *Interface::getPasswd() {
    char *buf = new char[LEN_MAX];
    char c;
    int i = 0;
    while ((c = getch()) != '\r') {
        if (i < LEN_MAX && isprint(c)) {
            buf[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b') {
            i--;
            putchar('\b'); putchar(' '); putchar('\b');
        }
    }
    putchar('\n');
    buf[i] = 0;
    return buf;
}

bool Interface::confirmRegister() {
    printf("Register a new account? (Y/N)\n");
    char ch;
    std::cin >> ch;
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmRegister();
}

bool Interface::confirmAddItem() {
    printf("Add a new item? (Y/N)\n");
    char ch;
    std::cin >> ch;
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmAddItem();
}

bool Interface::confirmSave() {
    printf("Save changes or not? (Y/N)\n");
    char ch;
    std::cin >> ch;
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmSave();
}

int Interface::chooseRole() {
    printf("Choose your role, Customer or Merchant. (C/M)\n");
    char ch;
    std::cin >> ch;
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'C' || ch == 'c') return 0;
    if (ch == 'M' || ch == 'm') return 1;
    return chooseRole();
}

int Interface::chooseType() {
    printf("Choose the type, Book or Clothing or Electronic. (B/C/E)\n");
    char ch;
    std::cin >> ch;
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'B' || ch == 'b') return 0;
    if (ch == 'C' || ch == 'c') return 1;
    if (ch == 'E' || ch == 'e') return 2;
    return chooseType();
}