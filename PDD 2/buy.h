#ifndef BUY_H
#define BUY_H

#include <QWidget>
#include <bits/stdc++.h>
#include "warning.h"
#include "user.h"

namespace Ui {
class Buy;
}

class Buy : public QWidget
{
    Q_OBJECT

public:
    explicit Buy(User *u, QWidget *parent = nullptr);
    ~Buy();

private slots:
    void on_pushButton_2_clicked();

    void on_IDInput_editingFinished();

    void on_buyButton_clicked();

    void on_cartButton_clicked();

private:
    Ui::Buy *ui;
    User *u;
    warning *warn;
};

#endif // BUY_H
