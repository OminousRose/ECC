/*
Name: Eric Flores
Date: 5/11/2022
Assignment: Week 12 Assignment
Description: Complete program 8_4 on page 449. Submit screen print showing it running and .cpp file
Program: 8_4: This program determines the locations of peaks in an elevation grid of data
*/
#include <iostream> //Required for cin, cout
#include <fstream>  //Required for ifstream
#include <string>   //Required for string
using namespace std;
int const N{25};
// Function prototypes.
bool isPeak(const double grid[][N], int r, int c);

int main()
{
    // Declare objects.
    int const N{25};
    int nrows, ncols;
    double elevation[N][N];
    string filename;
    ifstream file1;
    // Prompt user for file name and open file for input.
    cout << "Enter the name of the input file.\n";
    cin >> filename;
    file1.open(filename);
    if (file1.fail())
    {
        cerr << "Error opening input file\n";
        exit(1);
    }
    file1 >> nrows >> ncols;
    if (nrows > N || ncols > N)
    {
        cerr << "Grid is too large, adjust program.";
        exit(1);
    }
    // Read information from data file into array.
    for (int i = 0; i < nrows; ++i)
    {
        for (int j = 0; j < ncols; ++j)
        {
            file1 >> elevation[i][j];
        }
    }
    // Determine and print peak locations.
    cout << "Top left point defined as row 0, column 0 \n";
    for (int i = 1; i < nrows - 1; ++i)
    {
        for (int j = 1; j < ncols - 1; ++j)
        {
            if (isPeak(elevation, i, j))
            {
                cout << "Peak at row: " << i
                     << " column: " << j << endl;
            }
        }
    }
    // close file
    file1.close();
    // Exit program.
    return 0;
}
bool isPeak(const double grid[][N], int i, int j)
{
    if ((grid[i - 1][j] < grid[i][j]) &&
        (grid[i + 1][j] < grid[i][j]) &&
        (grid[i][j - 1] < grid[i][j]) &&
        (grid[i][j + 1] < grid[i][j]))
        return true;
    else
        return false;
}