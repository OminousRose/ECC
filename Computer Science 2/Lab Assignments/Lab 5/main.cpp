//    Name: Eric Flores
//    Assignment: Lab 6
//    Title:   Complex Numbers
//    Date: 11/30/2021
//
//    Description: This program uses a class to simulate a unique calulator that is able to find the sum, difference, and product
//                 of two user input complex numbers.
//
//
//
#include <iostream>
using namespace std;

// Class declaration
class Complex
{
private:
    int a, b;

public:
    // default constructor and constructor
    // initialize a and b to 0 set as int x and int y
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    Complex(int x)
    {
        a = x;
        b = 0;
    }

    Complex()
    {
        a = 0;
        b = 0;
    }

    bool operator==(const Complex &num)
    {
        // check if the real and imaginary part of both the numbers are equal
        return a == num.a && b == num.b;
    }

    Complex operator+(const Complex &num)
    {
        // create a new complex number equal to the sum of the given numbers and return it
        Complex res(a + num.a, b + num.b);
        return res;
    }

    Complex operator-(const Complex &num)
    {
        // create a new complex number equal to the difference of the given numbers and return it
        Complex res(a - num.a, b - num.b);
        return res;
    }

    Complex operator*(const Complex &num)
    {
        // create a new complex number equal to the product of the given numbers and return it
        Complex res(a * num.a - b * num.b, a * num.b + b * num.a);
        return res;
    }

    // overloading the stream insertion operator
    friend istream &operator>>(istream &, Complex &);

    // overloading the stream extraction operator
    friend ostream &operator<<(ostream &, const Complex &);
};

istream &operator>>(istream &in, Complex &num)
{
    cout << "Enter real part: ";
    in >> num.a;
    cout << "Enter imaginary part:";
    in >> num.b;
    return in;
}

ostream &operator<<(ostream &out, const Complex &num)
{
    if (num.b < 0)
        out << num.a << " - " << -num.b << "i";
    else
        out << num.a << " + " << num.b << "i";
    return out;
}

int main()
{
    // prompt user to input imaginary and real numbers
    Complex c1, c2;
    cout << "Enter the first complex number:\n";
    cin >> c1;
    cout << "\nEnter the second complex number:\n";
    cin >> c2;

    cout << "\nThe first number is: " << c1;
    cout << "\nThe second number is: " << c2 << '\n';
    // check to see if the input numbers are equal
    // then print out if equal or not
    if (c1 == c2)
        cout << "\nThe given numbers are equal.\n";
    else
        cout << "\nThe given numbers are unequal.\n";

    Complex c3 = c1 + c2;
    // print out sum
    cout << "\nThe sum of the given numbers is: " << c3 << '\n';
    // print out difference
    Complex c4 = c1 - c2;
    cout << "\nThe difference of the given numbers is: " << c4 << '\n';
    // print out product
    Complex c5 = c1 * c2;
    cout << "\nThe product of the given numbers is: " << c5 << '\n';
    return 0;
}