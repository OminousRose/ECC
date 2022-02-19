/*
Name: Eric Flores
Date: 2/18/2022
Assignment: Week 4 Homework Problem
Description: Write a program to compute the area A of a triangle with base b and height h (Recall that A = 1/2(b*h))
*/
#include <iostream>
using namespace std;

int main()
{
    // Declare variables to represent the dimensions of the triangle and the area.
    double b, h, A;
    // Program description.
    cout << "This program will compute the area of a triangle based on user input dimensions base 'b' and height 'h'." << endl;
    // Program prompts the user for triangle dimensions.
    cout << "Enter the base of of the triangle";
    cin >> b;
    cout << "Enter the height of the triangle";
    cin >> h;
    // A is set to equal one half the base times the height of the triangle.
    A = (1 / 2)(b * h);
    // Display results.
    cout << "The area of the trianlge for base " << b << " and height " << h << "is " << A << endl;
    // End program.
    return 0;
}