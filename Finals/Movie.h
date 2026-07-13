#ifndef MOVIE_H
#define MOVIE_H

#include <queue>
#include <string>

using namespace std;


//Queue Functions:
void loadQueueFromFile(queue<string>& q, const string& filename);
void saveQueueToFile(const queue<string>& q, const string& filename);

//Main Functions:
void addMovie(queue<string>& movieQueue);
void rentMovie(queue<string>& movieQueue, queue<string>& customerQueue);
void viewNextMovie(const queue<string>& movieQueue);
void checkIfEmpty(const queue<string>& movieQueue);

//Extra Functions
void searchMovie();
void displayMovie();
void displayCustomerQueue(const queue<string>& customerQueue);
void returnMovie(queue<string>& movieQueue, queue<string>& customerQueue);

//Menu
void displayMenu();

#endif