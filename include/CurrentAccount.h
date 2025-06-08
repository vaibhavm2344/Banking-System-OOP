#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;
    double overdraftUsed;

public:
    CurrentAccount(string accNum, string name, double bal, double limit);
    void withdraw(double amount) override;
    void calculateInterest() override;
    void display() const override;
};

#endif