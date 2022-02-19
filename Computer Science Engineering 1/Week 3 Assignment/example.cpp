#include <iostream>
using namespace std;

int main()
{
    double var1, var2;

    cout << "Enter first number:    " << endl;
    cin >> var1;

    cout << "Enter second number: " << endl;
    cin >> var2;

    cout << "What do you want to do with the numbers?" << endl;
    cout << "+ add" << endl;
    cout << "- subtract" << endl;
    cout << "* multiply" << endl;
    cout << "/ divide" << endl;

    char decision;
    cin >> decision;

    switch (decision)
    {
    case '+':
        cout << var1 << " + " << var2 << " = " << (var1 + var2) << endl;
        break;
    case '-':
        cout << var1 << " - " << var2 << " = " << (var1 - var2) << endl;
        break;
    case '*':
        cout << var1 << " * " << var2 << " = " << (var1 * var2) << endl;
        break;
    case '/':
        if (var2) // var2 !=0
            cout << var1 << " / " << var2 << " = " << (var1 / var2) << endl;
        else
            cout << "You can't divide by 0" << endl;
        break;
    default:
        cout << "You typed the wrong character";
    }
    return 0;
}