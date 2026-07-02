class Movie {
private:
    string title;
    string genre;
    string rating;
    int year;

public:
    Movie();
    Movie(string t, string g, string r, int yr);

    void addMovie(string t, string g, string r, int yr);
    void deleteMovie(string title);
    void searchMovie(string title);
    void saveToFile(string filename);
    void loadFromFile(string filename);
    void displayMenu();
};
