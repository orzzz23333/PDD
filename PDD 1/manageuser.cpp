#include "manageuser.h"
#include "ui_manageuser.h"
#include <QDoubleValidator>

ManageUser::ManageUser(User *u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageUser), u(u) {
    ui->setupUi(this);
    warn = new warning;
    ui->nickname->setText(u->nickname);
    std::string balance = std::to_string(u->getBalance());
    balance = balance.substr(0, balance.length() - 4);
    ui->balance->setText(QString::fromStdString(balance));
    QDoubleValidator* lineDouble = new QDoubleValidator(0, 1000000, 2, nullptr);
    ui->rechargeInput->setValidator(lineDouble);
    ui->oldPasswdInput->setEchoMode(QLineEdit::Password);
    ui->newPasswdInput->setEchoMode(QLineEdit::Password);
}

ManageUser::~ManageUser() {
    delete ui;
    delete warn;
}

void ManageUser::on_pushButton_2_clicked() {
    this->close();
}

void ManageUser::on_rechargeButton_clicked() {
    u->recharge(ui->rechargeInput->text().toDouble());
    std::string balance = std::to_string(u->getBalance());
    balance = balance.substr(0, balance.length() - 4);
    ui->balance->setText(QString::fromStdString(balance));
    warn->setText("充值成功！");
    warn->show();
}

void ManageUser::on_changePasswdButton_clicked() {
    std::string oldPasswd = ui->oldPasswdInput->text().toStdString();
    std::string newPasswd = ui->newPasswdInput->text().toStdString();
    if (u->changePasswd(oldPasswd, newPasswd)) {
        warn->setText("修改密码成功！");
        warn->show();
    }
    else {
        warn->setText("旧密码错误！");
        warn->show();
    }
}
