#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <queue>

using namespace std;

class Movie
{
public:
	
    string title;

    void loadQueueFromFile(queue<Movie>& movieQueue, const string& filename);
    void saveQueueToFile(queue<Movie> movieQueue, const string& filename);

    void addMovie(queue<Movie>& movieQueue);
    void deleteMovie(queue<Movie>& movieQueue);
    void searchMovie(queue<Movie> movieQueue);
    void displayMenu();
};

#endif