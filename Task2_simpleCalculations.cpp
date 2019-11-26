#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;

//netBalance, payment, d1, d2, and interest rate per month
//interest = averageDailyBalance∗0.0152

float calculateInterest(float netBalance, float payment, float d1, float d2, float int_rate_pm)
{
    float averageDailyBalance = (netBalance*d1 - payment*d2) / d1;
    
    return averageDailyBalance*int_rate_pm;
}

int main()
{
    vector<float> netBalances {500.08, 3000.450, 670.56};
    vector<float> payments {100.08, 300.50, 700.69};
    vector<float> d1s {1,2,3};
    vector<float> d2s {2,3,2};
    vector<float> int_rates_pm {0.0152, 0.0302, 0.0602};
    
    for( auto i = 0u; i != netBalances.size(); i++ )
    {
        auto interest = calculateInterest(netBalances[i], payments[i], d1s[i], d2s[i], int_rates_pm[i]);
        cout << fixed << setprecision(2) << interest << endl;
    }
    
    return 0;
}