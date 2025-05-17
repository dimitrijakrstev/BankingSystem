//
//  SavingsAccount.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 29.3.25.
//
#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

SavingsAccount::SavingsAccount(std::string& holderName, std::string& userPass, std::string& accountID, double initialBalance, double rate) : BankAccount(holderName, userPass, accountID, "savings", initialBalance), interestRate(rate) {}

void SavingsAccount::addMonthlyInterest() {
    double interest = getBalance() * interestRate / 12;
    deposit(interest);
}

void SavingsAccount::displayAccDetails() const {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|     Account Details      |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    
    std::cout << "Account Holder: " << getAccountHolderName() << std::endl;
    std::cout << "Account ID Number: " << getAccountIDNumber() << std::endl;
    std::cout << "Type of Account: " << getTypeOfAccount() << std::endl;
    std::cout << "Current Balance: " << getBalance() << std::endl;
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

void SavingsAccount::saveToFile() const {
    // Generate timestamp
    std::ostringstream filename;
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    filename << "accounts_" << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S") << ".txt";
    std::string filePath = filename.str();

    std::cout << "Saving to: " << std::filesystem::absolute(filePath) << std::endl;


    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Failed to open " << filePath << ": " << std::strerror(errno) << std::endl;
        throw std::runtime_error("File open failed.");
    }

    outFile << "AccountType: savings\n"
            << "ID: " << getAccountIDNumber() << '\n'
            << "Name: " << getAccountHolderName() << '\n'
            << "Password: " << getPassword() << '\n'
            << "Balance: " << getBalance() << '\n'
            << "InterestRate: " << getInterestRate() << '\n'
            << "--------------------------" << '\n';
    
    outFile.close();
}

