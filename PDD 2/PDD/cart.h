#ifndef CART_H
#define CART_H

#include <QWidget>
#include <bits/stdc++.h>
#include "warning.h"
#include "user.h"
#include "buy.h"
#include <qsqlquerymodel.h>

namespace Ui {
class Cart;
}

class Cart : public QWidget
{
    Q_OBJECT

public:
    explicit Cart(User *u, QWidget *parent = nullptr);
    ~Cart();

private slots:
    void on_cartButton_clicked();

    void on_dealButton_2_clicked();

    void on_modifyButton_clicked();

    void init();

    void on_dealButton_clicked();

    void on_cancelButton_clicked(int tot = -1);

    void on_buyButton_clicked();

private:
    Ui::Cart *ui;
    User *u;
    Buy *buy;
    warning *warn;
    double totMoney;
};

#endif // CART_H
