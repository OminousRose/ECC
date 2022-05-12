/*
Name: Eric Flores
Date: 5/9/2022
Assignment: Week 10 Assignment
Description: Complete program 6_8 and 6_9. Submit screen prints showing them running and .cpp files
Program: 6_8: This program calculates the percentage points that lie outside of a critical radius
*/

#include <iostream>
#include <fstream>
#include "Point.h"
using namespace std;

int main()
{
    // Declare objects
    const Point ORIGIN(0, 0);

    Point p;
    int pointCount(0), outside(0);
    double x, y, criticalRad;
    double dist, radiusOuter, radiusInner;

    // open input files
    ifstream fin("compositeMaterialsSim1.dat");
    if (fin.fail())
    {
        cout << "Could not open data file compositeMaterialsSim1.dat" << endl;
        exit(1);
    }

    // Input critical radius from user input
    cout << "Enter critical radius ";
    cin >> criticalRad;

    // Input radius of outer and inner cylinders
    fin >> radiusOuter >> radiusInner;

    // While not end of file, input point data
    fin >> x >> y;
    while (!fin.eof())
    {
        // increment point count
        ++pointCount;
        p.setX(x);
        p.setY(y);
        dist = p - ORIGIN;
        if (dist > criticalRad)
        {
            // increment outside counter
            ++outside;
        }
        fin >> x >> y;
    }

    // Print Results
    // Pre-Multiply by 100.0 to force floating point arithmetic
    cout << (100.0 * outside / pointCount) << "% lie outside the critical radius" << endl;
    return 0;
}