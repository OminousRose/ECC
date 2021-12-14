// 2.
//     Write the implementation(.cpp file) of the GasTank class of the previous exercise.The full specification of the class is :
//     A data member named amount of type double.An data member named capacity of type double.
//     A constructor that accepts a parameter of type double.The value of the parameter is used to initialize the value of capacity.
//     The constructor will also set amount to zero.
//     A function named addGas that accepts a parameter of type double.
//     The value of the amount instance variable is increased by the value of the parameter.
//     However, if the value of amount is increased beyond the value of capacity, amount is set to capacity.
//     A function named useGas that accepts a parameter of type double.The value of the amount data member is decreased by the value of the parameter.
//     However, if the value of amount is decreased below 0, amount is set to 0.
//     A function named isEmpty that accepts no parameters and returns a boolean value.isEmpty returns true if the value of amount is less than 0.1, and false otherwise.
//     A function named isFull that accepts no parameters and returns a boolean value..isFull returns true if the value of amount is greater than capacity - 0.1, and false otherwise.
//     A function named getGasLevel that accepts no parameters.getGasLevel returns the value of the amount data member.
#include <iostream>
#include "GasTank1.h"

GasTank::GasTank(double a)
{
    capacity = a;
    amount = 0;
}

void GasTank::addGas(double b)
{
    amount += b;
    if (amount > capacity)
        amount = capacity;
}
void GasTank::useGas(double c)
{
    amount -= c;
    if (amount < 0)
        amount = 0;
}
bool GasTank::isEmpty()
{
    if (amount < 0.1)
        return true;
    else
        return false;
}
bool GasTank::isFull()
{
    if (amount > (capacity - 0.1))
        return true;
    else
        return false;
}
double GasTank::getGasLevel()
{
    return amount;
}