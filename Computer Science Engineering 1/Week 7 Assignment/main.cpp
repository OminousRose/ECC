/*
Name: Eric Flores
Date: 5/9/2022
Assignment: Week 7 Assignments
Description: Complete program Chapter 5_5 from the book. Submit screenshot and .cpp file.
Program: This program generates a file of height and velocity values for a weather balloon. The information is also printed in a report.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    // Declare and initialize objects.
    double initial, increment, final, time, height, velocity, max_time{0}, max_height{0};
    int loops, itime;
    string filename;
    ofstream balloon;

    // Prompt user for name of output file.
    cout << "Enter the name of the output file";
    cin >> filename;

    // Open output file
    balloon.open(filename);

    // Get user input.
    cout << "Enter initial value for table (in hours) \n";
    cin >> initial;
    cout << "Enter increment between lines (in hours) \n";
    cin >> increment;
    cout << "Enter final value for table (in hours) \n";
    cin >> final;

    // Set format flags for standard output.
    cout.setf(ios::fixed);
    cout.precision(2);
    // Set format flags for file output.
    balloon.setf(ios::fixed);
    balloon.precision(2);
    // Print report heading.
    cout << "\n\nWeather Balloon Information \n";
    cout << "Time Height Velocity \n";
    cout << "(hrs) (meters) (meters/s) \n";
    // Determine number of iterations required.
    // Use integer index to avoid rounding error.
    loops = (int)((final - initial) / increment);
    for (itime = 0; itime <= loops; itime++)
    {
        time = initial + itime * increment;
        height = -0.12 * pow(time, 4) + 12 * pow(time, 3) - 380 * time * time + 4100 * time + 220;
        velocity = -0.48 * pow(time, 3) + 36 * time * time - 760 * time + 4100;
        // Print report information to the screen.
        cout << setw(6) << time << setw(10) << height
             << setw(10) << velocity / 3600 << endl;
        // Write report information to a file.
        balloon << setw(6) << time << setw(10) << height
                << setw(10) << velocity / 3600 << endl;
        if (height > max_height)
        {
            max_height = height;
            max_time = itime;
        }
    }
    // Report maximum height and corresponding time.
    cout << "\nMaximum balloon height was "
         << setw(8) << max_height
         << " meters\nand it occurred at "
         << setw(6) << max_time << endl;
    // Close file and exit program.
    balloon.close();
    return 0;
}