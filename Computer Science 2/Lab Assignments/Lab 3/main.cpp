//    Name: Eric Flores
//    Assignment: Lab 3
//    Title: Odometer
//    Date: 11/23/2021
//
//    Description: This program uses classes to create a makeshift odometer like the one's found in many vehicles
//                 User fuel efficiency and distances so the program is able to use those inputs to call member functions
//                 inside the Odometer class to calculate gallons consumed over the course of two trips.
//
//
#include <iostream>
using namespace std;

// Class declaration
class Odometer
{
    // Member decleration
private:
    double distanceTraveled;
    double F_efficiency;

    // Required functions needed in main
public:
    Odometer(double x)
    {
        F_efficiency = x;
        distanceTraveled = 0;
    }

    //Reset the odometer to zero after each trip
public:
    void OdometerReset()
    {
        distanceTraveled = 0;
    }
    // Function that adds each distance to the odometer total
    void distAddedToOdometer(double travelDist)
    {
        distanceTraveled = distanceTraveled + travelDist;
    }
    // Returns the value needed to display the amount of gallons consumed
    // for the amount of miles traveled
    double GalConsumed()
    {
        return (distanceTraveled / F_efficiency);
    }
};

int main()
{
    // Declare double variables to include decimals
    double fuel_eff;
    double dist1, dist2;

    cout << "Enter your fuel efficiency in miles per gallon: \n";
    cin >> fuel_eff;
    //set obj as variable of the odometer class which calls in member functions found only in the class
    // and also store the fuel efficiency in the class function
    Odometer obj(fuel_eff);

    cout << "Now enter your first trip distance in miles: \n";
    cin >> dist1;
    // obj calls the distance to add to the odometer function
    // which is only possible if the void function was set to public so int main
    // can access it.
    obj.distAddedToOdometer(dist1);

    cout << "Now enter your second distance in miles \n";
    cin >> dist2;
    // obj calls the distance to add to the odometer function
    // which is only possible if the void function was set to public so int main
    // can access it.
    obj.distAddedToOdometer(dist2);

    cout << "The car used " << obj.GalConsumed() << "gallon(s)" << endl;

    obj.OdometerReset();
    cout << "Enter your third trip distance in miles \n";
    cin >> dist1;
    // obj calls the distance to add to the odometer function
    // which is only possible if the void function was set to public so int main
    // can access it.
    obj.distAddedToOdometer(dist1);

    cout << "Enter the fourth trip distance in miles \n";
    cin >> dist2;
    // obj calls the distance to add to the odometer function
    // which is only possible if the void function was set to public so int main
    // can access it.
    obj.distAddedToOdometer(dist2);
    // Gal consumed calculated by using the value located in the class "odometer distance"
    // and "fuel efficiency" which are directed to divide each other in the Galconsumed
    // function located in the public member function
    cout << "This vehicle consumed " << obj.GalConsumed() << " gallon(s)" << endl;

    return 0;
}
