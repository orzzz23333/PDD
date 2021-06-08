#ifndef INTERFACE_H
#define INTERFACE_H

#include <bits/stdc++.h>
#include <conio.h>

class Interface {
public:
    char *getPasswd();
    bool confirmRegister();
    bool confirmSave();
    int chooseRole();
};

#endif