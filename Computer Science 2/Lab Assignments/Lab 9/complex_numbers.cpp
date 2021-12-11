#include <iostream>
using namespace std;
// class declaration
class Complex
{
private:
    double real;
    double imaginary;

public:
    // real part and imaginary part are stored as double values
    Complex(double realPart, double imagPart)
    {
        real = realPart;
        imaginary = imagPart;
    }

    Complex(double realPart)
    {
        real = realPart;
        imaginary = 0;
    }

    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    // overload addition operator
    Complex operator+(const Complex &b)
    {
        Complex c;
        c.real = this->real + b.real;
        c.imaginary = this->imaginary + b.imaginary;
        return c;
    }
    // overload subraction operator
    Complex operator-(const Complex &b)
    {
        Complex c;
        c.real = this->real - b.real;
        c.imaginary = this->imaginary - b.imaginary;
        return c;
    }
    // overload multiplication operator
    Complex operator*(const Complex &b)
    {
        Complex c;
        c.real = this->real * b.real - this->imaginary * b.imaginary;
        c.imaginary = this->real * b.imaginary + this->imaginary * b.real;
        return c;
    }
    // overload == operator
    bool operator==(const Complex &b)
    {
        return (this->real == b.real) && (this->imaginary == b.imaginary);
    }
    // overload ostream and istream operators
    friend ostream &operator<<(ostream &os, Complex &t)
    {
        os << t.real << " + " << t.imaginary << "*i" << endl;
        return os;
    }

    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter Real Part ";
        in >> c.real;
        cout << "Enter Imagenory Part ";
        in >> c.imaginary;
        return in;
    }
};