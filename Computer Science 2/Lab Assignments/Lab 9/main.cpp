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
#include "Complex.h"

using namespace std;


int main()
{
Complex c1(2,3);
Complex c2(10,11);
Complex c3 = c1 + c2;
cout << "Addition : " << c3 << endl;
Complex c4 = c2 - c1;
cout << "Subtraction : " << c4 << endl;
Complex c5 = c1 * c2;
cout << "Multiplication : " << c5 << endl;
Complex c6(10,11);
bool varBool = c6 == c1;
cout << "Are c6 and c2 equal:" << varBool << endl;
bool varBool1 = c6 == c2;
cout << "Are c6 and c2 equal:" << varBool1 << endl;
return 0;
}