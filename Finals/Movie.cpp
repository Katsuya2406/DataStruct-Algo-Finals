#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

//default constructor's value
Movie::Movie() {
    movieTitle = "";
    movieYear = 0;
    moviePublisher = "";
    next = nullptr;
}

//parameterized constructor implements variables to be given input by user for later features
Movie::Movie(string title, int year, string publisher) {
    movieTitle = title;
    movieYear = year;
    moviePublisher = publisher;
    next = nullptr;
}

//setters implements modification of private data members
void Movie::setMovieTitle(string title) { movieTitle = title; }
void Movie::setMovieYear(int year) { movieYear = year; }
void Movie::setMoviePublisher(string publisher) { moviePublisher = publisher; }
void Movie::setNext(Movie* n) { next = n; }

//getters implements access of private data members without modification
string Movie::getMovieTitle() const { return movieTitle; }
int Movie::getMovieYear() const { return movieYear; }
string Movie::getMoviePublisher() const { return moviePublisher; }
Movie* Movie::getNext() const { return next; }


//queue functions.
//loads the customer queue from a text file.
void loadQueueFromFile(queue<string>& customerQueue, const string& filename) {
    ifstream infile(filename.c_str());

    if (infile.is_open()) {
        string record;
        while (getline(infile, record)) {
            customerQueue.push(record);
        }

        infile.close();
    }
}

//linked list functions.
//saves the customer queue to a text file.
void saveQueueToFile(const queue<string>& customerQueue, const string& filename) {
    ofstream outfile(filename.c_str());

    if (outfile.is_open()) {
        queue<string> tempQueue = customerQueue;
        while (!tempQueue.empty()) {
            outfile << tempQueue.front() << endl;
            tempQueue.pop();
        }

        outfile.close();
    }
}


//loads the movie linked list from a text file.
void loadMoviesFromFile(Movie*& head, const string& filename) {
    ifstream infile(filename.c_str());

    if (!infile.is_open()) {
        return;
    }

    string line;

    //reads each movie from the file.
    while (getline(infile, line)) {
        stringstream ss(line);

        string title;
        string yearString;
        string publisher;

        //separates the title, year, and publisher using '-'.
        getline(ss, title, '-');
        getline(ss, yearString, '-');
        getline(ss, publisher);

        //converts the year from a string to an integer.
        int year;
        stringstream convert(yearString);
        convert >> year;

        //creates a new movie node.
        Movie* newMovie = new Movie(title, year, publisher);

        //checks if the linked list is empty.
        if (head == nullptr) {
            head = newMovie;
        }
        else {
            // Traverses the linked list until the last node is reached.
            Movie* current = head;

            while (current->getNext() != nullptr) {
                current = current->getNext();
            }

            //connects the new movie to the end of the linked list.
            current->setNext(newMovie);
        }
    }

    infile.close();
}

//saves the movie linked list to a text file.
void saveMoviesToFile(Movie* head, const string& filename) {
    ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        return;
    }

    // Traverses the linked list and saves each movie to the file.
    Movie* current = head;

    while (current != nullptr) {
        outfile << current->getMovieTitle() << "-" << current->getMovieYear() << "-" << current->getMoviePublisher() << endl;
        current = current->getNext();
    }

    outfile.close();
}

//main functions
//adds movie to the linked list, has authorization code for the "admin" of movie rental system.
//uses pointers for the linked list
void addMovie(Movie*& head) {
    string code;
    string title;
    int year;
    string publisher;

    cout << "Enter Authorization Code: ";
    getline(cin, code);

    if (code != "RX93V") {
        cout << "Wrong Code!" << endl;
        return;
    }

	//user needs to input movie title to add in the linked list.
    cout << "Enter movie title: ";
    getline(cin, title);

	//checks if empty.
    if (title.empty()) {
        cout << "Movie title cannot be empty." << endl;
        return;
    }

    cout << "Enter movie year: ";
    cin >> year;
    cin.ignore();

    cout << "Enter movie publisher: ";
    getline(cin, publisher);

    //new movie node.
    Movie* newMovie = new Movie(title, year, publisher);

    //if the linked list is empty, make the new movie the head.
    if (head == nullptr) {
        head = newMovie;
    }
    else {
        // Traverse to the end of the linked list.
        Movie* current = head;

        while (current->getNext() != nullptr) {
            current = current->getNext();
        }

        //link the new movie to the end of the list.
        current->setNext(newMovie);
    }

    //saves the updated linked list to the file.
    saveMoviesToFile(head, "movieList.txt");
    cout << endl;
    cout << "Movie added successfully!" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Publisher: " << publisher << endl;
}

