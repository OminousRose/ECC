/*
Name: Eric Flores
Date: 5/11/2022
Assignment: Week 11 Assignment
Description: Complete program 7_7 on page 371. Submit screen print showing it running and .cpp file
Program: 7_7: This program computes a set of statistical measurements from a speech signal.
*/
#include <iostream>   //Required for cin, cout.
#include <fstream>    //Required for ifstream.
#include <string>     //Required for string
#include <cmath>      //Required for abs()
#include "stat_lib.h" //Required for mean(), variance(), std-dev()
using namespace std;
// Declare function prototypes and define constants.
double ave_power(double x[], int n);
double ave_magn(double x[], int n);
int crossings(double x[], int n);
int main()
{
    // Declare objects.
    const int MAXIMUM = 2500;
    int npts(0);
    double speech[MAXIMUM];
    string filename;
    ifstream file_1;
    // Prompt user for file name and
    // open file.
    cout << "Enter filename ";
    cin >> filename;
    file_1.open(filename);
    if (file_1.fail())
    {
        cout << "error opening file " << filename
             << endl;
        return 0;
    }
    {
        // Read information from a data file. *
        while (npts <= MAXIMUM - 1 && file_1 >> speech[npts])
        {
            npts++;
        } // end while
        // Compute and print statistics.
        cout << "Digit Statistics \n";
        cout << "\tmean: " << mean(speech, npts) << endl;
        cout << "\tstandard deviation: "
             << std_dev(speech, npts) << endl;
        cout << "\tvariance: " << variance(speech, npts)
             << endl;
        cout << "\taverage power: " << ave_power(speech, npts)
             << endl;
        cout << "\taverage magnitude: "
             << ave_magn(speech, npts) << endl;
        cout << "\tzero crossings: " << crossings(speech, npts)
             << endl;
        // Close file and exit program.
        file_1.close();
        return 0;
    }
}
double ave_power(double x[], int n)
{
    // Declare and initialize objects.
    double sum(0);
    // Determine average power.
    for (int k = 0; k < n; ++k)
    {
        sum += x[k] * x[k];
    }
    // Return average power.
    return sum / n;
}

double ave_magn(double x[], int n)
{
    // Declare and initialize objects.
    double sum(0);
    // Determine average magnitude.
    for (int k = 0; k < n; ++k)
    {
        sum += abs(x[k]);
    }
    // Return average magnitude.
    return sum / n;
}
int crossings(double x[], int n)
{
    // Declare and initialize objects.
    int count(0);
    // Determine number of zero crossings.
    for (int k = 0; k < (n - 1); ++k)
    {
        if (x[k] * x[k + 1] < 0)
            count++;
    }
    // Return number of zero crossings.
    return count;
}
