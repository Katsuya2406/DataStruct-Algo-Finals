#ifndef MRENTAL_H
#define MRENTAL_H
#include <string>

using namespace std;
class Movie{
	private:
		string title;
		string genre;
		string rate;
		int year;
		
	public:
		Movie();
		Movie(string t, string g, string r, int yr);
		
		void setTitle(string t);
		void setGenre(string g);
		void setRating(string r)l
		void setYear(int yr);
		
		void addTitle (const string& )
};
