#include "rational.h"

int gcd(int a, int b)
{
    // this function returns the gcd of a and b recursively
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Rational::Rational()
{
    // default constructor
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num, int den)
{
    // parameterised constructor
    numerator = num;
    denominator = den;
}

Rational::Rational(const Rational &r)
{
    // copy constructor
    numerator = r.numerator;
    denominator = r.denominator;
}

void Rational::simplify()
{
    // method simplifies the rational number by dividing both numerator and denominator by gcd
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }

    int common_factor = gcd(numerator, denominator);
    numerator /= common_factor;
    denominator /= common_factor;
}

Rational &Rational::operator=(const Rational &r)
{
    // overloaded = operator
    numerator = r.numerator;
    denominator = r.denominator;
    return *this;
}

Rational &Rational::operator+=(const Rational &r)
{
    // overloaded += operator
    numerator = (numerator * r.denominator) + (denominator * r.numerator);
    denominator *= r.denominator;
    this->simplify();

    return *this;
}

Rational &Rational::operator-=(const Rational &r)
{
    // overloaded -= operator
    numerator = (numerator * r.denominator) - (denominator * r.numerator);
    denominator *= r.denominator;
    this->simplify();

    return *this;
}

Rational &Rational::operator*=(const Rational &r)
{
    // overloaded *= operator
    numerator *= r.numerator;
    denominator *= r.denominator;
    this->simplify();

    return *this;
}

Rational &Rational::operator/=(const Rational &r)
{
    // overloaded /= operator
    if (r.numerator == 0)
    {
        throw "Division by zero not allowed";
    }
    numerator *= r.denominator;
    denominator *= r.numerator;
    this->simplify();

    return *this;
}

Rational Rational::operator+(const Rational &r)
{
    // overloaded + operator
    return Rational{*this} += r;
}

Rational Rational::operator-(const Rational &r)
{
    // overloaded - operator
    return Rational{*this} -= r;
}

Rational Rational::operator*(const Rational &r)
{
    // overloaded * operator
    return Rational{*this} *= r;
}

Rational Rational::operator/(const Rational &r)
{
    // overloaded / operator
    return Rational{*this} /= r;
}

bool Rational::operator<(const Rational &r)
{
    // overloaded < operator
    return (numerator / (denominator * 1.0)) < (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator>(const Rational &r)
{
    // overloaded > operator
    return (numerator / (denominator * 1.0)) > (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator==(const Rational &r)
{
    // overloaded == operator
    return numerator == r.numerator && denominator == r.denominator;
}

bool Rational::operator!=(const Rational &r)
{
    // overloaded != operator
    return !(*this == r);
}

bool Rational::operator<=(const Rational &r)
{
    // overloaded <= operator
    return (numerator / (denominator * 1.0)) <= (r.numerator / (r.denominator * 1.0));
}

bool Rational::operator>=(const Rational &r)
{
    // overloaded >= operator
    return (numerator / (denominator * 1.0)) >= (r.numerator / (r.denominator * 1.0));
}

ostream &operator<<(ostream &os, const Rational &r)
{
    // overloaded output stream for Rational objects
    os << r.numerator << "/" << r.denominator;
    return os;
}

istream &operator>>(istream &is, Rational &r)
{
    // overloaded input stream for Rational objects
    is >> r.numerator >> r.denominator;
    return is;
}