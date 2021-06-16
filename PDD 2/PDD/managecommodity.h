#ifndef MANAGECOMMODITY_H
#define MANAGECOMMODITY_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "warning.h"
#include "user.h"

namespace Ui {
class ManageCommodity;
}

class ManageCommodity : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageCommodity(User *u, QWidget *parent = nullptr);
    ~ManageCommodity();

private slots:
    void on_pushButton_2_clicked();

    void on_IDInput_editingFinished();

    void on_modifyButton_clicked();

    void on_addButton_clicked();

    void on_discountButton_clicked();

private:
    Ui::ManageCommodity *ui;
    User *u;
    warning *warn;

};

#endif // MANAGECOMMODITY_H
