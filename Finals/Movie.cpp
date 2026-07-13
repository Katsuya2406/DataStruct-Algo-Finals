#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;


//Queue Functions
void loadQueueFromFile(queue<string>& q, const string& filename) {
    ifstream infile(filename.c_str());

    if (infile.is_open()) {
        string item;
        while (getline(infile, item)) {
            q.push(item);
        }
        infile.close();
    }
}

void saveQueueToFile(const queue<string>& q, const string& filename) {
    ofstream outfile(filename.c_str());

    if (outfile.is_open()) {
        queue<string> tempQueue = q;

        while (!tempQueue.empty()) {
            outfile << tempQueue.front() << endl;
            tempQueue.pop();
        }

        outfile.close();
    }
}


//Main Functions
void addMovie(queue<string>& movieQueue) {
    string movie;

    cout << "Add the title of your movie: ";
    getline(cin, movie);

    if (movie.empty()) {
        cout << "Movie title cannot be empty." << endl;
        return;
    }

    movieQueue.push(movie);
    saveQueueToFile(movieQueue, "movieQueue.txt");

    cout << "Your movie titled \"" << movie << "\" has been added!" << endl;
}

void rentMovie(queue<string>& movieQueue, queue<string>& customerQueue) {
    string customerName;
    string movieName;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter the movie to rent: ";
    getline(cin, movieName);

    if (customerName.empty() || movieName.empty()) {
        cout << "Customer name and movie title cannot be empty." << endl;
        return;
    }

    queue<string> tempQueue;
    bool found = false;

    while (!movieQueue.empty()) {
        if (movieQueue.front() == movieName && !found) {
            cout << "Movie rented successfully!" << endl;
            cout << "Customer: " << customerName << endl;
            cout << "Movie: " << movieQueue.front() << endl;

            string record = customerName + " rented " + movieQueue.front();
            customerQueue.push(record);

            movieQueue.pop();
            found = true;
        } else {
            tempQueue.push(movieQueue.front());
            movieQueue.pop();
        }
    }

    movieQueue = tempQueue;

    saveQueueToFile(movieQueue, "movieQueue.txt");
    saveQueueToFile(customerQueue, "customerQueue.txt");

    if (!found) {
        cout << "Movie not found." << endl;
    }
}

void viewNextMovie(const queue<string>& movieQueue) {
    if (!movieQueue.empty()) {
        cout << "Next movie: " << movieQueue.front() << endl;
    } else {
        cout << "The list of Movies is empty." << endl;
    }
}

void checkIfEmpty(const queue<string>& movieQueue) {
    if (!movieQueue.empty()) {
        cout << "The list is not empty." << endl;
    } else {
        cout << "The list of Movies is empty." << endl;
    }
}

//Menu

void displayMenu() {
    cout << endl;
    cout << "--Movie Rental System--" << endl;
    cout << "1. Add a movie" << endl;
    cout << "2. Rent a movie" << endl;
	cout << "3. Return a movie" << endl;
    cout << "4. View the next movie" << endl;
    cout << "5. Search for a movie" << endl;
    cout << "6. Display rented customers" << endl;
    cout << "7. Display all movies" << endl;
    cout << "8. Check if the list is empty" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}


//Extra Functions
void searchMovie() {
    ifstream infile("movieQueue.txt");

    if (!infile.is_open()) {
        cout << "Error: Could not open movieQueue.txt." << endl;
        return;
    }

    string searchText;
    string movie;
    bool found = false;

    cout << "Enter the movie title to search: ";
    getline(cin, searchText);

    while (getline(infile, movie)) {
        if (movie == searchText) {
            found = true;
            break;
        }
    }

    infile.close();

    if (found)
        cout << "Movie found!" << endl;
    else
        cout << "Movie not found." << endl;
}

void displayMovie() {
    ifstream infile("movieQueue.txt");
    string movie;

    if (!infile.is_open()) {
        cout << "Error: Could not open movieQueue.txt." << endl;
        return;
    }

    cout << "\n===== Movie Queue =====" << endl;

    while (getline(infile, movie)) {
        cout << movie << endl;
    }

    infile.close();
}

void displayCustomerQueue(const queue<string>& customerQueue) {
    queue<string> tempQueue = customerQueue;

    if (tempQueue.empty()) {
        cout << "No customers have rented movies yet." << endl;
        return;
    }

    cout << "\n===== Customer Rental Queue =====" << endl;

    while (!tempQueue.empty()) {
        cout << tempQueue.front() << endl;
        tempQueue.pop();
    }
}


void returnMovie(queue<string>& movieQueue, queue<string>& customerQueue) {
    string customerName;
    string movieName;

    // Fixed the prompt text to match "returning" instead of "renting"
    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter the movie you are returning: ";
    getline(cin, movieName);

    // Validation check
    if (customerName.empty() || movieName.empty()) {
        cout << "Customer name and movie title cannot be empty." << endl;
        return;
    }

    // 1. Add the movie back to the available movie queue
    movieQueue.push(movieName);

    // 2. Update the customer queue with the return record
    string record = customerName + " returned " + movieName;
    customerQueue.push(record);

    // 3. Save the updated queues back to their respective files
    saveQueueToFile(movieQueue, "movieQueue.txt");
    saveQueueToFile(customerQueue, "customerQueue.txt");

    // Success message
    cout << "\nMovie returned successfully!" << endl;
    cout << "Customer: " << customerName << endl;
    cout << "Movie: " << movieName << endl;
}