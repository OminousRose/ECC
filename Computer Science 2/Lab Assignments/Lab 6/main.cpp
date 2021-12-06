//    Name: Eric Flores
//    Assignment: Lab 6
//    Title:   Rational Numbers
//    Date: 11/30/2021  
// 
//    Description: This program uses headers and classes to work with user input integers to create rational numbers.
//                 The program uses those rational numbers to find: the product of the two integers, the sum, the difference, and the quotient.
//                 Additionally, the program also creates a unique truth table that compares the two rational numbers
//                 to determine which rational number is greater, and if or they are equal rational numbers.
//
#include <iostream>
using namespace std;

class Rational
{
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int n, int d);
    Rational &operator=(const Rational &r);
    Rational &operator+=(const Rational &r);
    Rational &operator-=(const Rational &r);
    Rational &operator*=(const Rational &r);
    Rational &operator/=(const Rational &r);
    friend Rational operator+(const Rational &a, Rational &b);
    friend Rational operator-(const Rational &a, Rational &b);
    friend Rational operator*(const Rational &a, Rational &b);
    friend Rational operator/(const Rational &a, Rational &b);
    friend bool operator<(const Rational &a, const Rational &b);
    friend bool operator>(const Rational &a, const Rational &b);
    friend bool operator==(const Rational &a, const Rational &b);
    friend bool operator!=(const Rational &a, const Rational &b);
    friend bool operator<=(const Rational &a, const Rational &b);
    friend bool operator>=(const Rational &a, const Rational &b);
    friend ostream &operator<<(ostream &out, const Rational &r);
    friend istream &operator>>(istream &in, Rational &r);
};

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int n, int d)
{
    numerator = 0;
    denominator = 1;
}
Rational &Rational::operator=(const Rational &r)
{
    this->numerator = r.numerator;
    this->denominator = r.denominator;
    return *this;
}
Rational &Rational::operator+=(const Rational &r)
{
    this->numerator = this->numerator * r.denominator + r.numerator * this->denominator;
    this->denominator = this->denominator * r.denominator;
    return *this;
}
Rational &Rational::operator-=(const Rational &r)
{
    this->numerator = this->numerator * r.denominator - r.numerator * this->denominator;
    this->denominator = this->denominator * r.denominator;
    return *this;
}
Rational &Rational::operator*=(const Rational &r)
{
    this->numerator = this->numerator * r.numerator;
    this->denominator = this->denominator * r.denominator;
    return *this;
}
Rational &Rational::operator/=(const Rational &r)
{
    this->numerator = this->numerator * r.denominator;
    this->denominator = this->denominator * r.numerator;
    return *this;
}
Rational operator+(const Rational &a, Rational &b)
{
    Rational r;
    r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    r.denominator = a.denominator * b.denominator;
    return r;
}
Rational operator-(const Rational &a, Rational &b)
{
    Rational r;
    r.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    r.denominator = a.denominator * b.denominator;
    return r;
}
Rational operator*(const Rational &a, Rational &b)
{
    Rational r;
    r.numerator = a.numerator * b.numerator;
    r.denominator = a.denominator * b.denominator;
    return r;
}
Rational operator/(const Rational &a, Rational &b)
{
    Rational r;
    r.numerator = a.numerator * b.denominator;
    r.denominator = a.denominator * b.numerator;
    return r;
}
bool operator<(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) < (b.numerator / b.denominator))
        return true;
    return false;
}
bool operator>(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) > (b.numerator / b.denominator))
        return true;
    return false;
}
bool operator==(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) == (b.numerator / b.denominator))
        return true;
    return false;
}
bool operator!=(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) != (b.numerator / b.denominator))
        return true;
    return false;
}
bool operator<=(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) <= (b.numerator / b.denominator))
        return true;
    return false;
}
bool operator>=(const Rational &a, const Rational &b)
{
    if ((a.numerator / a.denominator) >= (b.numerator / b.denominator))
        return true;
    return false;
}
ostream &operator<<(ostream &out, const Rational &r)
{
    out << "    Numerator = " << r.numerator << "\n";
    out << "    Denominator = " << r.denominator << "\n";
    return out;
}
istream &operator>>(istream &in, Rational &r)
{
    cout << "Enter the numerator: ";
    in >> r.numerator;
    cout << "Enter the denominator: ";
    in >> r.denominator;
    return in;
}

// driver function
int main()
{
    Rational r1, r2, r3;

    cout << "For r1:\n";
    cin >> r1;
    cout << "For r2:\n";
    cin >> r2;
    cout << "For r3:\n";
    cin >> r3;

    Rational r4(1, 4);

    r1 += r2;
    r2 *= r3;

    Rational r5, r6, r7, r8;
    r5 = r3 + r4;
    r6 = r3 - r4;
    r7 = r3 * r4;
    r8 = r3 / r4;

    cout << "===============\n";
    cout << "for r1:\n"
         << r1;
    cout << "for r2:\n"
         << r2;
    cout << "for r3:\n"
         << r3;
    cout << "for r4:\n"
         << r4;
    cout << "for r5:\n"
         << r5;
    cout << "for r6:\n"
         << r6;
    cout << "for r7:\n"
         << r7;
    cout << "for r8:\n"
         << r8;
    cout << "===============\n";

    if (r1 < r2)
        cout << "\nr1 is less than r2\n";
    else
        cout << "r1 is not less than r2\n";

    if (r1 > r2)
        cout << "r1 is greater than r2\n";
    else
        cout << "r1 is not greater than r2\n";

    if (r3 <= r4)
        cout << "r3 is less than or equal to r4\n";
    else
        cout << "r3 is not less than or equal to r4\n";

    if (r3 >= r4)
        cout << "r3 is greater than or equal to r4\n";
    else
        cout << "r3 is not greater than or equal to r4\n";

    if (r3 == r4)
        cout << "r3 is equal to r4\n";
    else
        cout << "r3 is not equal to r4\n";

    if (r3 != r4)
        cout << "r3 is not equal to r4\n";
    else
        cout << "r3 is equal to r4\n";

    return 0;
}