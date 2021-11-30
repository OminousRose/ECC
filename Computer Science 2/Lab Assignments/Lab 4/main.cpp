//    Name: Eric Flores
//    Assignment: Lab 4
//    Title: Odometer  
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
//Class declaration
class Movie
{
    // Member declaration
    private:
        string Movie_name, MPAA_Rating;
        // Set the movie rating in an array from 0 to 5 star(s)     
        int Rate[5];
    // Functions necessary to be called from main
    public:
         
        Movie(string Movie)
        {
            Movie_name = Movie;
            MPAA_Rating = 5;
            Rate[0]=0;
            Rate[1]=0;
            Rate[2]=0;
            Rate[3]=0;
            Rate[4]=0;
            Rate[5]=0;
        }
        
        string getMovie_name()
        {
            return Movie_name;
        }
        
        void setMovieName(string str)
        {
            Movie_name = str;
        }

      string getMPAA_rating()
      {
          return MPAA_Rating;
      }  
      
      void setMPAA_rating(string str)
      {
          MPAA_Rating = str;
      }

      void Rating(int stars)
      {
          int s = stars;
          if(stars>0 && stars <=5)
            {
                this->Rate[stars-1]++;
            }
            // In the event a user inputs a nonvalid number, the program recognizes an error
            else
            {
                cout << "Number is not in the 1-5 range of rating!" << endl;
            }
      }

      float getAverage()
      {
          float Rating = Rate[0]+Rate[1]+Rate[2]+Rate[3]+Rate[4];
          float denom = 5.0;
          float result = Rating/denom;

          return result;
      }
};


int main()
{
    string movie;
    int rating;
    char again = 'y';

    cout << "Enter a movie name. \n";
    char c = 0;
    while(c !='\n')
        {
            c = cin.get();
            movie.push_back(c);
        }

        movie.erase(movie.end()-1);
        
        Movie obj1(movie);
        while(again == 'y' || again == 'Y')
        {
            cout << "Add a movie rating(1 through 5)\n";
            cin >> rating;
            obj1.Rating(rating);

            cout << "Continue adding ratings? (y/n) \n";
            cin >> again;
        }

        cout << "\n Enter a movie name \n";
        c = 0;
        while(c !='\n')
        {
            c = cin.get();
            movie.push_back(c);
        }

        movie.erase(movie.end()-1);

        Movie obj2(movie);

        again = 'y';
        while(again == 'y' && again == 'Y')
        {
            cout << "Add a movie rating\n";
            cin >> rating;
            obj2.Rating(rating);

            cout << "Continue adding ratings? (y/n)\n";
            cin >> again;
        }

        float avg1 = obj1.getAverage();
        float avg2 = obj2.getAverage();

        cout << "\nAverage rating for" << obj1.getMovie_name() <<":" << avg1 << endl;
        cout << "Average rating for" << obj2.getMovie_name() <<":" << avg2 << endl;

        system("pause");
        return 0;
}