#include "interface.h"
#include "user.h"

char *Interface::getPasswd() {
    char *buf = new char[N];
    char c;
    int i = 0;
    while ((c = getch()) != '\r') {
        if (i < N && isprint(c)) {
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