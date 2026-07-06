#include "Movie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main() {    
	queue<string> movieQueue;
    const string filename = "movieQueue.txt";
  
	   loadQueueFromFile(movieQueue, filename);

    int choice;
    
    while (true){
    	displayMenu();
    	
    	cin >>choice;
    	cin.ignore();
    	
    	switch (choice){
    		case 1:
    			addMovie(movieQueue);
    			break;
    			
    		case 2:
    			playMovie(movieQueue);
    			break;
    			
    		case 3:
    			viewNextMovie(movieQueue);
    			break;
    			
    		case 4:
    			checkIfEmpty(movieQueue);
    			break;
    			
    		case 5:
    			saveQueueToFile(movieQueue, filename);
    			cout << "Saving to File, Goodbye!";
    			
    			return 0;
    			
    		default: 
    			cout << "Invalid choice! Please try again." << endl;
    			break;
		}
	}
    return 0;
}