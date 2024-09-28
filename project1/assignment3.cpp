#include <iostream>
using namespace std;
int year;
bool leapyear;
int main() {
 
    // Prompt user to enter a year
    cout << "Enter a year: ";
    // Boolean variable to store the result
    cin >> year;

    // Determine if it's a leap year using the boolean variable
    leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Output based on the value of leapyear
    if (leapyear) {
        cout << year << " is a leap year." << endl;
    }
    else {
        cout << year << " is not a leap year." << endl;
    }
    return 0;
}
