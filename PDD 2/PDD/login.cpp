#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->passwdInput->setEchoMode(QLineEdit::Password);
    u = NULL;
    warn = new warning;
}

Login::~Login()
{
    delete ui;
    delete u;
    delete reg;
    delete warn;
}
int Login::getUserType() {
    return u->getUserType();
}
void Login::setLogin(std::string str) {
    int len = str.size();
    if (len > 50) len = 50;
    memset(uid, 0, sizeof(uid));str.copy(uid, len);
    memset(email, 0, sizeof(email));str.copy(email, len);
    if (uidLegal()) memset(email, 0, sizeof(email));
    else if (emailLegal()) memset(uid, 0, sizeof(uid));
    else {
        printf("Not a uid or e-mail address\n");
        memset(uid, 0, sizeof(uid));
        memset(email, 0, sizeof(email));
    }
}

void Login::uidQuery() {
    int index = atoi(uid) - 100000;
    size_t block;
    std::ifstream in;
    if (role == 1) {
        block = sizeof(Merchant);
        in.open(USER_FILE[1], std::ios::binary);
    }
    else if (role == 0) {
        block = sizeof(Customer);
        in.open(USER_FILE[0], std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    int size = in.tellg() / block;
    if (index < 0 || index >= size) {
        printf("UID not found\n");
        u = (User *) -1;
        return;
    }
    in.seekg(index * block, std::ios::beg);
    if (role == 1) u = new Merchant;
    else if (role == 0) u = new Customer;
    in.read((char *)u, block);
    in.close();
}

void Login::emailQuery() {
    size_t block;
    std::ifstream in;
    if (role){
        block = sizeof(Merchant);
        in.open(USER_FILE[1], std::ios::binary);
    }
    else {
        block = sizeof(Customer);
        in.open(USER_FILE[0], std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    int size = in.tellg() / block;
    in.seekg(0, std::ios::beg);
    if (role) u = new Merchant;
    else u = new Customer;
    for (int index = 0; index < size; index++) {
        in.read((char *)u, block);
        if (!strcmp(u->email, email)) {
            in.close();
            return;
        }
    }
    in.close();
    u = (User *)-1;
}

bool Login::validChar(char ch) const{
    if ((ch >= 'A') && (ch <= 'Z')) return true;
    if ((ch >= 'a') && (ch <= 'z')) return true;
    if ((ch >= '0') && (ch <= '9')) return true;
    if ( ch == '_' || ch == '-' || ch == '.' || ch == '@' ) return true;
    return false;
}

bool Login::uidLegal() const{
    if (strlen(uid) == 0) return false;
    for (int i = 0; uid[i]; i++) {
        if (uid[i] < '0' || uid[i] > '9') return false;
    }
    return true;
}

bool Login::emailLegal() const{
    std::string str(email);
    if (str.length() < 5) return false;
    char ch = str[0];
    if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9'))) {
        int atCount =0;
        int dotCount = 0;
        for(int i = 1, len = str.length(); i < len; i++) {
            ch = str[i];
            if (validChar(ch)) {
                if (ch=='@') {
                    atCount ++;
                }
                else if ((atCount > 0) && (ch == '.')) dotCount ++;
            }
            else return false;
        }
        if (ch == '@') return false;
        if (atCount != 1 || dotCount < 1 || dotCount > 3 ) return false;
        int x = str.find("@."), y = str.find(".@");
        if (x > 0 || y > 0) return false;
        return true;
    }
    return false;
}

void Login::on_pushButton_clicked() {
    if (ui->isCustomer->checkState() == Qt::CheckState::Checked) role = 0;
    else if (ui->isMerchant->checkState() == Qt::CheckState::Checked) role = 1;
    else {
        warn->setText("请先选择用户类型！");
        warn->show();
        return;
    }
    std::string name = ui->nameInput->text().toStdString();
    setLogin(name);
    if (uidLegal()) {
        uidQuery();
        if (u == (User *)-1) {
            warn->setText("用户不存在！");
            warn->show();
            return;
        }
    }
    else if (emailLegal()) {
        emailQuery();
        if (u == (User *)-1) {
            std::string _email(email);
            reg = new Register(role, _email);
            reg->show();
            return;
        }
    }
    else {
        warn->setText("用户名不是一个UID或邮箱！");
        warn->show();
        return;
    }

    std::string pw = ui->passwdInput->text().toStdString();
    if (!u->checkPasswd(pw)) {
        warn->setText("密码错误！");
        warn->show();
//        delete u;
        u = NULL;
    }
    else {
        std::string text(u->nickname);
        text = "欢迎您，" + text + "!";
        warn->setText(text);
        warn->show();
        this->close();
    }
}

void Login::on_isCustomer_stateChanged(int arg1){
    if (arg1 == Qt::CheckState::Checked) {
        ui->isMerchant->blockSignals(true);
        ui->isMerchant->setCheckState(Qt::CheckState::Unchecked);
        ui->isMerchant->blockSignals(false);
    }
}

void Login::on_isMerchant_stateChanged(int arg1)
{
    if (arg1 == Qt::CheckState::Checked) {
        ui->isCustomer->blockSignals(true);
        ui->isCustomer->setCheckState(Qt::CheckState::Unchecked);
        ui->isCustomer->blockSignals(false);
    }
}

void Login::on_pushButton_2_clicked() {
    this->close();
}
