#ifndef MANAGEUSER_H
#define MANAGEUSER_H

#include <QWidget>
#include "warning.h"
#include "user.h"

namespace Ui {
class ManageUser;
}

class ManageUser : public QWidget
{
    Q_OBJECT

public:
    explicit ManageUser(User *u, QWidget *parent = nullptr);
    ~ManageUser();

private slots:
    void on_pushButton_2_clicked();

    void on_rechargeButton_clicked();

    void on_changePasswdButton_clicked();

private:
    Ui::ManageUser *ui;
    warning *warn;
    User *u;
};

#endif // MANAGEUSER_H
