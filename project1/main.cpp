#include "deposit.h"
#include "withdrawal.h"
#include <iostream>
#include <string>
using namespace std;

class Bank_Account {
private:
    double balance;
    string username;

public:
    void setUsername(string name) {
        username = name;
    }

    string getUsername() const {
        return username;
    }

    void setBalance(double initialBalance) {
        balance = initialBalance;
    }

    double getBalance() const {
        return balance;
    }

    double deposit(double amount) {
        return ::deposit(amount, balance); // Call deposit function
    }

    double withdrawal(double amount) {
        return ::withdrawal(amount, balance); // Call withdrawal function
    }
};

int main() {
    Bank_Account myAccount;
    int Choice = 0;

    cout << "What is your name? " << endl;
    string myUsername;
    cin >> myUsername;
    myAccount.setUsername(myUsername);

    cout << "Hello " << myAccount.getUsername() << endl;

    cout << "What is your balance? " << endl;
    double myBalance;
    cin >> myBalance;
    myAccount.setBalance(myBalance);

    cout << "Your account balance is " << myAccount.getBalance() << endl;

    while (Choice != 3) {
        cout << "1) Make a Deposit \n2) Make a Withdrawal \n3) Exit" << endl;
        cin >> Choice;

        if (Choice == 1) {
            cout << "What is your deposit?" << endl;
            double myDeposit;
            cin >> myDeposit;
            cout << "Your new balance is " << myAccount.deposit(myDeposit) << endl;
        }
        else if (Choice == 2) {
            cout << "What is your withdrawal?" << endl;
            double myWithdrawal;
            cin >> myWithdrawal;
            cout << "Your new balance is " << myAccount.withdrawal(myWithdrawal) << endl;
        }
        else if (Choice == 3) {
            cout << "Your final balance is: " << myAccount.getBalance() << endl;
            cout << "Thank you for using the bank. Goodbye!" << endl;
        }
        else {
            cout << "Invalid option. Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}
