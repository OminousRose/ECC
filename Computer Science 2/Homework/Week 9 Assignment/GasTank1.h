// Week 9 Assignment
//     Name : Eric Flores
//            1. Write the
//            interface(.h file) of a class GasTank containing :
// An data member named amount of type double.An data member named capacity of type double.A constructor that accepts a parameters of type double.
// A function named addGas that accepts a parameter of type double and returns no value.
// A function named useGas that accepts a parameter of type double and returns no value.
// A function named isEmpty that accepts no parameters and returns a boolean value.
// A function named isFull that accepts no parameters and returns a boolean value.
// A function named getGasLevel that accepts no parameters and returns double.
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
};