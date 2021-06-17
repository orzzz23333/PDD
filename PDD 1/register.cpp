#include "register.h"
#include "ui_register.h"

Register::Register(int role, std::string email, QWidget *parent) :
     QDialog(parent),
    ui(new Ui::Register), role(role), email(email) {
    ui->setupUi(this);
    ui->passwdInput->setEchoMode(QLineEdit::Password);
    warn = new warning;
}

Register::~Register() {
    delete ui;
    delete warn;
}

void Register::on_pushButton_clicked() {
    size_t block;
    std::ifstream in;
    if (role == 1){
        block = sizeof(Merchant);
        in.open(USER_FILE[1], std::ios::binary);
    }
    else if (role == 0) {
        block = sizeof(Customer);
        in.open(USER_FILE[0], std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    size_t size = in.tellg() / block;
    in.close();
    std::string uid;
    uid = std::to_string(size + 100000);
    std::string nickname, passwd;
    nickname = ui->nameInput->text().toStdString();
    passwd = ui->passwdInput->text().toStdString();
    User *p;
    std::ofstream out;
    if (role == 1){
        p = new Merchant(uid, email, nickname, passwd);
        out.open(USER_FILE[1], std::ios::binary|std::ios::app);
    }
    else if (role == 0) {
        p = new Customer(uid, email, nickname, passwd);
        out.open(USER_FILE[0], std::ios::binary|std::ios::app);
    }
    out.write((char *)p, block);
    out.close();
    std::string text = "注册成功，您的UID为" + uid;
    warn = new warning;
    warn->setText(text);
    warn->show();
    this->close();
}

void Register::on_pushButton_2_clicked(){
    this->close();
}
