//    Name: Eric Flores
//    Assignment: Lab 8
//    Title:   Complex Numbers II
//    Date: 12/6/2021  
// 
//    Description: This program uses class "Complex" from a previous lab in order to perform
//                 calculations involving imaginary numbers. The class itself represents complex numbers, declared by two int
//                 member variables. Prototypes for operators "==, +, -, >>, <<" are included in the class as well.
//                 Definitions for the member functions of the class are written outside the class on a different file.
//
#include <iostream>
#include "complex_numbers.cpp"

using namespace std;

int main()
{
Complex c1;
Complex c2;
  
cin >> c1;
cin >> c2;

cout << c1;
cout << c2;

Complex c3;
c3 = c1+c2;

cout << c3;

c3 = c1-c2;
cout << c3;

c3 = c1*c2;
cout << c3;

if (c1 == c2)
{
cout << "Equal\n";
}   
else
{
cout <<"Not equal\n";
}
}