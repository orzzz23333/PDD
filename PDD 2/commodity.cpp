#include "commodity.h"
#include "user.h"

Commodity::Commodity(int ID, QString NAME, int PRICE, QString CID, QString MID)
    : id(ID), name(NAME), price(PRICE), cid(CID), mid(MID) {}

Commodity::~Commodity() {}

/*---------BOOK---------*/

Book::Book(int ID, QString NAME, int PRICE, QString CID, QString MID)
    : Commodity(ID, NAME, PRICE, CID, MID) {}

Book::~Book() {}

double Book::getPrice() {
    return price;
}

/*---------CLOTHING---------*/

Clothing::Clothing(int ID, QString NAME, int PRICE, QString CID, QString MID)
    : Commodity(ID, NAME, PRICE, CID, MID) {}

Clothing::~Clothing() {}

double Clothing::getPrice() {
    return price;
}

/*---------FOOD---------*/

Food::Food(int ID, QString NAME, int PRICE, QString CID, QString MID)
    : Commodity(ID, NAME, PRICE, CID, MID) {}

Food::~Food() {}

double Food::getPrice() {
    return price;
}
