#ifndef MOVIE_H
#define MOVIE_H

#include <queue>
#include <string>

using namespace std;

void loadQueueFromFile(queue<string>& movieQueue, const string& filename);
void saveQueueToFile(const queue<string>& movieQueue, const string& filename);


void addMovie(queue<string>& movieQueue);
void rentMovie(queue<string>& movieQueue);
void viewNextMovie(const queue<string>& movieQueue);
void checkIfEmpty(const queue<string>& movieQueue);

//added functions
void searchMovie();


void displayMenu();

#endif