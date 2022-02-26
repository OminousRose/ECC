/*
Name: Eric Flores
Date: 2/25/2022
Assignment: Week 4 Assignment
Description: Problem 30 of chapter 3 requires a program that prompts the user to input two
            integer numbers, then prints a vlue of the true if the first number is evenly divisible
            by the second number.
*/
#include <iostream>
using namespace std;

int main()
{
    // State the purpose of this program and instructs user with a direction.
    cout << "This program will print a value of true if the first number is evenly divisible by the second number you put" << endl;
    cout << "Enter two integer numbers." << endl;
    // Declare variables a and b
    int a = 0, b = 0;
    // Prompt the user to enter two integer numbers.
    cin >> a >> b;
    // Conditional statement to check if the first number is evenly divisible by the second.
    // If true
    if (a % b == 0)
    {
        cout << "The first number is evenly divisible by the second number: True!" << endl;
    }
    // If false
    else
    {
        cout << "The first number is evenly divisible by the second number: False!" << endl;
    }
    // End of program.
    return 0;
}