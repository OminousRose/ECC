#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
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
    Rational(const Rational &r);
    int get_numerator() { return numerator; }
    int get_denominator() { return denominator; }
    void simplify();
    Rational &operator=(const Rational &r);
    Rational &operator+=(const Rational &r);
    Rational &operator-=(const Rational &r);
    Rational &operator*=(const Rational &r);
    Rational &operator/=(const Rational &r);
    Rational operator+(const Rational &r);
    Rational operator-(const Rational &r);
    Rational operator*(const Rational &r);
    Rational operator/(const Rational &r);
    bool operator<(const Rational &r);
    bool operator>(const Rational &r);
    bool operator==(const Rational &r);
    bool operator!=(const Rational &r);
    bool operator<=(const Rational &r);
    bool operator>=(const Rational &r);
    friend ostream &operator<<(ostream &os, const Rational &r);
    friend istream &operator>>(istream &is, Rational &r);
};

#endif