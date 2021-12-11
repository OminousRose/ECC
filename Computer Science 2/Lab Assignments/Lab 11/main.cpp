//    Name: Eric Flores
//    Assignment: Lab 11
//    Title:   Tower of Hanoi
//    Date: 12/11/2021
//
//    Description: This program simulates the Tower of Hanoi puzzle, in which "n" disks of different sizes are
//                 stacked in ascending order on one rod and there are two other rods with no disks on them.
//                 The objective is to move all disks from the first rod to the third.
//                 The code itself is a recursive function that outputs the sequence of steps needed to solve
//                 the puzzle with "n" number of disks
#include <iostream>
using namespace std;
//  declare void recursive and nonrecursive scenario functions
void TOH(int n, char rod1, char rod2, char rod3)
{
    if (n == 1)
    {
        cout << "Move Disk " << n << " from " << rod1 << " to " << rod3 << endl;
        return;
    }
    TOH(n - 1, rod1, rod3, rod2);
    cout << "Move Disk " << n << " from " << rod1 << " to " << rod3 << endl;
    TOH(n - 1, rod2, rod1, rod3);
}
int main()
{
    // store the number of disks
    int n;
    cout << "Enter no. of disks:";
    // set the number of disks to user input int
    cin >> n;
    // output
    TOH(n, 'A', 'B', 'C');

    return 0;
}