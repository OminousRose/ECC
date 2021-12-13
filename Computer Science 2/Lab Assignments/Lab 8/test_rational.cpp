//    Name: Eric Flores
//    Assignment: Lab 8
//    Title:   Rational Numbers II
//    Date: 12/6/2021
//
//    Description: This program uses headers and classes to work with user input integers to create rational numbers.
//                 The program uses those rational numbers to find: the product of the two integers, the sum, the difference, and the quotient.
//                 Additionally, the program also creates a unique truth table that compares the two rational numbers
//                 to determine which rational number is greater, and if or they are equal rational numbers.
//
#include "rational.cpp"

using namespace std;

int main()
{
    // testing rational class methods
    Rational R1, R2;
    cout << "Enter numerator and denominator of rational number 1: ";
    cin >> R1;
    cout << "Enter numerator and denominator of rational number 2: ";
    cin >> R2;
    cout << endl;
    // print sum, difference, product, and quotient
    cout << "Sum: " << R1 << " + " << R2 << " = " << R1 + R2 << endl
         << endl;
    cout << "Difference: " << R1 << " - " << R2 << " = " << R1 - R2 << endl
         << endl;
    cout << "Product: " << R1 << " * " << R2 << " = " << R1 * R2 << endl
         << endl;
    cout << "Quotient: " << R1 << " / " << R2 << " = " << R1 / R2 << endl
         << endl;
    // truth table of comparison tests
    cout << "Is " << R1 << " == " << R2 << "? " << ((R1 == R2) ? "true" : "false") << endl
         << endl;
    cout << "Is " << R1 << " != " << R2 << "? " << ((R1 != R2) ? "true" : "false") << endl
         << endl;
    cout << "Is " << R1 << " > " << R2 << "? " << ((R1 > R2) ? "true" : "false") << endl
         << endl;
    cout << "Is " << R1 << " < " << R2 << "? " << ((R1 < R2) ? "true" : "false") << endl
         << endl;
    cout << "Is " << R1 << " >= " << R2 << "? " << ((R1 >= R2) ? "true" : "false") << endl
         << endl;
    cout << "Is " << R1 << " <= " << R2 << "? " << ((R1 <= R2) ? "true" : "false") << endl
         << endl;
    return 0;
}