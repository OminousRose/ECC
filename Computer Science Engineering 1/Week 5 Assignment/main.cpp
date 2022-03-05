/*
Name: Eric Flores
Date: 3/4/2022
Assignment: Week 5 Assignment
Description: Complete program 4_6 from the textbook and submit .cpp file and a screenshot
*/
#include <iostream>
using namespace std;

int main()
{
    double exam_score, sum(0), average;
    int counter;

    // Prompt user for input
    cout << "Enter the number of exam scores to be read ";
    cin >> counter;

    cout << "Enter " << counter << " exam scores separated "
         << " by whitespace ";

    // Input exam scores using counter-controlled loop.
    for (int i = 1; i <= counter; ++i)
    {
        cin >> exam_score;
        sum = sum + exam_score;
    }
    // Calculate average exam score.
    average = sum / counter;
    cout << counter << " students took the exam.\n";
    cout << "The exam average is " << average << endl;

    // Exit program
    return 0;
}