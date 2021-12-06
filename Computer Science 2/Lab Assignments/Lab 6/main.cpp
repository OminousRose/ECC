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

class Rational {
    // class rational declaration
    int numerator, denominator;
    // define a class called Rational that would be used to store rational
    // numbers. Include a constructor with two arguments that would initialize the
    // numerator and denominator to the values of its respective arguments; include a
    // default constructor that would initialize the rational to 0/1. Overload the
    // operators =, +=, -=, *=, /=, and then using these operators overload the
    // following operators: +, -, *, /. Also overload the comparison operators <, >,
    // ==, !=, <=, >= and the i/o stream operators >> and <<.
    public:
    Rational();
    Rational(int num, int den);
    Rational(const Rational& r);
    int get_numerator() {return numerator;}
    int get_denominator() {return denominator;}
    void simplify();
    Rational& operator=(const Rational& r);
    Rational& operator+=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator*=(const Rational& r);
    Rational& operator/=(const Rational& r);
    Rational operator+(const Rational& r);
    Rational operator-(const Rational& r);
    Rational operator*(const Rational& r);
    Rational operator/(const Rational& r);
    bool operator<(const Rational& r);
    bool operator>(const Rational& r);
    bool operator==(const Rational& r);
    bool operator!=(const Rational& r);
    bool operator<=(const Rational& r);
    bool operator>=(const Rational& r);
    friend ostream& operator<<(ostream& os, const Rational& r);
    friend istream& operator>>(istream& is, Rational& r);

};

int gcd(int a, int b) {
// this function returns the gcd of a and b recursively
if(b == 0)
return a;
return gcd(b, a%b);
}

Rational::Rational(){
// default constructor
numerator = 0;
denominator = 1;
}

Rational::Rational(int num, int den){
// parameterised constructor
numerator = num;
denominator = den;
}

Rational::Rational(const Rational& r){
// copy constructor
numerator = r.numerator;
denominator = r.denominator;
}

void Rational::simplify() {
// method simplifies the rational number by dividing both numerator and denominator by gcd
if(denominator < 0) {
numerator *= -1;
denominator *= -1;
}

int common_factor = gcd(numerator, denominator);
numerator /= common_factor;
denominator /= common_factor;
}

Rational& Rational::operator=(const Rational& r){
// overloaded = operator
numerator = r.numerator;
denominator = r.denominator;
return *this;
}

Rational& Rational::operator+=(const Rational& r){
// overloaded += operator
numerator = (numerator * r.denominator) + (denominator * r.numerator);
denominator *= r.denominator;
this->simplify();

return *this;
}

Rational& Rational::operator-=(const Rational& r){
// overloaded -= operator
numerator = (numerator * r.denominator) - (denominator * r.numerator);
denominator *= r.denominator;
this->simplify();

return *this;
}

Rational& Rational::operator*=(const Rational& r){
// overloaded *= operator
numerator *= r.numerator;
denominator *= r.denominator;
this->simplify();

return *this;
}

Rational& Rational::operator/=(const Rational& r){
// overloaded /= operator
if(r.numerator == 0) {
throw "Division by zero not allowed";
}
numerator *= r.denominator;
denominator *= r.numerator;
this->simplify();

return *this;
}

Rational Rational::operator+(const Rational& r){
// overloaded + operator
return Rational{*this} += r;
}

Rational Rational::operator-(const Rational& r){
// overloaded - operator
return Rational{*this} -= r;
}

Rational Rational::operator*(const Rational& r){
// overloaded * operator
return Rational{*this} *= r;
}

Rational Rational::operator/(const Rational& r){
// overloaded / operator
return Rational{*this} /= r;
}

bool Rational::operator<(const Rational& r){
// overloaded < operator
return (numerator / (denominator * 1.0)) < (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator>(const Rational& r){
// overloaded > operator
return (numerator / (denominator * 1.0)) > (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator==(const Rational& r){
// overloaded == operator
return numerator == r.numerator && denominator == r.denominator;
}

bool Rational::operator!=(const Rational& r){
// overloaded != operator
return !(*this == r);
}

bool Rational::operator<=(const Rational& r){
// overloaded <= operator
return (numerator / (denominator * 1.0)) <= (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator>=(const Rational& r){
// overloaded >= operator
return (numerator / (denominator * 1.0)) >= (r.numerator / (r.denominator * 1.0));
}

ostream& operator<<(ostream& os, const Rational& r){
// overloaded output stream for Rational objects
os << r.numerator << "/" << r.denominator;
return os;
}

istream& operator>>(istream& is, Rational& r){
// overloaded input stream for Rational objects
is >> r.numerator >> r.denominator;
return is;
}

int main() {
// testing rational class methods
Rational R1, R2;
cout << "Enter numerator and denominator of rational number 1: ";
cin >> R1;
cout << "Enter numerator and denominator of rational number 2: ";
cin >> R2;
cout << endl;
// print sum, difference, product, and quotient
cout << "Sum: " << R1 << " + " << R2 << " = " << R1 + R2 << endl << endl;
cout << "Difference: " << R1 << " - " << R2 << " = " << R1 - R2 << endl << endl;
cout << "Product: " << R1 << " * " << R2 << " = " << R1 * R2 << endl << endl;
cout << "Quotient: " << R1 << " / " << R2 << " = " << R1 / R2 << endl << endl;
// truth table of comparison tests
cout << "Is " << R1 << " == " << R2 << "? " << ((R1==R2)?"true":"false") << endl << endl;
cout << "Is " << R1 << " != " << R2 << "? " << ((R1!=R2)?"true":"false") << endl << endl;
cout << "Is " << R1 << " > " << R2 << "? " << ((R1>R2)?"true":"false") << endl << endl;
cout << "Is " << R1 << " < " << R2 << "? " << ((R1<R2)?"true":"false") << endl << endl;
cout << "Is " << R1 << " >= " << R2 << "? " << ((R1>=R2)?"true":"false") << endl << endl;
cout << "Is " << R1 << " <= " << R2 << "? " << ((R1<=R2)?"true":"false") << endl << endl;
return 0;
}