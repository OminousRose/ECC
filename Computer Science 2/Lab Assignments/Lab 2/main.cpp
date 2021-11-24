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

    // Initialize score container and scores int
    vector<int> scoresVector;                
    int studentScore = 0;

    cout << "Enter the student's scores to be organized, when you are finished enter -1" << endl;
    cin >> studentScore;                         // Asks for user input

            // The program will keep looping as long as -1 is not the input
            while(studentScore !=-1){                                
                
                scoresVector.push_back(studentScore);
                cin >> studentScore;

            }

    // Dereferencing iterator pointing to the element with the largest value in the range [first,last)
    int maxScore = *(max_element(scoresVector.begin(), scoresVector.end()));     

    // Allocate dynamic array with maxScore size + 1 for index offset
    int *hist = new int[maxScore + 1];          

    // Initializing all possible elements in array to 0
    for(int i=0; i <= maxScore; i++) hist[i] = 0;

    // Updates histogram
    // Ex. 1, 1, 3, 4, 5 - Scores
    // Max score = 5
    // Hist[0, 1, 2, 3, 4, 5]
    // Hist[0] = 0 ... Hist[5] = 0
    // Hist[scoresVector[0]] == Hist[1] = 0++ = 1
    // Hist[scoresVector[1]] == Hist[1] = 1++ = 2
    for(int i=0; i <= scoresVector.size(); i++)                         
        hist[scoresVector[i]]++;     

    // Prints available numbers in histogram                                        
    for(int i=0; i<=maxScore; i++){                                   
        if(hist[i]!=0)                                              
            cout <<" Number of "<< i<<"'s: " << hist[i] << endl;        
    }

    return 0;
}