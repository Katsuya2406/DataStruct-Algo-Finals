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
    	
    	switch
	}
    return 0;
}
