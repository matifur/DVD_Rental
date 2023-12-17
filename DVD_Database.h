#ifndef DVD_RENTAL_DVD_DATABASE_H
#define DVD_RENTAL_DVD_DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movie.h"
#include "RentalRecord.h"


class DVD_Database {
private:
    vector<RentalRecord> films;

public:
    DVD_Database(){
        loadFromFile();
    }

    void addMovie(const RentalRecord& film) {
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

    void ReturnMovie(const string& ret_title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == ret_title ) {
                it -> set_title(ret_title);
                it -> set_access(true);
                it -> set_name("empty");
                it -> set_surname("empty");
                it -> set_phone("empty");
                break;
            }
        }
        saveToFile();
    }
    void BorrowMovie(const string& borr_title, const string& name, const string& surname, const string& phone) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == borr_title ) {
                it -> set_title(borr_title);
                it -> set_access(false);
                it -> set_name(name);
                it -> set_surname(surname);
                it -> set_phone(phone);
                break;
            }
        }
        saveToFile();
    }

    void displayAllMovies() {
        loadFromFile();
        cout << " --------------- WSZYSTKIE FILMY -------------- \n" << endl;
        for (const RentalRecord& film : films) {
            film.display_admin();
        }
        cout << endl;
    }

    void displayAviableMovies() {
        loadFromFile();
        cout << " --------------- DOSTEPNE FILMY -------------- " << endl;
        cout << "Dane w formacie Tytul, Rezyser, Rok produkcji: \n" << endl;
        for (const RentalRecord& film : films) {
            film.display_available();
        }
        cout << endl;
    }

    void displayNotAviableMovies() {
        loadFromFile();
        cout << "-------------- NIE DOSTEPNE FILMY ------------" << endl;
        for (const RentalRecord& film : films) {
            film.display_not_available();
        }
    }

    bool saveToFile() const {
        ofstream file("Movies_database.txt");
        if (!file) {
            cerr << "Nie można otworzyć pliku do zapisu." << endl;
            return false;
        }

        for (const RentalRecord& film : films) {
            file << film.get_title() << ',' << film.get_director() << ',' << film.get_year() << "," << film.get_access()
                << ","<< film.get_name() << "," << film.get_surname() << "," << film.get_phone() << '\n';
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
            bool access;
            string name, surname, phone;

            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, director, ',');
            ss >> year;
            ss.ignore();
            ss >> access;
            ss.ignore();
            getline(ss, name, ',');
            getline(ss, surname, ',');
            getline(ss, phone, ',');


            RentalRecord film(title, director, year, access, name, surname, phone);
            films.push_back(film);
        }

        file.close();
        return true;
    }
};


#endif //DVD_RENTAL_DVD_DATABASE_H
