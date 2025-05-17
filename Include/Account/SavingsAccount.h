//
//  SavingsAccount.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 29.3.25.
//

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(std::string& holderName, std::string& userPass, std::string& accountID, double initialBalance, double rate);
    void addMonthlyInterest();
    void displayAccDetails() const override;
    double getInterestRate() const override;
    void saveToFile() const override;
};

#endif
