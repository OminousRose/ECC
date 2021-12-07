//    Name: Eric Flores
//    Assignment: Lab 1
//    Date: 11/22/2021
//
//    Description: This program allows a user to input a string and will make use of pointers
//                 in order to reverse the string. The input string will then be displayed to the
//                 console after the string is input.
//
//
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string.h>

using namespace std;

void reverse(char *s);

int main()
{
    char str[100] = ""; // Set the character size to 100
    cout << "This program reverses a user input string!" << endl;
    cout << "Enter your string:" << endl; // Prompt user to enter a string
    cin.get(str, 100);                    // Using only cin >> str will only reverse the first part of the string if a space is used.

    reverse(str);

    cout << "The string reversed would be:" << endl;
    cout << str << endl; // Output

    return 0;
}

void reverse(char *s)
{
    char *front, *rear, temp; // Initialize *front, *rear, and a temp that will be used to assist in reversing

    front = s;
    rear = s + strlen(s) - 1;
    while (front < rear)
    {

        temp = *front;
        *front = *rear; // During the while loop, the program uses a temp character to store the front character. So after the rear character is swapped to the front,
        *rear = temp;   // the rear character is replaced with the front character, which was stored as a temp. Then the process repeats until the whole string is reversed.

        front++; // After the first character swaps, the code moves on to the next character to the right
        rear--;  // After the rear character swaps to the front, the code moves to the previous character to the left until can't procede past the front character.
    }
    return;
}
