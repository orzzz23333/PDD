#ifndef CART_H
#define CART_H

#include <QWidget>
#include <bits/stdc++.h>
#include "warning.h"
#include "user.h"
#include "buy.h"
#include "client.h"

namespace Ui {
class Cart;
}

class Cart : public QWidget
{
    Q_OBJECT

public:
    explicit Cart(User *u, Client *client, QWidget *parent = nullptr);
    ~Cart();
    void showTable(int col);

private slots:
    void on_cartButton_clicked();

    void on_dealButton_2_clicked();

    void on_modifyButton_clicked();

    void init();

    void on_dealButton_clicked();

    void on_cancelButton_clicked(int tot = -1);

    void on_buyButton_clicked();

    void generateModel();
signals:
    void finished();
private:
    Ui::Cart *ui;
    User *u;
    Buy *buy;
    warning *warn;
    double totMoney;
    Client *client;
    QStringList model;
};

#endif // CART_H
