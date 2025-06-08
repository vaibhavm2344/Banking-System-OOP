#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string name, double bal, double rate);
    void calculateInterest() override;
    void display() const override;
};

#endif