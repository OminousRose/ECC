//    Name: Eric Flores
//    Assignment: Lab 14
//    Title:
//    Date: 12/13/2021
//
//    Description: Create a base class called Vehicle that has the manufacturer's name (type
//                 string), number of cylinders in the engine (type int), and owner (type
//                 string). Include a default constructor that would initialize the manufacturer
//                 to an empty string and the number of cylinders to 0, and call the default
//                 constructor of the Person class to initialize the owner. Also include a
//                 constructor that would accept the manufacturer's name, number of cylinders,
//                 and a Person object to initialize the corresponding member variables. Include
//                 the aproppriate get/set member functions for all member variables.
//                 Then create a class called Truck that is derived from the Vehicle class
//                 and has these additional properties: the load capacity in tons (type double)
//                 and towing capacity in pounds (type int). Include a default constructor that
//                 would set all member variables to 0 and call the default constructor of class
//                 Vehicle; also include a constructor that would initialize the object to the
//                 values of its arguments. Overload the << operator such that it outputs a
//                 string of the following format:
//                 Mack (12 cylinders, 22 tons maximum load, 17000 lbs towing capacity), owned by Jim
//                 Write a test program that would prompt the user for the number of trucks
//                 they wish to enter, then for each of the trucks read in the data from standard
//                 input, and finally output the "winner" -- i.e. the truck that has the greatest
//                 combined load and towing capacity.
#include <iostream>
#include <string>
using namespace std;
// create a base class called Vehicle that has the
class Vehicle
{
private:
    // manufacturer's name (type string ),
    // number of cylinders in the engine (type int ),
    // and owner (type string ).
    string name;
    int number_of_cylinders;
    string owner;

public:
    // include a default constructor that would initialize the manufacturer to an empty string and the number of cylinders to 0,
    Vehicle()
    {
        name = "";
        number_of_cylinders = 0;
        owner = ""; // and call the default constructor of the Person class to initialize the owner.
    }
    // also include a constructor that would accept the manufacturer's name , number of cylinders, and a
    // person object to initialize the corresponding member variables .
    Vehicle(string n, int c, string o)
    {
        name = n;
        number_of_cylinders = c;
        owner = o;
    }
    // include the aproppriate get/set member functions for all member variables .
    void setName(string n) { name = n; }
    void setNumber_of_cylinders(int n) { number_of_cylinders = n; }
    void setOwner(string n) { owner = n; }
    string getName() { return name; }
    int getNumber_of_cylinders() { return number_of_cylinders; }
    string getOwner() { return owner; }
};
// then create a class called Truck that is derived from the Vehicle class and has these additional properties:
class Truck : public Vehicle
{
private:
    // the load capacity in tons (type double )
    // and towing capacity in pounds (type int ).
    double load_capacity;
    int towing_capacity;
    .
        // include a default constructor that would set all member variables to 0 and call the default constructor of class Vehicle;
        public : Truck() : Vehicle()
    {
        load_capacity = 0.0;
        towing_capacity = 0;
    }
    // also include a constructor that would initialize the object to the values of its arguments .
    Truck(string n, int c, string o, double l, int t) : Vehicle(n, c, o)
    {
        load_capacity = l;
        towing_capacity = t;
    }
    void setLoad_capacity(double l) { load_capacity = l; }
    void setTowing_capacity(int t) { towing_capacity = t; }
    double getLoad_capacity() { return load_capacity; }
    int getTowing_capacity() { return towing_capacity; }
    // overload the << operator such that it outputs a string of the following format:
    friend ostream &operator<<(ostream &out, Truck T);
};
ostream &operator<<(ostream &out, Truck T)
{
    out << T.getName() << " (" << T.getNumber_of_cylinders() << " cylinders, " << T.load_capacity << " tons maximum load, " << T.towing_capacity << " lbs towing capacity), owned by " << T.getOwner() << endl;
    return out;
}

// write a test program that would prompt the user for the number of trucks they wish to enter, then for each of the trucks read in the
// data from standard input, and finally output the "winner" -- i.e. the truck that has the greatest combined load and towing capacity.
int main()
{
    int n;
    cout << "Enter the number of contestants: ";
    cin >> n;
    cout << endl;
    Truck *T = new Truck[n];
    string name, o;
    int c, t;
    double l;
    int max_index = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter contestant " << (i + 1) << " info." << endl;
        cout << "Enter truck's manufacturer: ";
        cin >> name;
        cout << "Enter truck's number of cylinders: ";
        cin >> c;
        cout << "Enter truck's owner: ";
        cin >> o;
        cout << "Enter truck's maximum load (in tons): ";
        cin >> l;
        cout << "Enter truck's maximum towing capacity (in pounds): ";
        cin >> t;
        T[i].setName(name);
        T[i].setNumber_of_cylinders(c);
        T[i].setOwner(o);
        T[i].setLoad_capacity(l);
        T[i].setTowing_capacity(t);
        if (T[i].getLoad_capacity() > T[max_index].getLoad_capacity() && T[i].getTowing_capacity() > T[max_index].getTowing_capacity())
        {
            max_index = i;
        }
    }
    cout << "Winner is " << endl;
    cout << T[max_index];
    system("pause");
    return 0;
}