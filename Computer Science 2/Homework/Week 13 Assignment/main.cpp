// Week 13 Assignment
// Name: Eric Flores
#include <iostream>
using namespace std;

int main()
{
    // declare int for integer data type values
    int dollars, remainingCoupons;
    int noChocolate, addi_Chocolate;

    cout << "Enter your amount of dollars: ";
    cin >> dollars;

    // initialize noChocolate and remainingCoupons
    noChocolate = dollars;
    remainingCoupons = noChocolate;

    while (remainingCoupons >= 7)
    {
        // statement to calculate the noChocolate,
        // additional chocolate and remaining coupons
        addi_Chocolate = remainingCoupons / 7;
        noChocolate = noChocolate + addi_Chocolate;
        remainingCoupons = (remainingCoupons / 7);
    }

    // output
    cout << "Total number of chocolate bars is: " << noChocolate << endl;
    cout << "Number of leftover coupons is: " << remainingCoupons << endl;

    return 0;
}