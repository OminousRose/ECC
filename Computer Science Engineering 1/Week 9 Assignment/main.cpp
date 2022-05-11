/*
Name: Eric Flores
Date: 5/9/2022
Assignment: Week 9 Assignment
Description: Complete problem 20 from Chapter 5 in the book. Submit screenshot and .cpp file.
Problem: Assume that the file rocket1.txt contains an initial line that specifies the number
of actual data lines that follows. Write a program that reads these data and determines
the time at which the rocket begins falling back to Earth. (Hint: Determine the time
at which the altitude begins to decrease.)
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int time, alt, palt = 0, vel, acc, count, i, returntime = 0;
    FILE *in;
    in = fopen("rocket1.txt", "r");
    if (in == NULL)
    {
        cout << "Error opening rocket2!\n";

        return 1;
    }
    fscanf(in, "%d", &count);
    for (i = 0; i < count; i++)
    {
        fscanf(in, "%d %d %d%d", &time, &alt, &vel, &acc);
        if (alt < palt && returntime == 0)
            returntime = time;
        palt = alt;
    }
    cout << "The rocket begins to fall to earth at time %dseconds\n"
         << returntime;

    return 0;
}