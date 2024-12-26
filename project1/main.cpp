#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "deposit.h"
#include "withdrawal.h"

using namespace std;

class Bank_Account {
private:
    double balance;
    string username;
    static const int MAX_TRANSACTIONS = 100; // Maximum number of transactions to store
    double depositAmounts[MAX_TRANSACTIONS];
    string depositTimestamps[MAX_TRANSACTIONS];
    int depositCount;
    double withdrawalAmounts[MAX_TRANSACTIONS];
    string withdrawalTimestamps[MAX_TRANSACTIONS];
    int withdrawalCount;

    string getCurrentTime() {
        time_t tt;
        struct tm ti;

        time(&tt);

        if (localtime_s(&ti, &tt) == 0) {
            char buffer[26];

            if (asctime_s(buffer, sizeof(buffer), &ti) == 0) {
                return string(buffer);
            }   
        }
    }

public:
    Bank_Account() : balance(0.0), username(""), depositCount(0), withdrawalCount(0) {
    }

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

    void displayBalance() const {
        cout << "Current balance for " << username << " is: $";
        // Manually format to 2 decimal places
        cout.precision(2);
        cout << fixed << balance << endl;
    }

    void displayDepositHistory() const {
        cout << "Deposit history for " << username << ":" << endl;
        if (depositCount == 0) {
            cout << "No deposit history found." << endl;
        }
        else {
            for (int i = 0; i < depositCount; i++) {
                cout << "Amount: $";
                cout.precision(2);
                cout << fixed << depositAmounts[i] << " - Timestamp: " << depositTimestamps[i];
            }
        }
    }

    void displayWithdrawalHistory() const {
        cout << "Withdrawal history for " << username << ":" << endl;
        if (withdrawalCount == 0) {
            cout << "No withdrawal history found." << endl;
        }
        else {
            for (int i = 0; i < withdrawalCount; i++) {
                cout << "Amount: $";
                cout.precision(2);
                cout << fixed << withdrawalAmounts[i] << " - Timestamp: " << withdrawalTimestamps[i];
            }
        }
    }

    double deposit(double amount) {
        if (amount > 0) {
            if (depositCount < MAX_TRANSACTIONS) {
                balance = ::deposit(amount, balance);
                string timestamp = getCurrentTime();
                depositAmounts[depositCount] = amount;
                depositTimestamps[depositCount] = timestamp;
                depositCount++;
                cout << "Deposit of $" << fixed << amount << " was successful on " << timestamp << endl;

                ofstream outFile("deposits.txt", ios::app);
                if (outFile.is_open()) {
                    outFile << amount << " " << timestamp;
                    outFile.close();
                }
                
            }
            
        }
        else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
        return balance;
    }

    double withdrawal(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                if (withdrawalCount < MAX_TRANSACTIONS) {
                    balance = ::withdrawal(amount, balance);
                    string timestamp = getCurrentTime();
                    withdrawalAmounts[withdrawalCount] = amount;
                    withdrawalTimestamps[withdrawalCount] = timestamp;
                    withdrawalCount++;
                    cout << "Withdrawal of $" << fixed << amount << " was successful on " << timestamp << endl;

                    ofstream outFile("withdrawals.txt", ios::app);
                    if (outFile.is_open()) {
                        outFile << amount << " " << timestamp;
                        outFile.close();
                    }
                    
                }
                
            }
            else {
                cout << "Error: Insufficient funds for withdrawal." << endl;
            }
        }
        else {
            cout << "Error: Withdrawal amount must be positive." << endl;
        }
        return balance;
    }

    void loadHistory(const string& depositFile, const string& withdrawalFile) {
        ifstream inFile;
        double amount;
        string timestamp;

        inFile.open(depositFile);
        if (inFile.is_open()) {
            while (inFile >> amount && depositCount < MAX_TRANSACTIONS) {
                getline(inFile, timestamp);
                depositAmounts[depositCount] = amount;
                depositTimestamps[depositCount] = timestamp;
                depositCount++;
                balance += amount;
            }
            inFile.close();
        }

        inFile.open(withdrawalFile);
        if (inFile.is_open()) {
            while (inFile >> amount && withdrawalCount < MAX_TRANSACTIONS) {
                getline(inFile, timestamp);
                withdrawalAmounts[withdrawalCount] = amount;
                withdrawalTimestamps[withdrawalCount] = timestamp;
                withdrawalCount++;
                balance -= amount;
            }
            inFile.close();
        }
    }
};

int main() {
    Bank_Account myAccount;
    myAccount.loadHistory("deposits.txt", "withdrawals.txt");

    int Choice = 0;

    cout << "What is your name? " << endl;
    string myUsername;
    cin >> myUsername;
    myAccount.setUsername(myUsername);

    cout << "Hello " << myAccount.getUsername() << endl;
    cout.precision(2);
    cout << "Your account balance is $" << fixed << myAccount.getBalance() << endl;

    while (Choice != 6) {

        cout << "\nMenu:\n";
        cout << "1) Balance\n";
        cout << "2) Make a Deposit\n";
        cout << "3) Make a Withdrawal\n";
        cout << "4) Deposit History\n";
        cout << "5) Withdrawal History\n";
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        if (Choice == 1) {
            myAccount.displayBalance();
        }
        else if (Choice == 2) {
            cout << "What is your deposit?" << endl;
            double myDeposit;
            cin >> myDeposit;

            myAccount.deposit(myDeposit);
            cout << "Your new balance is $" << fixed << myAccount.getBalance() << endl;
        }
        else if (Choice == 3) {
            cout << "What is your withdrawal?" << endl;
            double myWithdrawal;
            cin >> myWithdrawal;

            myAccount.withdrawal(myWithdrawal);
            cout << "Your new balance is $" << fixed << myAccount.getBalance() << endl;
        }
        else if (Choice == 4) {
            myAccount.displayDepositHistory();
        }
        else if (Choice == 5) {
            myAccount.displayWithdrawalHistory();
        }
        else if (Choice == 6) {
            cout << "Your final balance is: $" << fixed << myAccount.getBalance() << endl;
            cout << "Thank you for using the bank. Goodbye!" << endl;
        }
        else {
            cout << "Invalid option. Please select from 1 to 6." << endl;
        }
    }

    return 0;
}