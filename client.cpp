#include "client.h"
#include "interface.h"
#include "customer.h"
#include "merchant.h"

Client::Client() {}

Client::~Client() {}

void Client::setClient(std::string str) {
    int len = str.size();
    if (len > 50) {
        printf("Too long! Only the first 50 words are taken.\n");
        len = 50;
    }
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

User *Client::registerAccount() {
    size_t block;
    std::ifstream in;
    if (role){
        block = sizeof(Merchant);
        in.open("data/merchant.dat", std::ios::binary);
    }
    else {
        block = sizeof(Customer);
        in.open("data/customer.dat", std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    size_t size = in.tellg() / block;
    in.close();
    strcpy(uid, std::to_string(size + 100000).c_str());
    std::string nickname, passwd;
    printf("Input your nickname\n");
    std::cin >> nickname;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printf("Input your passwd\n");
    std::cin >> passwd;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    User *p;
    std::ofstream out;
    if (role){
        std::string _uid(uid), _email(email);
        p = new Merchant(_uid, _email, nickname, passwd);
        out.open("data/merchant.dat", std::ios::binary|std::ios::app);
    }
    else {
        std::string _uid(uid), _email(email);
        p = new Customer(_uid, _email, nickname, passwd);
        out.open("data/customer.dat", std::ios::binary|std::ios::app);
    }
    out.write((char *)p, block);
    out.close();
    return p;
}

User *Client::Login() {
    Interface tool;
    role = tool.chooseRole();
    while (true) {
        printf("Input your [e-mail address] or [UID] to login, or input your [e-mail address] to register\n");
        std::string tempStr;
        std::cin >> tempStr;
        if(tempStr == "q") return (User *)-1;
        setClient(tempStr);
        User *u;
        if (uidLegal()) u = uidQuery();
        else if (emailLegal()) u = emailQuery();
        else continue;
        if (u == (User *)-1) continue;
        int cnt = 3;
        while (cnt--) {
            std::string str;
            printf("Input your password:\n");
            char *buf = tool.getPasswd();
            str = buf;
            if (!u->checkPasswd(str) && cnt) printf("Wrong password. %d more chance.\n", cnt);
            else {
                delete buf;break;
            }
        }
        if (cnt >= 0) {
            // u->getUserType();
            u->methodList();
            return u;
        }
        else {
            printf("Fail to log in. You can enter 'q' to quit.\n");
        }
    }
}

User *Client::uidQuery() {
    int index = atoi(uid) - 100000;
    size_t block;
    std::ifstream in;
    if (role){
        block = sizeof(Merchant);
        in.open("data/merchant.dat", std::ios::binary);
    }
    else {
        block = sizeof(Customer);
        in.open("data/customer.dat", std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    size_t size = in.tellg() / block;
    if (index < 0 || index >= size) {
        printf("UID not found\n");
        return (User *) -1;
    }
    in.seekg(index * block, std::ios::beg);
    User *ret;
    if (role) ret = new Merchant;
    else ret = new Customer;
    in.read((char *)ret, block);
    in.close();
    return ret;
}

User *Client::emailQuery() {
    size_t block;
    std::ifstream in;
    if (role){
        block = sizeof(Merchant);
        in.open("data/merchant.dat", std::ios::binary);
    }
    else {
        block = sizeof(Customer);
        in.open("data/customer.dat", std::ios::binary);
    }
    in.seekg(0, std::ios::end);
    size_t size = in.tellg() / block;
    in.seekg(0, std::ios::beg);
    User *ret;
    if (role) ret = new Merchant;
    else ret = new Customer;
    for (int index = 0; index < size; index++) {
        in.read((char *)ret, block);
        if (!strcmp(ret->email, email)) {
            in.close();
            return ret;
        }
        in.seekg(block, std::ios::cur);
    }
    in.close();
    Interface tool;
    if (tool.confirmRegister()) return registerAccount();
    else return (User *) -1;
}

bool Client::validChar(char ch) {
    if ((ch >= 'A') && (ch <= 'Z')) return true;
    if ((ch >= 'a') && (ch <= 'z')) return true;
    if ((ch >= '0') && (ch <= '9')) return true;
    if ( ch == '_' || ch == '-' || ch == '.' || ch == '@' ) return true;
    return false;
}

bool Client::uidLegal() {
    if (strlen(uid) == 0) return false;
    for (int i = 0; uid[i]; i++) {
        if (uid[i] < '0' || uid[i] > '9') return false;
    }
    return true;
}

bool Client::emailLegal() {
    std::string str(email);
    if (str.length() < 5) return false;
    char ch = str[0];
    if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || (ch >= '0') && (ch <= '9')) {
        int atCount =0;
        int atPos = 0;
        int dotCount = 0;
        for(int i = 1; i < str.length(); i++) {
            ch = str[i];
            if (validChar(ch)) {
                if (ch=='@') {
                    atCount ++;
                    atPos = i;
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

void Client::methodList() {
    printf("L: Login\n");
    printf("H: Help\n");
    printf("Q: Quit\n");
    char ch;
    while (true) {
        std::cin >> ch;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (ch == 'L' || ch == 'l') {
            User *u = Login(); 
            if (u == (User *)-1) continue;
            delete u;
            methodList();
        }
        else if (ch == 'H' || ch == 'h') {
            methodList(); return;
        }
        else if (ch == 'Q' || ch == 'q') {
            return;
        }
        else printf("Command not exist.\n");
    }
}