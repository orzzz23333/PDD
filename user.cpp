#include "user.h"
#include "interface.h"

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
    printf("Hello, %s! Your UID is %s.\n", nickname, uid);
}

User::~User() {}

bool User::checkPasswd(std::string str) {
    if(!strcmp(str.c_str(), passwd)) {
        printf("Welcome, %s\n", nickname);
        return true;
    }
    return false;
}

void User::changePasswd() {
    Interface tool;
    int cnt = 3;
    while (cnt--) {
        std::string str;
        printf("+--------------------+\n");
        printf("|Input your password.|\n");
        printf("+--------------------+\n");
        char *buf = tool.getPasswd();
        str = buf;
        if (!checkPasswd(str) && cnt) printf("Wrong password. %d more chance.\n", cnt);
        else {
            delete[] buf;break;
        }
    }
    if (cnt < 0) {
        printf("Fail to change.\n");
        return;
    }
    printf("Input your new password.\n");
    char *buf = tool.getPasswd();
    memset(passwd, 0, sizeof(passwd));
    for (int i = 0; i < strlen(buf); i++) passwd[i] = buf[i];
    saveData();
    delete[] buf;
    printf("Success!\n");
}

double User::getBalance() {
    printf("You have $%.2f left.\n", balance);
    return balance;
}

