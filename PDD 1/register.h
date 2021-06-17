#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "user.h"
#include "warning.h"
#include <string.h>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(int role, std::string email, QWidget *parent = nullptr);
    ~Register();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Register *ui;
    int role;
    std::string email;
    warning *warn;
};

#endif // REGISTER_H
