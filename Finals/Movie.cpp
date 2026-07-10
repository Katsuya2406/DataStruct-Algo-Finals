#include "Movie.h"
#include <string>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

void loadQueueFromFile(queue<string>& movieQueue, const string& filename){
	ifstream infile(filename.c_str());
if (infile.is_open()) {
string movie;
while (getline(infile, movie)) {
movieQueue.push(movie);
}
infile.close();
}
}

void saveQueueToFile(const queue<string>& movieQueue, const string& filename){
ofstream outfile(filename.c_str());
if (outfile.is_open()) {
queue<string> tempQueue = movieQueue; 
// Create a temporary vcopy to iterate
while (!tempQueue.empty()) {
outfile << tempQueue.front() << endl;
tempQueue.pop();
}
outfile.close();
}
}



void addMovie(queue<string>& movieQueue){
	string movie;
	
	cout << "Add the title pf your movie: ";
	getline(cin, movie);
	
	movieQueue.push(movie); 
	cout << "Your movie titled " << movie << " has beed added!" << endl;
	
}

void playMovie(queue<string>& movieQueue){
	if (!movieQueue.empty()){
		cout<<"Playing movie: " << movieQueue.front() << endl;
		movieQueue.pop();	
	}
	else 
	{
		cout << "The list of Movies is empty." << endl;
	}
}

void viewNextMovie(const queue<string>& movieQueue){
	if (!movieQueue.empty()){
		cout<<"Next movie: " << movieQueue.front() << endl;
			
	}
	else 
	{
		cout << "The list of Movies is empty." << endl;
	}
}

void checkIfEmpty(const queue<string>& movieQueue){
	if (!movieQueue.empty()){
		cout<<" The list is not empty."<< endl;
			
	}
	else 
	{
		cout << "The list of Movies is empty." << endl;
	}
}

void displayMenu(){
	cout << endl;
	cout << "--Movie Rental System--" << endl;
	cout << "1. Add a movie" << endl;
	cout << "2. Play a movie" << endl;
	cout << "3. View the next movie" << endl;
	cout << "4. Search for a movie" << endl;
	cout << "5. Check if the list is empty" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your choice: ";
}


void searchMovie()
{
    ifstream infile("movieQueue.txt");

    if (!infile)
    {
        cout << "Error: Could not open movieQueue.txt." << endl;
        return;
    }

    string searchText;
    string movie;
    bool found = false;

    cout << "Enter the movie title to search: ";
    getline(cin, searchText);

    while (getline(infile, movie))
    {
        if (movie == searchText)
        {
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