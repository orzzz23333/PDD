#include "commodity.h"
#include "user.h"

Commodity::Commodity() {
    memset(name, 0, sizeof(name));
    memset(info, 0, sizeof(info));
}

Commodity::Commodity(int BELONG, int ID, std::string NAME, int PRICE, int INVENTORY, int DISCOUNT, std::string INFO)
    : belong(BELONG), id(ID), price(PRICE), inventory(INVENTORY), discount(DISCOUNT) {
    memset(name, 0, sizeof(name)); NAME.copy(name, NAME.size());
    memset(info, 0, sizeof(info)); INFO.copy(info, INFO.size());
}

Commodity::~Commodity() {}

bool Commodity::dispatch(int x) {
    if (x > inventory) {
        printf("Inventory not enough.\n");
        return false;
    }
    inventory -= x;
    saveData();
    return true;
}

bool Commodity::stock(int x) {
    if(x >= MAX_INVENTORY - inventory) inventory = MAX_INVENTORY;
    else inventory += x;
    saveData(); return true;
}

void Commodity::listInfo() {
    printf("ID: %d\nName: %s\nList Price: %d\nCurrent Price: %.2f\nDiscount: %d%% off\n", id, name, price, getPrice(), discount);
    printf("Inventory: %d piece(s) left\nInfo: %s\n", inventory, info);
}

bool Commodity::changeDiscount(int x) {
    if (x < 0 || x > 100) {
        printf("Unreasonable discount!\n");
        return false;
    }
    discount = x;
    saveData(); return true;
}

/*---------BOOK---------*/

Book::Book(){};

Book::Book(int BELONG, int ID, std::string NAME, int PRICE, int INVENTORY, int DISCOUNT, std::string INFO)
    : Commodity(BELONG, ID, NAME, PRICE, INVENTORY, DISCOUNT, INFO) {}

Book::~Book() {}

double Book::getPrice() {
    return (1.0 - 1.0 * discount / 100) * price;
}

void Book::saveData() {
    std::fstream out(COMMODITY_FILE[0], std::ios::binary|std::ios::out|std::ios::in);
    out.seekp((id - 1000) * sizeof(Book), std::ios::beg);
    out.write((char *)this, sizeof(Book));
    out.close();
}

/*---------CLOTHING---------*/

Clothing::Clothing() {}

Clothing::Clothing(int BELONG, int ID, std::string NAME, int PRICE, int INVENTORY, int DISCOUNT, std::string INFO)
    : Commodity(BELONG, ID, NAME, PRICE, INVENTORY, DISCOUNT, INFO) {}

Clothing::~Clothing() {}

double Clothing::getPrice() {
    return (1.0 - 1.0 * discount / 100) * price;
}

void Clothing::saveData() {
    std::fstream out(COMMODITY_FILE[1], std::ios::binary|std::ios::out|std::ios::in);
    out.seekp((id - 2000) * sizeof(Clothing), std::ios::beg);
    out.write((char *)this, sizeof(Clothing));
    out.close();
}

/*---------ELECTRONIC---------*/

Electronic::Electronic(){}

Electronic::Electronic(int BELONG, int ID, std::string NAME, int PRICE, int INVENTORY, int DISCOUNT, std::string INFO)
    : Commodity(BELONG, ID, NAME, PRICE, INVENTORY, DISCOUNT, INFO) {}

Electronic::~Electronic() {}

double Electronic::getPrice() {
    return (1.0 - 1.0 * discount / 100) * price;
}

void Electronic::saveData() {
    std::fstream out(COMMODITY_FILE[2], std::ios::binary|std::ios::out|std::ios::in);
    out.seekp((id - 3000) * sizeof(Electronic), std::ios::beg);
    out.write((char *)this, sizeof(Electronic));
    out.close();
}
