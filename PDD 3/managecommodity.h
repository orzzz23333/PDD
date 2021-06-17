#ifndef MANAGECOMMODITY_H
#define MANAGECOMMODITY_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "warning.h"
#include "user.h"
#include "client.h"

namespace Ui {
class ManageCommodity;
}

class ManageCommodity : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageCommodity(User *u, Client *client, QWidget *parent = nullptr);
    ~ManageCommodity();

private slots:
    void on_pushButton_2_clicked();

    void on_IDInput_editingFinished();

    void on_modifyButton_clicked();

    void on_addButton_clicked();

    void on_discountButton_clicked();

    void generateModel();
signals:
    void finished();
private:
    Ui::ManageCommodity *ui;
    User *u;
    warning *warn;
    Client *client;
    QStringList model;
};

#endif // MANAGECOMMODITY_H
