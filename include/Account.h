#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    string holderName;
    double balance;

public:
    Account(string accNum, string name, double bal);

    string getAccountNumber() const;
    string getHolderName() const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const;
    virtual void calculateInterest() = 0;

    virtual ~Account();
};

#endif