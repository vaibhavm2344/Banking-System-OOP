#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "include/SavingsAccount.h"
#include "include/CurrentAccount.h"

using namespace std;

int main() {
    vector<shared_ptr<Account>> accounts;
    int choice;

    while (true) {
        cout << "\n1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Calculate Interest" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        string accNum, name;
        double bal, amount, rate, limit;
        int index;

        switch (choice) {
            case 1:
                cout << "Enter Account Number, Name, Balance, Interest Rate: ";
                cin >> accNum >> name >> bal >> rate;
                accounts.push_back(make_shared<SavingsAccount>(accNum, name, bal, rate));
                break;
            case 2:
                cout << "Enter Account Number, Name, Balance, Overdraft Limit: ";
                cin >> accNum >> name >> bal >> limit;
                accounts.push_back(make_shared<CurrentAccount>(accNum, name, bal, limit));
                break;
            case 3:
                cout << "Enter account index and deposit amount: ";
                cin >> index >> amount;
                if (index < accounts.size()) accounts[index]->deposit(amount);
                break;
            case 4:
                cout << "Enter account index and withdraw amount: ";
                cin >> index >> amount;
                if (index < accounts.size()) accounts[index]->withdraw(amount);
                break;
            case 5:
                for (int i = 0; i < accounts.size(); ++i) {
                    cout << "\nAccount Index: " << i << endl;
                    accounts[i]->display();
                }
                break;
            case 6:
                cout << "Enter account index to calculate interest: ";
                cin >> index;
                if (index < accounts.size()) accounts[index]->calculateInterest();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}