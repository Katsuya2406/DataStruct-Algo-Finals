#include "Movie.h"
#include <string>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;
Movie newMovie;


void Movie::displayMenu()
{
    cout << endl;
    cout << "Cinema Ticket Booking System" << endl;
    cout << "1. Add a customer" << endl;
    cout << "2. Serve a customer" << endl;
    cout << "3. View the next customer" << endl;
    cout << "4. Check if the queue is empty" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void Movie::addMovie(queue<Movie>& movieQueue) {
string movie;
//TODO

cout << "Enter the name of the customer to add: ";
cin>>movie;
movieQueue.push(newMovie);
cout << "Customer added: " << movie << endl;
}

