#ifndef COMMODITY_H
#define COMMODITY_H

#include <bits/stdc++.h>
#include <qstring.h>

const int MAX_LEN = 100;
const int MAX_INVENTORY = 9999;

class Commodity {
private:
public:
    int id;
    QString name;
    int price;
    QString cid;
    QString mid;
    Commodity();
    Commodity(int ID, QString NAME, int PRICE, QString CID, QString MID);
    virtual ~Commodity();
    virtual double getPrice() = 0;
};

class Book : public Commodity {
private:
public:
    Book();
    Book(int ID, QString NAME, int PRICE, QString CID, QString MID);
    ~Book();
    double getPrice();
};

class Clothing : public Commodity {
private:
public:
    Clothing();
    Clothing(int ID, QString NAME, int PRICE, QString CID, QString MID);
    ~Clothing();
    double getPrice();
};

class Food : public Commodity {
private:
public:
    Food();
    Food(int ID, QString NAME, int PRICE, QString CID, QString MID);
    ~Food();
    double getPrice();
};

#endif
