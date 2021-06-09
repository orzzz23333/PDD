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
    printf("+-----------------------------+\n");
    printf("|Register a new account? (Y/N)|\n");
    printf("+-----------------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmRegister();
}

bool Interface::confirmAddItem() {
    printf("+---------------------+\n");
    printf("|Add a new item? (Y/N)|\n");
    printf("+---------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmAddItem();
}

bool Interface::confirmSave() {
    printf("+--------------------------+\n");
    printf("|Save changes or not? (Y/N)|\n");
    printf("+--------------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'N' || ch == 'n') return false;
    if (ch == 'Y' || ch == 'y') return true;
    return confirmSave();
}

int Interface::chooseRole() {
    printf("+---------------------------------------------+\n");
    printf("|Choose your role, Customer or Merchant. (C/M)|\n");
    printf("+---------------------------------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'C' || ch == 'c') return 0;
    if (ch == 'M' || ch == 'm') return 1;
    return chooseRole();
}

int Interface::chooseType() {
    printf("+--------------------------------------------------------+\n");
    printf("|Choose the type, Book or Clothing or Electronic. (B/C/E)|\n");
    printf("+--------------------------------------------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'B' || ch == 'b') return 0;
    if (ch == 'C' || ch == 'c') return 1;
    if (ch == 'E' || ch == 'e') return 2;
    return chooseType();
}

void Interface::listItems() {
    printf("+-------------------+\n");
    printf("|Choose the keyword.|\n");
    printf("|A: All             |\n");
    printf("|N: Name            |\n");
    printf("|T: Type            |\n");
    printf("+-------------------+\n");
    char ch;
    std::cin >> ch;
    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (ch == 'A' || ch == 'a') {
        std::string kind;
        std::ifstream in;
        size_t block;
        for (int type = 0; type < 3; type++) {
            if (type == 0) block = sizeof(Book), kind = "Book";
            else if (type == 1) block = sizeof(Clothing), kind = "Clothing";
            else block = sizeof(Electronic), kind = "Electronic";
            in.open(COMMODITY_FILE[type], std::ios::binary);
            in.seekg(0, std::ios::end);
            size_t size = in.tellg() / block;
            in.seekg(0, std::ios::beg);
            Commodity *ret = NULL;
            if (type == 0) ret = new Book();
            else if (type == 1) ret = new Clothing();
            else ret = new Electronic();
            for (int index = 0; index < size; index++) {
                in.read((char *)ret, block);
                std::cout << kind << std::endl;
                ret->listInfo();
            }
            in.close();
        }
    }
    else if (ch == 'N' || ch == 'n') {
        printf("+--------------------------------+\n");
        printf("|Input the name of the commodity.|\n");
        printf("+--------------------------------+\n");
        std::string name, kind;
        std::getline(std::cin, name);
        std::ifstream in;
        size_t block;
        for (int type = 0; type < 3; type++) {
            if (type == 0) block = sizeof(Book), kind = "Book";
            else if (type == 1) block = sizeof(Clothing), kind = "Clothing";
            else block = sizeof(Electronic), kind = "Electronic";
            in.open(COMMODITY_FILE[type], std::ios::binary);
            in.seekg(0, std::ios::end);
            size_t size = in.tellg() / block;
            in.seekg(0, std::ios::beg);
            Commodity *ret = NULL;
            if (type == 0) ret = new Book();
            else if (type == 1) ret = new Clothing();
            else ret = new Electronic();
            for (int index = 0; index < size; index++) {
                in.read((char *)ret, block);
                std::string str(ret->name);
                if (str == name) {
                    std::cout << kind << std::endl;
                    ret->listInfo();
                }
            }
            in.close();
        }
    }
    else if (ch == 'T' || ch == 't') {
        printf("+----------------+\n");
        printf("|Choose the type.|\n");
        printf("|B: Book         |\n");
        printf("|C: Clothing     |\n");
        printf("|E: Electronic   |\n");
        printf("+----------------+\n");
        std::cin >> ch;
        std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int type;
        if (ch == 'B' || ch == 'b') type = 0;
        else if (ch == 'C' || ch == 'c') type = 1;
        else if (ch == 'E' || ch == 'e') type = 2;
        else {
            printf("Command not exist.\n");
            listItems();
        }
        std::ifstream in;
        size_t block;
        if (type == 0) block = sizeof(Book);
        else if (type == 1) block = sizeof(Clothing);
        else block = sizeof(Electronic);
        in.open(COMMODITY_FILE[type], std::ios::binary);
        in.seekg(0, std::ios::end);
        size_t size = in.tellg() / block;
        in.seekg(0, std::ios::beg);
        Commodity *ret = NULL;
        if (type == 0) ret = new Book();
        else if (type == 1) ret = new Clothing();
        else ret = new Electronic();
        for (int index = 0; index < size; index++) {
            in.read((char *)ret, block);
            ret->listInfo();
        }
        in.close();
    }
    else {
        printf("Command not exist.\n");
        listItems();
        return;
    }
    printf("That's all!!!\n");
}