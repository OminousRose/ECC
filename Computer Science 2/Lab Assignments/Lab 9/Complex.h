#include<iostream>
using namespace std;

// class Complex declaration
class Complex
{
public:
// default constructor
Complex();
// constructor with two parameters
Complex(int = 0.0, int = 0.0);
// constructor with only real part
Complex(int real);
// subtraction overloaded  
friend Complex operator-(const Complex &, Complex const &);
// multiplication overloaded
friend Complex operator*(const Complex &, Complex const &);
// addition ovcerloaded
friend Complex operator + (Complex const &, Complex const &);
// overloading istream and ostream operators
friend ostream &operator<<(ostream&, const Complex &);
friend istream &operator>>(istream&, Complex &);
const bool operator==(const Complex &r) const;

private:
//real part
int real_part;
//imaginary part
int imaginary_part;
};