#include "Movie.h"
#include <iostream>
#include <string>
#include <queue>
#include <limits>

using namespace std;

int main() {
    queue<string> movieQueue;
    queue<string> customerQueue;

    const string movieFile = "movieQueue.txt";
    const string customerFile = "customerQueue.txt";

    loadQueueFromFile(movieQueue, movieFile);
    loadQueueFromFile(customerQueue, customerFile);

    int choice;

    while (true) {
        displayMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addMovie(movieQueue);
                break;

            case 2:
                rentMovie(movieQueue, customerQueue);
                break;
                
            case 3:
            	returnMovie(movieQueue, customerQueue);
                break;

            case 4:
                viewNextMovie(movieQueue);
                break;

            case 5:
                searchMovie();
                break;

            case 6:
                displayCustomerQueue(customerQueue);
                break;

            case 7:
                displayMovie();
                break;

            case 8:
                checkIfEmpty(movieQueue);
                break;

            case 9:
                saveQueueToFile(movieQueue, movieFile);
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