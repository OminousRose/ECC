/*------------------------------------------------------*/
/* Point Class Chapter6_7 */
/* filename: Point.cpp */
#include "Point.h"  //Required for Point
#include <iostream> //Required for cout
#include <cmath>    //Required for sqrt() and pow()
using namespace std;
// Parameterized constructor
Point::Point(double x, double y)
{
    // input parameters x,y
    cout << " Constructing Point object, parameterized: \n";
    cout << " input parameters: " << x << " ," << y << endl;
    xCoord = x;
    yCoord = y;
}
// Default constructor
Point::Point()
{
    cout << " Constructing Point object, default: \n";
    cout << " initializing to zero" << endl;
    xCoord = 0.0;
    yCoord = 0.0;
} // Distance Formula
double Point::operator-(const Point &rhs) const
{
    double t1, t2, d;
    t1 = rhs.xCoord - xCoord; //(x2-x1)
    t2 = rhs.yCoord - yCoord; //(y2-y1)
    d = sqrt(pow(t1, 2) + pow(t2, 2));
    return d;
}
bool Point::operator==(const Point &rhs) const
{
    if (rhs.xCoord == xCoord &&
        rhs.yCoord == yCoord)
        return true;
    else
        return false;
}

void Point::setX(double xVal)
{
    xCoord = xVal;
}
void Point::setY(double yVal)
{
    yCoord = yVal;
}