double User::recharge() {
    printf("+------------------------------------+\n");
    printf("|Input a number you want to recharge.|\n");
    printf("+------------------------------------+\n");
    double x;
    while(true) {
        if (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    if (x > MONEY_MAX - balance) balance = MONEY_MAX;
    else if (x < 0) {
        printf("Can't be negative number.\n");
        return balance;
    }
    else balance += x;
    saveData();
    printf("Success! You have $%.2f now.\n", balance);
    return balance;
}

void User::quit() {
    // Interface tool;
    // if(tool.confirmSave()) saveData();
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

void Customer::methodList() {
    getUserType();
    printf("+----------------------+\n");
    printf("|A: Search in all items|\n");
    printf("|B: Check balance      |\n");
    printf("|H: Help               |\n");
    printf("|P: Change password    |\n");
    printf("|Q: Logout             |\n");
    printf("|R: Recharge           |\n");
    printf("+----------------------+\n");
    char ch;
    while (true) {
        std::cin >> ch;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (ch == 'A' || ch == 'a') {
            Interface tool; tool.listItems();
        }
        else if (ch == 'B' || ch == 'b') {
            getBalance();
        }
        else if (ch == 'P' || ch == 'p') {
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

/*---------MERCHANT---------*/

Merchant::Merchant() {
    memset(list, 0, sizeof(list));
}

Merchant::Merchant(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD)
    : User(UID, EMAIL, NICKNAME, PASSWD) {
    memset(list, 0, sizeof(list));
}

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

Commodity *Merchant::addItem(std::string name, int type) {
    int price;
    printf("+----------------+\n");
    printf("|Input the price.|\n");
    printf("+----------------+\n");
    while(true) {
        if (!(std::cin >> price)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }

    std::ifstream in;
    int block;
    if (type == 0) block = sizeof(Book);
    else if (type == 1) block = sizeof(Clothing);
    else block = sizeof(Electronic);
    in.open(COMMODITY_FILE[type], std::ios::binary);
    in.seekg(0, std::ios::end);
    size_t size = in.tellg() / block;
    in.close();

    Commodity *p = NULL;
    if (type == 0) p = new Book(atoi(uid), size + 1000, name, price);
    else if (type == 1) p = new Clothing(atoi(uid), size + 2000, name, price);
    else p = new Electronic(atoi(uid), size + 3000, name, price);
    p->saveData();

    for(int i = 0; i < ITEM_MAX; i++)
    if(list[i] == 0) {
        list[i] = size + 1000 * (type + 1);
        break;
    }
    
    return p;
}

Commodity *Merchant::search() {
    Interface tool;
    int type = tool.chooseType();
    printf("+--------------------------------+\n");
    printf("|Input the name of the commodity.|\n");
    printf("+--------------------------------+\n");
    std::string name;
    std::getline(std::cin, name);
    // std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    size_t block;
    std::ifstream in;
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
        std::string str(ret->name);
        if (ret->belong == atoi(uid) && str == name) {
            in.close();
            return ret;
        }
    }
    in.close();

    if (tool.confirmAddItem()) return addItem(name, type);
    else return (Commodity *) -1;
}

void Merchant::changeInfo() {
    Commodity *p = search();
    if (p == (Commodity *)-1) {
        printf("Change Failed.\n");
        return;
    }
    p->listInfo();
    printf("+-----------------------------+\n");
    printf("|Rename. Input 'skip' to skip.|\n");
    printf("+-----------------------------+\n");
    std::string name;
    std::getline(std::cin, name);
    // std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (name != "skip") {
        memset(p->name, 0, sizeof(p->name)); name.copy(p->name, name.size());
    }
    int price = 0, discount = 0, inventory = 0;
    printf("+--------------------------+\n");
    printf("|Input new price. (integer)|\n");
    printf("+--------------------------+\n");
        while(true) {
        if (!(std::cin >> price)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    p->price = price;
    printf("+-------------------------------------+\n");
    printf("|Input new discount. (?%% off, integer)|\n");
    printf("+-------------------------------------+\n");
    while(true) {
        if (!(std::cin >> discount)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    p->changeDiscount(discount);
    printf("+--------------------+\n");
    printf("|Input new inventory.|\n");
    printf("+--------------------+\n");
    while(true) {
        if (!(std::cin >> inventory)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    p->inventory = inventory;
    printf("+----------------------------------+\n");
    printf("|Change Info. Input 'skip' to skip.|\n");
    printf("+----------------------------------+\n");
    std::cin.get(); std::getline(std::cin, name);
    // std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (name != "skip") {
        memset(p->info, 0, sizeof(p->info)); name.copy(p->info, name.size());
    }
    p->saveData();
    printf("Success! Data now:\n");
    p->listInfo();
    delete p;
}

void Merchant::stock() {
    Commodity *p = search();
    if (p == (Commodity *)-1) {
        printf("Stock Failed.\n");
        return;
    }
    p->listInfo();
    printf("+---------------------------+\n");
    printf("|Input the number you stock.|\n");
    printf("+---------------------------+\n");
    int x = 0;
    while(true) {
        if (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Bad Input!\n");
        }
        else break;
    }
    p->stock(x);
    printf("Success!\n");
    delete p;
}

void Merchant::methodList() {
    getUserType();
    printf("+-------------------------+\n");
    printf("|A: Search in all items   |\n");
    printf("|B: Check balance         |\n");
    printf("|C: Change info of an item|\n");
    printf("|H: Help                  |\n");
    printf("|P: Change password       |\n");
    printf("|Q: Logout                |\n");
    printf("|R: Recharge              |\n");
    printf("|S: Stock                 |\n");
    printf("+-------------------------+\n");
    char ch;
    while (true) {
        std::cin >> ch;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (ch == 'A' || ch == 'a') {
            Interface tool; tool.listItems();
        }
        else if (ch == 'B' || ch == 'b') {
            getBalance();
        }
        else if (ch == 'P' || ch == 'p') {
            changePasswd();
        }
        else if (ch == 'C' || ch == 'c') {
            changeInfo();
        }
        else if (ch == 'H' || ch == 'h') {
            methodList(); return;
        }
        else if (ch == 'R' || ch == 'r') {
            recharge();
        }
        else if (ch == 'S' || ch == 's') {
            stock();
        }
        else if (ch == 'Q' || ch == 'q') {
            quit();return;
        }
        else printf("Command not exist.\n");
    }
}