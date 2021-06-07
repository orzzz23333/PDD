#include "user.h"
#include "interface.h"

User::User() {
    memset(uid, 0, sizeof(uid));
    memset(email, 0, sizeof(email));
    memset(nickname, 0, sizeof(nickname));
    memset(passwd, 0, sizeof(passwd));
}
User::User(std::string UID, std::string EMAIL, std::string NICKNAME, std::string PASSWD) {
    memset(uid, 0, sizeof(uid)); UID.copy(uid, UID.size());
    memset(email, 0, sizeof(email)); EMAIL.copy(email, EMAIL.size());
    memset(nickname, 0, sizeof(nickname)); NICKNAME.copy(nickname, NICKNAME.size());
    memset(passwd, 0, sizeof(passwd)); PASSWD.copy(passwd, PASSWD.size());
    printf("Hello, %s! Your UID is %s.\n", nickname, uid);
}

User::~User() {}

bool User::checkPasswd(std::string str) {
    if(!strcmp(str.c_str(), passwd)) {
        printf("Welcome, %s\n", nickname);
        return true;
    }
    return false;
}

void User::changePasswd() {
    Interface tool;
    int cnt = 3;
    while (cnt--) {
        std::string str;
        printf("Input your password:\n");
        char *buf = tool.getPasswd();
        str = buf;
        if (!checkPasswd(str) && cnt) printf("Wrong password. %d more chance.\n", cnt);
        else {
            delete buf;break;
        }
    }
    if (cnt < 0) {
        printf("Fail to change.\n");
        return;
    }
    char *buf = tool.getPasswd();
    for (int i = 0; i < strlen(buf); i++) passwd[i] = buf[i];
    printf("Success!\n");
}