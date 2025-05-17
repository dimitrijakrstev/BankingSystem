//
//  LoginMenu.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 1.5.25.
//
#ifndef LOGINMENU_H
#define LOGINMENU_H

#include "BankAccount.h"
#include <vector>

class LoginMenu {
private:
    BankAccount* account;
    bool deleteRequested = false;
public:
    LoginMenu(BankAccount* acc) : account(acc) {}
    void showLoginOptions();
    void runLogin();
    bool shouldDeleteAccount() const { return deleteRequested; }
};

#endif
