/*
Name: Eric Flores
Date: 5/11/2022
Assignment: Week 13 Assignment
Description: Complete program 9_7 on page 498. Submit screen print showing it running and .cpp file
Program: 9_7: This program counts the number of times a specified letter appears in an uppercase string.
*/
#include <iostream> //Required for cout
#include <cctype>   //Required for toupper()

using namespace std;
// Function prototypes.

void stringupper(char *);
int countchar(const char *, char);
int main()
{
    // Declare and initialize objects.
    char strg1[] = "abbcfgwdbibbw";
    char *ptr_strg1 = strg1, ch = 'B';
    // Convert string to uppercase.
    stringupper(ptr_strg1);
    cout << "The letter " << ch << " appears "
         << countchar(ptr_strg1, ch) << " times in the string "
         << ptr_strg1 << endl;
    return 0;
}
int countchar(const char *ptr_strg, char ch)
{
    // Declare and initialize local objects.
    int cnt{0};
    // While not end of string.
    while (*ptr_strg)
    {
        // Look for ch and increment cnt.
        if (*ptr_strg == ch)
            cnt++;
        // Mover pointer to next character
        ptr_strg++;
    }
    return cnt;
}
void stringupper(char *ptr_strg)
{
    // While not end of string.
    while (*ptr_strg)
    {
        // Convert character to uppercase
        *ptr_strg = toupper(*ptr_strg);
        // Mover pointer to next character
        ptr_strg++;
    }
}