/*
Name: Eric Flores
Date: 2/11/2022
Assignment: Chapter 2_5 Program
Description: Week 2 assignment requires completion and execution of example program 2_5 on page 74 in the textbook.
*/

/* Program chapter2_5 */
/*
/* This program computes area of a circle. */
/* Results are displayed with two digits */
/* to the right of the decimal point. */
#include <iostream> //Required for cout, endl.
#include <iomanip>  //Required for setw() setprecision(), fixed.
#include <cmath>    //Required for acos().
using namespace std;
const double PI = acos(-1.0);
int main()
{
    //Declare and initialize objects,
    double radius{10}, area;
    area = PI * radius * radius;

    cout << fixed << setprecision(2);
    cout << "The radius of the circle is: "
         << setw(10) << radius << "  centimeters" << endl;
    cout << "The area of the circle is:  " << setw(10) << area << " square centimeters" << endl;

    // Exit program
    return 0;
}