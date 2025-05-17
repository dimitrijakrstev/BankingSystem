//
//  CheckingAccount.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 29.3.25.
//
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

CheckingAccount::CheckingAccount(std::string& holderName, std::string& userPass, std::string& accountID, double initialBalance, double overdraftLimit, double transactionFee) : BankAccount(holderName, userPass, accountID, "checking", initialBalance), overdraftLimit(overdraftLimit), transactionFee(transactionFee) {}


void CheckingAccount::withdraw(double amount) {
    double totalAmount = amount + transactionFee;
    double projectedBalance = getBalance() - totalAmount;

    try {
        if (amount <= 0) {
            throw std::runtime_error("ERROR 02: Withdrawal amount must be greater than 0!");
        }

        if (projectedBalance >= -overdraftLimit) {
            adjustBalance(-totalAmount);  // bypasses base check
            addTransaction("Withdrew: $" + std::to_string(amount) + " (Fee: $" + std::to_string(transactionFee) + ")");
        } else {
            throw std::runtime_error(
                "ERROR 03: Insufficient funds! You tried to withdraw $" + std::to_string(amount) +
                " + $" + std::to_string(transactionFee) + " fee = $" + std::to_string(totalAmount) +
                ", but your overdraft limit only allows you to go down to $" + std::to_string(-overdraftLimit) +
                ". Current balance: $" + std::to_string(getBalance()) + "."
            );
        }
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void CheckingAccount::displayAccDetails() const {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|     Account Details      |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    
    std::cout << "Account Holder: " << getAccountHolderName() << std::endl;
    std::cout << "Account ID Number: " << getAccountIDNumber() << std::endl;
    std::cout << "Type of Account: " << getTypeOfAccount() << std::endl;
    std::cout << "Current Balance: " << getBalance() << std::endl;
    std::cout << "Overdraft Limit: " << overdraftLimit << std::endl;
    std::cout << "Transaction Fee: " << transactionFee << std::endl;
}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}

double CheckingAccount::getTransactionFee() const {
    return transactionFee;
}

void CheckingAccount::saveToFile() const {
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

    outFile << "AccountType: checking\n"
            << "ID: " << getAccountIDNumber() << '\n'
            << "Name: " << getAccountHolderName() << '\n'
            << "Password: " << getPassword() << '\n'
            << "Balance: " << getBalance() << '\n'
            << "TransactionFee: " << transactionFee << '\n'
            << "OverdraftLimit: " << overdraftLimit << '\n'
            << "--------------------------" << '\n';

    outFile.close();
}
