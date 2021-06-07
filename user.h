#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
const int N = 50;

class User {
private:
    char nickname[N];
    char passwd[N];
public:
    char uid[N];
    char email[N];
    User();
    User(std::string uid, std::string email, std::string nickname, std::string passwd);
    bool checkPasswd(std::string str);
    virtual ~User();
    virtual int getUserType() = 0;
    virtual void methodList() = 0;
    void changePasswd();
};



#endif