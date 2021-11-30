//    Name: Eric Flores
//    Assignment: Lab 4
//    Title: Movie Rating  
//    Date: 11/29/2021  
// 
//    Description: This program uses classes to simulate an average rating calculator based on user input movie names and
//                 user input ratings. Once the user sets the values the programs calls respective method functions located inside the class
//                 to determine the movie rating.
//
//
#include <iostream>
#include <string>
using namespace std;

// Class declaration
class Movie
{
// Member declaration
private:
  string title;
  string mpaa_rating;
     int num_rating1, num_rating2, num_rating3, num_rating4, num_rating5;
// Public member variables and functions necessary to compute: Title, MPAA rating, and public rating
public:
    Movie(string title, string mpaa_rating);
    string getTitle() const;
    string getMpaaRating() const;
    void incrementRating(int rating);
    double getAverage() const;
};
// Constructor that accepts two parameters and
// initializes the movie's title to the value of its first parameter and the movie's
// MPAA rating to the value of its second parameter,
Movie::Movie(string title, string mpaa_rating)

{
    this->title = title;

    this->mpaa_rating = mpaa_rating;

    num_rating1 = 0;
    num_rating2 = 0;
    num_rating3 = 0;
    num_rating4 = 0;
    num_rating5 = 0;
}

string Movie::getTitle() const
{

    return title;
}
string Movie::getMpaaRating() const
{
    return mpaa_rating;
}
// Member function that keeps track of each 1-5 star rating on the movie
//* Number of people who rated this movie as a 1
//* Number of people who rated this movie as a 2
//* Number of people who rated this movie as a 3
//* Number of people who rated this movie as a 4
//* Number of people who rated this movie as a 5
void Movie::incrementRating(int rating)
{
    switch(rating)
    {
    case 1:
            num_rating1++;
            break;
    case 2:
            num_rating2++;
            break;
    case 3:
            num_rating3++;
            break;
    case 4:
            num_rating4++;
            break;
    case 5:
            num_rating5++;
            break;
    }
}
// Member function that gets the average public viewer rating
double Movie:: getAverage() const
{
    int totalRating = num_rating1 + num_rating2*2 + num_rating3*3 + num_rating4*4 + num_rating5*5;

    int num_rating = num_rating1+num_rating2+num_rating3+num_rating4+num_rating5;

    return(((double)totalRating)/num_rating);
}

int main() 
{

    string title, mpaa_rating;
    int rating;
    //Title
    cout<<"Enter the movie title: \n ";
    getline(cin,title);

    title = title.substr(0,title.length());
    //MPAA Rating(e.g G, PG , PG-13 , R)
    cout<<"Now enter the MPAA rating: \n ";
    cin>>mpaa_rating;

    Movie movie(title,mpaa_rating);
    cout<<"Enter space-separated list of people ratings for the movie, when you are finished enter -1.\n ";
    //Add rating increments as long as -1 is not the rating value
    while(true)
    {
        cin>>rating;
        if(rating == -1)

            break;

        movie.incrementRating(rating);
    }
    // Output
    cout<<"\nMPAA rating for "<<movie.getTitle()<<" is "<<movie.getMpaaRating()<<", and the average people rating is "<<movie.getAverage()<<".";

    return 0;

}