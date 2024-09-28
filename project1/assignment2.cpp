#include <iostream>
using namespace std;
double myBalance;
double withdrawl;
string myUsername;

int main()
{
    cout << "What is your name? " << endl;
    cin >> myUsername;
    cout << "Hello " << myUsername << endl;
    cout << "What is your balance? " << endl;
    cin >> myBalance;
    cout << "Your account balance is " << myBalance << endl;
    cout << "What is your withdrawl?" << endl;
    cin >> withdrawl;
    myBalance -= withdrawl;
    cout << "Your new balance is " << myBalance << endl;

    return 0;
}
