//
//  Account.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 20.3.25.
//
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    std::string accountIDNumber;
    std::string typeOfAcc;
    double balance;
    std::vector<std::string> transactionHistory;
    std::string userPassword;
   
protected:
    void addTransaction(const std::string& description);
    void adjustBalance(double amount);
public:
    BankAccount(std::string firstLastName, std::string userPass, std::string accountID, std::string accountType, double initialBalance);
    virtual ~BankAccount();
    
    virtual void saveToFile() const = 0; // pure virtual

    void deposit(double amount);
    virtual void withdraw(double amount);
    void displayBalance() const;
    virtual void displayAccDetails() const;
    void showTransactions() const;
    
    //Getters
    std::string getAccountHolderName() const;
    std::string getAccountIDNumber() const;
    double getBalance() const;
    std::string getTypeOfAccount() const;
    std::string getPassword() const;
    virtual double getOverdraftLimit() const;
    virtual double getTransactionFee() const;
    virtual double getInterestRate() const;
};

#endif
