#ifndef COMMODITY_H
#define COMMODITY_H

#include <bits/stdc++.h>

const int MAX_LEN = 100;
const int MAX_INVENTORY = 9999;

class Commodity {
private:
    char info[MAX_LEN];
    int inventory;
public:
    int id;
    int price;
    int discount;
    char name[MAX_LEN];
    Commodity();
    Commodity(int ID, std::string NAME, int PRICE, int INVENTORY, int DISCOUNT, std::string INFO);
    virtual ~Commodity();
    virtual double getPrice() = 0;
    virtual void saveData() = 0;
    bool dispatch(int x);
    bool stock(int x);
    void listInfo();
    bool changeDiscount(int x);
};

class Book : public Commodity {
private:
public:
    Book();
    Book(int ID, std::string NAME, int PRICE, int INVENTORY = 0, int DISCOUNT = 0, std::string INFO = "NONE");
    ~Book();
    double getPrice();
    void saveData();
};

class Clothing : public Commodity {
private:
public:
    Clothing();
    Clothing(int ID, std::string NAME, int PRICE, int INVENTORY = 0, int DISCOUNT = 0, std::string INFO = "NONE");
    ~Clothing();
    double getPrice();
    void saveData();
};

class Electronic : public Commodity {
private:
public:
    Electronic();
    Electronic(int ID, std::string NAME, int PRICE, int INVENTORY = 0, int DISCOUNT = 0, std::string INFO = "NONE");
    ~Electronic();
    double getPrice();
    void saveData();
};

#endif