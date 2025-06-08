#include "../include/SavingsAccount.h"

SavingsAccount::SavingsAccount(string accNum, string name, double bal, double rate)
    : Account(accNum, name, bal) {
    interestRate = rate;
}

void SavingsAccount::calculateInterest() {
    double interest = (balance * interestRate) / 100;
    balance += interest;
    cout << "Interest of " << interest << " added to balance." << endl;
}

void SavingsAccount::display() const {
    cout << " --- Savings Account ---" << endl;
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}
