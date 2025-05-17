//
//  Account.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 20.3.25.
//

#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string firstLastName, std::string userPass, std::string accountID, std::string accountType, double initialBalance)
: accountHolderName(firstLastName), userPassword(userPass), accountIDNumber(accountID), typeOfAcc(accountType), balance(initialBalance) {};

void BankAccount::deposit(double amount) {
    try {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited: $" + std::to_string(amount)); // Record transaction
        } else {
            throw (amount);
        }
    } catch (double negativeAmount) {
        std::cout << "ERROR 01: Deposit amount must be greater than 0!" << std::endl;
        std::cout << "Your deposit was " << negativeAmount << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    try {
        if (amount <= 0) {
            throw std::runtime_error("ERROR 02: Withdrawal amount must be greater than 0!");
        }
        if (amount > balance) {
            throw std::runtime_error("ERROR 03: Insufficient funds! You tried to withdraw $" + std::to_string(amount) + ", but your balance is only $" + std::to_string(balance) + ".");
        }
        
        balance -= amount;
        transactionHistory.push_back("Withdrew: $" + std::to_string(amount)); // Record transaction
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void BankAccount::displayBalance() const {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|     Account Balance      |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    
    std::cout << "Current Balance: $" << balance << std::endl;
    if (transactionHistory.empty()) {
        std::cout << "No transactions made yet" << std::endl;
    } else {
        for (const std::string& transaction : transactionHistory) {
            std::cout << "- " << transaction << std::endl;
        }
    }
    std::cout << "+--------------------------+" << std::endl;
}

void BankAccount::displayAccDetails() const {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|     Account Details      |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    
    std::cout << "Account Holder: " << accountHolderName << std::endl;
    std::cout << "Account ID Number: " << accountIDNumber << std::endl;
    std::cout << "Type of Account: " << typeOfAcc << std::endl;
    std::cout << "Current Balance: " << balance << std::endl;
    // could add number of transactions or when the account was created...
}

void BankAccount::showTransactions() const {
    if (transactionHistory.size() == 0) {
        std::cout << "No transactions yet." << std::endl;
    }
    for (int i = 0; i < transactionHistory.size(); i++) {
        std::cout << i + 1 << "." << transactionHistory[i] << std::endl;
    }
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

std::string BankAccount::getAccountIDNumber() const {
    return accountIDNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getTypeOfAccount() const {
    return typeOfAcc;
}

void BankAccount::addTransaction(const std::string &description) {
    transactionHistory.push_back(description);
}

void BankAccount::adjustBalance(double amount) {
    balance += amount;
}

std::string BankAccount::getPassword() const {
    return userPassword;
}

double BankAccount::getOverdraftLimit() const {
    return 0.0;
}

double BankAccount::getTransactionFee() const {
    return 0.0;
}

double BankAccount::getInterestRate() const {
    return 0.0;
}

BankAccount::~BankAccount() {
    
}
