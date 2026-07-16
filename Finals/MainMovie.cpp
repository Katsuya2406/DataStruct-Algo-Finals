#include "Movie.h"
#include <iostream>
#include <string>
#include <queue>
#include <limits>

using namespace std;

int main() {
    
    //initializes the core data structures movie linked list and customer queue with their .txt file path.
    Movie* movieHead = nullptr; 
    queue<string> customerQueue;
    const string movieFile = "movieList.txt";
    const string customerFile = "customerQueue.txt";
	
	//load previously saved movie records into the linked list and customer data into the queue.
    loadMoviesFromFile(movieHead, movieFile);
    loadQueueFromFile(customerQueue, customerFile);

    int choice;

    while (true) {
        displayMenu();

        //input validation to prevent infinite loops if a user types a letter.
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		//the options from the previously made functions.
        switch (choice) {
            case 1:
                addMovie(movieHead); 
                break;
                
            case 2:
                deleteMovie(movieHead); 
                break;

            case 3:
                rentMovie(movieHead, customerQueue); 
                break;
                
            case 4:
                returnMovie(movieHead, customerQueue); 
                break;

            case 5:
                viewNextMovie(movieHead);
                break;

            case 6:
                searchMovie(movieHead); 
                break;

            case 7:
                displayCustomerQueue(customerQueue);
                break;

            case 8:
                displayMovies(movieHead);
                break;

            case 9:
                checkIfEmpty(movieHead); 
                break;
                
			case 10:
                //save the states to their text files upon exit.
                saveMoviesToFile(movieHead, movieFile);
                saveQueueToFile(customerQueue, customerFile);
                cout << "Saving to File, Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
