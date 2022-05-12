#include <iostream>
#include <cmath>
#include "stat_lib.h"
double minval(const double x[], int n)
{
    // Declare objects.
    double min_x;
    // Determine minimum value in the array.
    min_x = x[0];
    for (int k = 1; k < n; ++k)
    {
        if (x[k] < min_x)
            min_x = x[k];
    }
    // Return minimum value.
    return min_x;
}
double mean(const double x[], int n)
{
    // Declare and initialize objects.
    double sum(0);
    // Determine mean value.
    for (int k = 0; k < n; ++k)
    {
        sum += x[k];
    }
    // Return mean value.
    return sum / n;
}
double median(const double x[], int n)
{
    // Declare objects.
    double median_x;
    int k;
    // Determine median value.
    k = floor(n / 2);
    if (n % 2 != 0)
        median_x = x[k];
    else
        median_x = (x[k - 1] + x[k]) / 2;
    // Return median value.
    return median_x;
}
double mean(const double x[], int n);
double variance(const double x[], int n) // Function header.
{
    // Declare objects.
    double sum(0), mu;
    // Determine variance.
    mu = mean(x, n);
    for (int k = 0; k < n; ++k)
    {
        sum += (x[k] - mu) * (x[k] - mu);
    }
    // Return variance.
    return sum / (n - 1);
}
// Declare function prototypes.
double variance(const double x[], int n);
double std_dev(const double x[], int n) // Function header.
{
    // Return standard deviation.
    return sqrt(variance(x, n));
}
