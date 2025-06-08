#include "../include/CurrentAccount.h"

CurrentAccount::CurrentAccount(string accNum, string name, double bal, double limit)
    : Account(accNum, name, bal) {
    overdraftLimit = limit;
    overdraftUsed = 0;
}

void CurrentAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Withdrawn from balance: " << amount << endl;
    } else {
        double remaining = amount - balance;
        if (remaining <= (overdraftLimit - overdraftUsed)) {
            cout << "Withdrawn from balance: " << balance << endl;
            balance = 0;
            overdraftUsed += remaining;
            cout << "Withdrawn from overdraft: " << remaining << endl;
        } else {
            cout << "Overdraft limit exceeded! Cannot withdraw " << amount << endl;
        }
    }
}

void CurrentAccount::calculateInterest() {
    cout << "No interest for Current Account." << endl;
}

void CurrentAccount::display() const {
    cout << "--- Current Account ---" << endl;
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
    cout << "Overdraft Used: " << overdraftUsed << endl;
    cout << "Overdraft Remaining: " << (overdraftLimit - overdraftUsed) << endl;
}