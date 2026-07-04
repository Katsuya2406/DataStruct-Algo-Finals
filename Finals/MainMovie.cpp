#include "Movie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main() {      
	    Movie movie;

          // <-- Fixed

    queue<Movie> movieQueue;  // <-- Declare the queue

    int choice;
    
while (true)
    {
        movie.displayMenu();

        cin >> choice;
        cin.ignore();

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        movie.addMovie(movieQueue); // <-- Make sure the name matches
        break;

    default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
}
    return 0;
}
