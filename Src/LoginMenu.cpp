//
//  LoginMenu.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 1.5.25.
//
#include "LoginMenu.h"
#include "CheckingAccount.h"
#include "BankAccount.h"
#include "SavingsAccount.h"
#include <iostream>

using namespace std;

void LoginMenu::runLogin() {
    double amount = 0;
    int choice;
    do {
        showLoginOptions();
        cout << "Enter action \n" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                cout << "Enter amount! \n" << endl;
                cin >> amount;
                account->deposit(amount);
                cout << "Current Balance: " << account->getBalance() << endl;
                break;
            }
            case 2: {
                cout << "Enter amount! \n" << endl;
                cin >> amount;
                account->withdraw(amount);
                cout << "Current Balance: " << account->getBalance() << endl;
                break;
            }
            case 3: {
                cout << "Your Balance is: \n";
                account->displayBalance();
                cout << "\n";
                break;
            }
            case 4: {
                cout <<"\n";
                account->displayAccDetails();
                break;
            }
            case 5: {
                if (account->getTypeOfAccount() == "savings") {
                    std::cout << "Error: Cannot display details for savings account in this option.\n";
                    break;
                } else {
                    cout << "Overdraft Limit: " << account->getOverdraftLimit() << endl;
                    cout << "Transaction Fee: " << account->getTransactionFee() << endl;
                    break;
                }
            }
            case 6: {
                if (account->getTypeOfAccount() == "checking") {
                    std::cout << "Error: Cannot display details for checking account in this option.\n";
                    break;
                } else {
                    cout << "Interest Rate: " << account->getInterestRate() << endl;
                    break;
                }
            }
            case 7: {
                std::string confirm;
                std::cout << "Are you sure you want to delete this account? Type YES to confirm: ";
                std::cin >> confirm;
                if (confirm == "YES") {
                    deleteRequested = true;
                    std::cout << "Account will be deleted.\n";
                    return; // Exit login loop
                } else {
                    std::cout << "Deletion canceled.\n";
                }
                break;
            }
                
            case 10: {
                cout << "Logging Out: " << endl;
                return;
            }
            default:
                cout << "Invalid option!\n";
                break;
        }
    }
    while (true);
};

void LoginMenu::showLoginOptions() {
    cout << "\n==== ACCOUNT MENU ====\n";
    cout << "1. Deposit Money \n";
    cout << "2. Withdraw Money \n";
    cout << "3. Display Balance \n";
    cout << "4. Display Account Details \n";
    cout << "5. Check Overdraft Limit and Transaction fee (only for checking account) \n";
    cout << "6. Check Interest Rate (only for savings account) \n";
    cout << "7. Delete Account \n";
    cout << "10. Logout \n";
    cout << "==========================\n";
};
