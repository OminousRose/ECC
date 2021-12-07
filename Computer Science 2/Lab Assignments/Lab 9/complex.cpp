#include "Complex.h"
Complex::Complex()
{
real_part = 0.0;
imaginary_part = 0.0;
}

Complex::Complex(int r,int i)
{
real_part = r;
imaginary_part = i;
}

Complex::Complex(int r)
{
real_part = r;
imaginary_part = 0.0;
}

Complex operator + (Complex const &c1, Complex const &c2)
{
   return Complex(c1.real_part + c2.real_part, c1.imaginary_part + c2.imaginary_part);
}

Complex operator - (Complex const &c1, Complex const &c2)
{
   return Complex(c1.real_part - c2.real_part, c1.imaginary_part - c2.imaginary_part);
}

Complex operator * (Complex const &c1, Complex const &c2)
{
   return Complex(c1.real_part * c2.real_part, c1.imaginary_part * c2.imaginary_part);
}
ostream& operator<<(ostream& os, const Complex& complex)
{
os << complex.real_part << '+' << complex.imaginary_part << 'i';
return os;
}

istream & operator >> (istream &in, Complex &complex)
{
cout << "Enter Real Part of complex number ";
in >> complex.real_part;
cout << "Enter Imaginary Part of complex number";
in >> complex.imaginary_part;
return in;
}

const bool Complex::operator==(const Complex &r) const
{
if((real_part == r.real_part) && (imaginary_part == r.imaginary_part))
return true;
else
return false;
}