//displays all the movies stored in the linked list.
void displayMovies(Movie* head) {
    //checks if the linked list is empty.
    if (head == nullptr) {
        cout << "There are no movies in the list." << endl;
        return;
    }

    //creates a pointer that will be used to traverse the linked list.
    Movie* current = head;
    
    cout << "\n===== Movie List =====" << endl;

    //traverses the linked list and displays the information of each movie.
    while (current != nullptr) {
        cout << "Title: " << current->getMovieTitle() << endl;
        cout << "Year: " << current->getMovieYear() << endl;
        cout << "Publisher: " << current->getMoviePublisher() << endl;
        cout << endl;

        //moves the pointer to the next movie in the linked list.
        current = current->getNext();
    }
}

//searches for a specific movie in the linked list.
void searchMovie(Movie* head) {
    //checks if the linked list is empty.
    if (head == nullptr) {
        cout << "There are no movies in the list." << endl;
        return;
    }

    string title;
    bool found = false;

    //the user needs to enter a movie title to search.
    cout << "Enter the movie title to search: ";
    getline(cin, title);

    //creates a pointer that will be used to traverse the linked list.
    Movie* current = head;

    //traverses the linked list to compare each movie title with the user's input.
    while (current != nullptr) {
        //checks if the current movie matches the entered title.
        if (current->getMovieTitle() == title) {
            cout << "\nMovie found!" << endl;
            cout << "Title: " << current->getMovieTitle() << endl;
            cout << "Year: " << current->getMovieYear() << endl;
            cout << "Publisher: " << current->getMoviePublisher() << endl;

            found = true;
            break;
        }

        //moves the pointer to the next movie in the linked list.
        current = current->getNext();
    }

    //displays a message if the movie was not found.
    if (!found) {
        cout << "Movie not found." << endl;
    }
}

//checks if the movie linked list is empty.
void checkIfEmpty(Movie* head) {
    //checks if the head pointer is not pointing to any movie node.
    if (head == nullptr) {
        cout << "The movie list is empty." << endl;
    }
    else {
        cout << "The movie list contains movies." << endl;
    }
}

//deletes a movie from the linked list.
void deleteMovie(Movie*& head) {
    //checks if the linked list is empty.
    if (head == nullptr) {
        cout << "The movie list is empty." << endl;
        return;
    }

    string title;

    //user needs to enter the title of the movie to delete.
    cout << "Enter the movie title to delete: ";
    getline(cin, title);

    Movie* current = head;
    Movie* previous = nullptr;

    //traverses the linked list to find the movie.
    while (current != nullptr && current->getMovieTitle() != title) {
        previous = current;
        current = current->getNext();
    }

    //checks if the movie does not exist in the linked list.
    if (current == nullptr) {
        cout << "Movie not found." << endl;
        return;
    }

    //checks if the movie to delete is the first node.
    if (previous == nullptr) {
        head = current->getNext();
    }
    else {
        //connects the previous node to the next node.
        previous->setNext(current->getNext());
    }

    //deletes the selected movie node from memory.
    delete current;

    //saves the updated linked list to the file.
    saveMoviesToFile(head, "movieList.txt");

    cout << "Movie deleted successfully!" << endl;
}

