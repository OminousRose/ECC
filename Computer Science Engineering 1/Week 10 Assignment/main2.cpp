/*
Name: Eric Flores
Date: 5/10/2022
Assignment: Week 10 Assignment
Description: Complete program 6_8 and 6_9. Submit screen prints showing them running and .cpp files
Program: 6_9: This program calculates the percentage points that lie outside of a critical radius
*/

#include <iostream>
#include <fstream>
using namespace std;

// Function prototype
double distance(double x1, double y1, double x2, double y2);

int main()
{
    // Declare objects
    int pointCount(0), outside(0);
    double x, y, criticalRad;
    const double xORIGIN(0), yORIGIN(0);
    double dist, radiusOuter, radiusInner;

    // open input files
    ifstream fin("compositeMaterialsSim1.dat");
    if (fin.fail())
    {
        cout << "Could not open data file compositeMaterialsSimn1.dat" << endl;
        exit(1);
    }

    // Input critical radius from user
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
        dist = distance(x, y, xORIGIN, yORIGIN);
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
// Required for sqrt and pow
#include <cmath>
double distance(double x1, double y1, double x2, double y2)
{
    double d1, d2, d;
    d1 = x2 - x1;
    d2 = y2 - y1;
    d = sqrt(pow(d1, 2) + pow(d2, 2));
    return d;
}