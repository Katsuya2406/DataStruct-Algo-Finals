#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

//movie as a class in-order to list down the data members of title, year, and publisher. 
class Movie{
//by encapsulation, private data members and the pointer for the linked list.
private:
	//data members that will store the value later given by the user.
    string movieTitle;
    int movieYear;
    string moviePublisher;
    
    //for the next movie in the list.
    Movie* next;

public:
    //constructor (no parameter) default value.
    Movie();
    Movie(string title, int year, string publisher);

    //setters, access the private data members.
    void setMovieTitle(string title);
    void setMovieYear(int year);
    void setMoviePublisher(string publisher);
    void setNext(Movie* n);

    //getters, modifies the value of private data members.
    string getMovieTitle() const;
    int getMovieYear() const;
    string getMoviePublisher() const;
    Movie* getNext() const;
};

//functions for loading and saving the linked list of movies to a file.
void loadMoviesFromFile(Movie*& head, const string& filename);
void saveMoviesToFile(Movie* head, const string& filename);

//functions for managing the movie linked list.
void addMovie(Movie*& head);
void deleteMovie(Movie*& head);
void searchMovie(Movie* head);
void displayMovies(Movie* head);
void viewNextMovie(Movie* head);
void checkIfEmpty(Movie* head);

//functions for loading and saving the customer queue.
void loadQueueFromFile(queue<string>& q, const string& filename);
void saveQueueToFile(const queue<string>& q, const string& filename);

//functions for renting and returning movies using the customer queue.
void rentMovie(Movie*& head, queue<string>& customerQueue);
void returnMovie(Movie*& head, queue<string>& customerQueue);
void displayCustomerQueue(const queue<string>& customerQueue);

//displays the main menu.
void displayMenu();

#endif
