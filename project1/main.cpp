#include "deposit.h"
#include "withdrawal.h"
#include <iostream>
using namespace std;
double myBalance;
double myDeposit;
double myWithdrawal;
string myUsername;
double Choice;


int main() 
{
    cout << "What is your name? " << endl;
    cin >> myUsername;
    cout << "Hello " << myUsername << endl;
    cout << "What is your balance? " << endl;
    cin >> myBalance;
    cout << "Your account balance is " << myBalance << endl;
    cout << "1) Make a Deposit \n2) Make a Withdrawal" << endl;
    cin >> Choice;
    if (Choice == 1) {
        cout << "What is your deposit?" << endl;
        cin >> myDeposit;
        if (myDeposit <= 0) {
            cout << "Deposit amount is invalid. Please input a positive deposit amount." << endl;
        }
        else {
            cout << "Your new balance is " << deposit(myBalance, myDeposit) << endl;
        }
    }
    else if (Choice == 2) {
        cout << "What is your Withdrawal?" << endl;
        cin >> myWithdrawal;
        if (myWithdrawal >= myBalance && myWithdrawal > 0) {
            cout << "Insufficient funds. Please withdraw a valid amount." << endl;
        }
        else {
            cout << "Your new balance is " << withdrawal(myBalance, myWithdrawal) << endl;
        }
    }

    
    
    return 0;
}









  