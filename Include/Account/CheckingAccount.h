//
//  CheckingAccount.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 29.3.25.
//
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;
    double transactionFee;
public:
    CheckingAccount(std::string& holderName, std::string& userPass, std::string& accountID, double initialBalance, double overdraftLimit, double transactionFee);
    void withdraw(double amount) override;
    void displayAccDetails() const override;
    double getOverdraftLimit() const override;
    double getTransactionFee() const override;
    virtual void saveToFile() const override;
    
};

#endif
