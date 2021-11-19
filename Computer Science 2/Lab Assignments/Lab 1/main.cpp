#include <iostream>
#include <cstring>

using namespace std;

string reverse(char word[100]);

int main()
{
cout << "This program will take a user input string and output the string in reverse." << endl;

char Rstring[100];

cout << "Enter a string: \n";
cin >> Rstring;


string result = reverse(Rstring);

cout << result;
}

string reverse(char word[100])
{
    char a= 'a';
    char b= 'b';

    char *front=&a;
    char *rear=&b;
    for (int i=0; i<(strlen(word)/2);i++)
    {
        front[0]=word[i];
            rear[0]=word[strlen(word)-1-i];
            word[i]=*rear;
            word[strlen(word)-1-i]=*front;
    }
        
    return word;
        


}










}