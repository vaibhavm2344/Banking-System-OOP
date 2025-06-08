#include "../include/Account.h"

Account::Account(string accNum, string name, double bal) {
    accountNumber = accNum;
    holderName = name;
    balance = bal;
}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getHolderName() const {
    return holderName;
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposited: " << amount << endl;
}

void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account() {}