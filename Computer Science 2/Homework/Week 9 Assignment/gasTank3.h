// 3. Write the interface(.h file) of a class GasTank containing :
//     A data member named amount of type double.
//     A data member named capacity of type double.
//     A constructor that accepts a parameter of type double.
//     A function named addGas that accepts a parameter of type double and returns no value.
//     A function named useGas that accepts a parameter of type double and returns no value.
//     A function named isEmpty that accepts no parameters and returns a boolean value.
//     A function named isFull that accepts no parameters and returns a boolean value.
//     A function named getGasLevel that accepts no parameters and returns a double.
//     A function named fillUp that accepts no parameters and returns a double.
#include <iostream>

class GasTank
{
private:
    double amount;
    double capacity;

public:
    GasTank(double);
    void addGas(double);
    void useGas(double);
    bool isEmpty();
    bool isFull();
    double getGasLevel();
    double fillUp();
};
