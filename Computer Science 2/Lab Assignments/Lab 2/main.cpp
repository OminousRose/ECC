//    Name: Eric Flores
//    Assignment: Lab 2
//    Title: Vectors  
//    Date: 11/23/2021  
// 
//    Description: This program stores user inputs into a vector. After the user inputs the integer -1,
//                 The program computes a histogram and prints the histogram to standard output. 
//                 The data is displayed as how many times a certain integer was input by the user and it progressively
//                 goes from lowest integer input to highest integer input.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    vector<int> vec_int;                // Initialize the vector and an int to store into the vector
    int num;

    cout << "Enter the student's scores to be organized, when you are finished enter -1" << endl;
    cin >> num;                         // Asks for user input
    
            while(num !=-1){                                // The program will keep looping as long as -1 is not the input
                
                vec_int.push_back(num);
                cin >> num;

            }

    int max = *(max_element(vec_int.begin(), vec_int.end()))+1;     // the max is set to the highest integer in the vector plus one
    int *hist= new int[max];                
    for(int i=0; i<max; i++) hist[i] = 0;
    for(int i=0; i<vec_int.size(); i++)                         //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    hist[vec_int[i]]++;                                         //This code progressively keeps adding 1 from 0 until it finds the same integer located in the vector
    for(int i=0; i<max; i++){                                   //it counts it and proceeds to add 1 until it finds the next integer in the vector, process repeats
    if(hist[i]!=0)                                              //Program loops until it hits the amount of integers in the vector so it can display the amount of each int
    cout <<"Number of "<< i<<"'s: " << hist[i] << endl;         //    Output
    }
    return 0;
}