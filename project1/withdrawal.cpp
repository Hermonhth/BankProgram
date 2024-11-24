#include "withdrawal.h"

double withdrawal(double& withdrawValue, 
    double& balanceValue) {
    if (withdrawValue > 
        balanceValue || withdrawValue <= 0) {
        return balanceValue;
    }
    balanceValue -= withdrawValue;
    return balanceValue;
}
