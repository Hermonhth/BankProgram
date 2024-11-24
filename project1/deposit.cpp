#include "deposit.h"

double deposit(double& depositValue,
    double& balanceValue) {
    if (depositValue <= 0) {
        return balanceValue; 
    }
    balanceValue += depositValue;
    return balanceValue;
}
