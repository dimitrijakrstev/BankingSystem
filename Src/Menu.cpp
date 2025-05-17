//
//  Menu.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 6.4.25.
//
#include "Menu.h"
#include "BankAccount.h"
#include "LoginMenu.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>


using namespace std;

void Menu::run() {
    int choice;
    do {
        showOptions();
        cout << "Enter action \n" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string user, pass, accID, type, input;
                double balance, transacfee = 0.0, overlimit = 0.0, interrate = 0.0;
                
                while (true) {
                    try {
                        cout << "Enter Account holder full name \n";
                        getline(cin, user);
                        for (char ch : user) {
                            if (!isalpha(ch) && !isspace(ch)) {
                                throw invalid_argument("Name must only contain letters and spaces.");
                            }
                        }
                        if (user.empty()) {
                            throw invalid_argument("Name cannot be empty.");
                        }
                        break;
                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
                cout << "Enter password \n";
                cin >> pass;
                int randID = rand() % 900000 + 100000; // Random 6-digit number (100000 to 999999)
                accID = to_string(randID);
                cout << "Generated Account ID: " << accID << "\n";
                
                while (true) {
                    try {
                        cout << "Enter type of Account (checking or savings): ";
                        cin >> type;
                        transform(type.begin(), type.end(), type.begin(), ::tolower);

                        if (type == "checking") {

                            while (true) {
                                cout << "Enter Transaction Fee: ";
                                if ((cin >> transacfee) && transacfee >= 0) break;

                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cerr << "Error: Transaction fee must be a non-negative number." << endl;
                            }

                            while (true) {
                                cout << "Enter Overdraft Limit: ";
                                if ((cin >> overlimit) && overlimit >= 0) break;

                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cerr << "Error: Overdraft limit must be a non-negative number." << endl;
                            }

                            break; // all inputs valid -> exit outer loop

                        } else if (type == "savings") {

                            while (true) {
                                cout << "Enter Interest Rate: ";
                                if ((cin >> interrate) && interrate >= 0) break;

                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cerr << "Error: Interest rate must be a non-negative number." << endl;
                            }

                            break; // all inputs valid -> exit outer loop

                        } else {
                            throw invalid_argument("Invalid account type. Please enter 'checking' or 'savings'.");
                        }

                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                while (true) {
                    try {
                        std::cin.clear(); // Clear any fail flags
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush leftover input

                        std::cout << "Enter balance: ";
                        std::string input;
                        std::getline(std::cin, input);

                        input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
                        input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);

                        if (input.empty()) {
                            throw std::invalid_argument("Input cannot be empty.");
                        }

                        balance = std::stod(input);

                        if (balance < 0) {
                            throw std::invalid_argument("Balance must be non-negative.");
                        }

                        break; // valid input
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                }
                cout << "Creating Account... \n";
                if (type == "checking") {
                    accounts.push_back(new CheckingAccount(user, pass, accID, balance, overlimit, transacfee));
                } else if (type == "savings") {
                    accounts.push_back(new SavingsAccount(user, pass, accID, balance, interrate));
                }
                cout << "Account Created! \n";
                break;
            }
                
            case 2: {
                if (currentUser != nullptr) {
                    std::cout << "You're already logged in as " << currentUser->getAccountHolderName() << "!\n";
                    break;
                }

                std::string inputName, inputPass;
                std::cout << "Enter Account Holder Name: ";
                std::getline(std::cin, inputName);
                std::cout << "Enter Password: ";
                std::getline(std::cin, inputPass);

                size_t index = findAccountIndex(inputName, inputPass);
                if (index != accounts.getSize()) {
                    currentUser = accounts[index];
                    std::cout << "Login successful! Welcome, " << currentUser->getAccountHolderName() << ".\n";

                    LoginMenu loginMenu(currentUser);
                    loginMenu.runLogin();

                    if (loginMenu.shouldDeleteAccount()) {
                        accounts.removeAt(index);
                        std::cout << "Account deleted successfully.\n";
                        currentUser = nullptr;
                        break;  // ← prevent using deleted account
                    }

                    currentUser = nullptr;
                } else {
                    std::cout << "Login failed! Incorrect name or password.\n";
                }
                break;
            }
            case 3:
                cout << "Saving Account Data to accounts.txt" << endl;
                    for (BankAccount* account : accounts) {
                        account->saveToFile();  // polymorphic call
                    }
                    cout << "All accounts saved.\n";
                    break;
            case 4:
                cout << "Exiting program...\n";
                exit(0);

            default:
                cout << "Invalid choice!\n";
                break;
        }

    } while (choice != 10);  
}

void Menu::showOptions() {
    cout << "\n==== BANK SYSTEM MENU ====\n";
    cout << "1. Create Account \n";
    cout << "2. Login \n";
    cout << "3. Save Accounts Data \n";
    cout << "4. Exit \n";
    cout << "==========================\n";
}

size_t Menu::findAccountIndex(const std::string& name, const std::string& password) {
    for (size_t i = 0; i < accounts.getSize(); ++i) {
        if (accounts[i]->getAccountHolderName() == name &&
            accounts[i]->getPassword() == password) {
            return i;
        }
    }
    return accounts.getSize(); // Special value indicating "not found"
}
