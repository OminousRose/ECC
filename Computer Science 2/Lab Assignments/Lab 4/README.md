Consider a class Movie that contains the following information about a
movie:

* Title
* MPAA Rating (e.g. G, PG, PG-13, R)
* Number of people who rated this movie as a 1
* Number of people who rated this movie as a 2
* Number of people who rated this movie as a 3
* Number of people who rated this movie as a 4
* Number of people who rated this movie as a 5

Implement the Movie class such that it is able to contain the above
information. Include a constructor that would accept two parameters and
initialize the movie's title to the value of its first parameter and the movie's
MPAA rating to the value of its second parameter, and public rating to 0. Also
include accessor member functions for title and MPAA rating. Include a member
function to increment the public rating that will only accept integer values
between 1 and 5. Finally, write a member function that would return the average
public rating of a movie.

Write a program that would use your Movie class by first asking the user to
input movie title and MPAA rating, then create an object using the constructor,
and then allow the user to enter a space-separated list of people ratings,
terminating with -1. Finally, the program will output the title of the movie,
its MPAA rating, and its average public rating.