//rents a movie from the linked list.
void rentMovie(Movie*& head, queue<string>& customerQueue) {
    //checks if the linked list is empty.
    if (head == nullptr) {
        cout << "The movie list is empty." << endl;
        return;
    }

    string customerName;
    string title;

    //user needs to enter the customer's name.
    cout << "Enter customer name: ";
    getline(cin, customerName);

    //user needs to enter the movie title to rent.
    cout << "Enter movie title: ";
    getline(cin, title);

    Movie* current = head;
    Movie* previous = nullptr;

    //traverses the linked list to find the movie.
    while (current != nullptr && current->getMovieTitle() != title) {
        previous = current;
        current = current->getNext();
    }

    //checks if the movie exists in the linked list.
    if (current == nullptr) {
        cout << "Movie not found." << endl;
        return;
    }

    //converts the movie year from an integer to a string.
    stringstream ss;
    ss << current->getMovieYear();

    //stores the rental record in the customer queue.
    customerQueue.push(customerName + " rented " + current->getMovieTitle() + "-" + ss.str() + "-" + current->getMoviePublisher());

    //removes the movie from the linked list.
    if (previous == nullptr) {
        head = current->getNext();
    }
    else {
        previous->setNext(current->getNext());
    }

    //deletes the rented movie node from memory.
    delete current;

    //saves the updated movie linked list.
    saveMoviesToFile(head, "movieList.txt");

    //saves the updated customer queue.
    saveQueueToFile(customerQueue, "customerQueue.txt");

    //displays a confirmation message.
    cout << "Movie rented successfully!" << endl;
}

// Returns a movie to the linked list.
void returnMovie(Movie*& head, queue<string>& customerQueue)
{
    //checks if the customer queue is empty.
    if (customerQueue.empty())
    {
        cout << "There are no rented movies to return." << endl;
        return;
    }

    //gets the rental record at the front of the queue.
    string record = customerQueue.front();

    //removes the rental record from the customer queue.
    customerQueue.pop();

    //separates the customer name from the movie information.
    int position = record.find(" rented ");

    string customerName = record.substr(0, position);
    string movieInfo = record.substr(position + 8);
    
    if (customerName.empty() || movieInfo.empty()) {
    cout << "Error: Invalid customer name in list or movie details in queue." << endl;
    return;
    }

    // Uses a stringstream to separate the movie information.
    stringstream ss(movieInfo);

    string title;
    string yearString;
    string publisher;

    getline(ss, title, '-');
    getline(ss, yearString, '-');
    getline(ss, publisher);

    // Converts the movie year from a string to an integer.
    int year;
    stringstream convert(yearString);
    convert >> year;

    //creates a new movie node.
    Movie* newMovie = new Movie(title, year, publisher);

    //checks if the linked list is empty.
    if (head == nullptr) {
        //makes the returned movie the first node.
        head = newMovie;
    }
    else {
        // Traverses the linked list until the last node is reached.
        Movie* current = head;

        while (current->getNext() != nullptr) {
            current = current->getNext();
        }

        // Adds the returned movie to the end of the linked list.
        current->setNext(newMovie);
    }

    //saves the updated movie linked list.
    saveMoviesToFile(head, "movieList.txt");

    //saves the updated customer queue.
    saveQueueToFile(customerQueue, "customerQueue.txt");

    //displays a confirmation message.
    cout << customerName << " successfully returned "
         << title << "." << endl;
}

//displays the head/next movie on the list.
void viewNextMovie(Movie* head) {
    if (head == nullptr) {
        cout << "The movie list is empty. No upcoming movies." << endl;
        return;
    }
    cout << "\n===== Next Movie in Queue =====" << endl;
    cout << "Title: " << head->getMovieTitle() << endl;
    cout << "Year: " << head->getMovieYear() << endl;
    cout << "Publisher: " << head->getMoviePublisher() << endl;
}

//displays the queue of customers.
void displayCustomerQueue(const queue<string>& customerQueue) {
    if (customerQueue.empty()) {
    cout << "No customers in the rental queue." << endl;
	return;
}
	queue<string> tempQueue = customerQueue;
	
    cout << "\n===== Customer Rental Queue =====" << endl;
    int position = 1;
    while (!tempQueue.empty()) {
    cout << position << ". " << tempQueue.front() << endl;
    tempQueue.pop();
    position++;
}
}

//displays main menu of the rental system.
void displayMenu() {
    cout << "\n--- Movie Rental System Menu ---" << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Delete Movie" << endl;
    cout << "3. Rent Movie" << endl;
    cout << "4. Return Movie" << endl;
    cout << "5. View Next Movie" << endl;
    cout << "6. Search Movie" << endl;
    cout << "7. Display Customer Queue" << endl;
    cout << "8. Display Movies" << endl;
    cout << "9. Check if Empty" << endl;
    cout << "10. Save and Exit" << endl;
    cout << "Enter your choice: ";
}
