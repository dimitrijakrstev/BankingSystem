//
//  Menu.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 6.4.25.
//
#ifndef MENU_H
#define MENU_H
#include "BankAccount.h"
#include "Vector.h"



class Menu {
private:
    void showOptions();
    Vector accounts; // this stores all accounts created during this run
    BankAccount* currentUser = nullptr;  // Pointer to the currently logged-in user
public:
    void run();
    size_t findAccountIndex(const std::string& name, const std::string& password);
};

#endif 
