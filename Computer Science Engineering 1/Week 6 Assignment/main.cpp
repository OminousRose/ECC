/*
Name: Eric Flores
Date: 3/11/2022
Assignment: Week 6 Program
Description: Complete Problem 20 from Chapter 4 in the book. Submit screenshot and .cpp file
Problem:  Generate a table of conversions from mph to ft/s. Start the mph column at 0 and
increment by 5 mph. The last line should contain the value 65 mph. (Recall that
1 mi = 5,280 ft.)
*/
#include <iostream>
using namespace std;

int main()
{
    float MPH, FPS;
    cout << "MPH" << '\t' << "FPS" << endl;

    for (MPH = 0; MPH <= 65; MPH = MPH + 5)
    {
        FPS = (MPH * 5280 / 3600);
        cout << MPH << '\t' << float(FPS) << endl;
    }
    return 0;
}