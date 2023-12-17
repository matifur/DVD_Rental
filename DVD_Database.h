#ifndef DVD_RENTAL_DVD_DATABASE_H
#define DVD_RENTAL_DVD_DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movie.h"
using namespace std;

class DVD_Database {
private:
    vector<Movie> films;

public:
    DVD_Database(){
        loadFromFile();
    }

    void addMovie(const Movie& film) {
        films.push_back(film);
        saveToFile();
    }

    void removeMovie(const string& title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title()== title ) {
                films.erase(it);
                break;
            }
        }
    }

    void setMovieAvailable(const string& title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == title ) {
                it -> set_access(true);
                break;
            }
        }
        saveToFile();
    }
    void setMovieNotAvailable(const string& title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == title ) {
                it ->set_access(false);
                break;
            }
        }
        saveToFile();
    }

    void displayAllMovies() {
        loadFromFile();
        cout << "Dane w formacie Tytul, Rezyser, Rok produkcji: \n" << endl;
        for (const Movie& film : films) {
            film.display_admin();
        }
    }

    void displayAviableMovies() {
        loadFromFile();
        cout << " --------------- DOSTEPNE FILMY -------------- " << endl;
        cout << "Dane w formacie Tytul, Rezyser, Rok produkcji: \n" << endl;
        for (const Movie& film : films) {
            film.display_available();
        }
    }

    void displayNotAviableMovies() {
        loadFromFile();
        cout << "-------------- NIE DOSTEPNE FILMY ------------" << endl;
        cout << "Dane w formacie Tytul, Rezyser, Rok produkcji: \n" << endl;
        for (const Movie& film : films) {
            film.display_not_available();
        }
    }

    bool saveToFile() const {
        ofstream file("Movies_database.txt");
        if (!file) {
            cerr << "Nie można otworzyć pliku do zapisu." << endl;
            return false;
        }

        for (const Movie& film : films) {
            file << film.get_title() << ',' << film.get_director() << ',' << film.get_year() << "," << film.get_access() << '\n';
        }

        file.close();
        return true;
    }

    bool loadFromFile() {
        ifstream file("Movies_database.txt");
        if (!file) {
            cerr << "Nie można otworzyć pliku do odczytu." << endl;
            return false;
        }

        films.clear();

        string line;
        while (getline(file, line)) {
            string title, director;
            int year;
            double rating;
            bool access;

            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, director, ',');
            ss >> year;
            ss.ignore();
            ss >> access;

            Movie film(title, director, year,access);
            films.push_back(film);
        }

        file.close();
        return true;
    }
};


#endif //DVD_RENTAL_DVD_DATABASE_H
