#ifndef DVD_RENTAL_DVD_DATABASE_H
#define DVD_RENTAL_DVD_DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "RentalRecord.h"

//Klasa zajmuje się zapisywaniem odczytywaniem i zarządzaniem danymi używanymi przez program.
class DVD_Database {
private:
    vector<RentalRecord> films;

public:
    DVD_Database(){
        loadFromFile();
    }

    //Sortuje elementy wektora alfabetycznie według tytułu
    void sortRentalRecordsByTitle(vector<RentalRecord>& records) {
        sort(records.begin(), records.end(),
             [](const RentalRecord& a, const RentalRecord& b) {
                 return a.get_title() < b.get_title();
             }
        );
    }

    //Pozwala na dodanie filmu do naszej bazy danych
    void addMovie(const RentalRecord& film) {
        films.push_back(film);
        cout << " >> Film zostal poprawnie dodany do bazy danych." << endl;
        saveToFile();
    }

    //Usuwa wybrany film z bazy danych
    void removeMovie(const string& title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title()== title ) {
                films.erase(it);
                cout << " >> Film zostal usuniety z bazy danych.\n" << endl;
                saveToFile();
                return;
            }
        }
        cout << "ERROR: Nie znaleziono filmu\n" << endl;
        return;
    }

    //Funkcja przeszukuje bazę danych w poszukiwaniu podanego tytułu
    void search_title(const string& title_search){
        loadFromFile();
        bool found_title = false;
        cout << "Wyniki wyszukiwania: \n" << endl;
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == title_search) {
                it -> display_admin();
                found_title = true;
            }
        }
        if(!found_title) {
            cout << "ERROR: Nie znaleziono filmu\n" << endl;
            return;
        }
        return;
    }

    //Funkcja szuka w bazie danych czy podana osoba wyporzyczyła jakiś film
    void search_client(const string& name_search, const string& surname_search) {
        loadFromFile();
        bool found_person = false;
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_name() == name_search) {
                if (it->get_surname() == surname_search) {
                    it->display_admin();
                    found_person = true;
                }
            }
        }
        if (!found_person) {
            cout << "ERROR: Nie znaleziono osoby\n" << endl;
            return;
        }
        return;
    }

    //Zmienia status filmu z wyporzyczony na dostępny
    void ReturnMovie(const string& ret_title) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == ret_title ) {
                it -> set_title(ret_title);
                it -> set_access(true);
                it -> set_name("empty");
                it -> set_surname("empty");
                it -> set_phone("empty");
                cout << " >> Film zostal poprawnie zwrocony.\n" << endl;
                saveToFile();
                return;
            }
        }
        cout << "ERROR: Nie znaleziono filmu.\n" << endl;
        return;
    }

    //Zmienia status filmu z dostępny na wyporzyczony
    void BorrowMovie(const string& borr_title, const string& name, const string& surname, const string& phone) {
        loadFromFile();
        for (auto it = films.begin(); it != films.end(); ++it) {
            if (it->get_title() == borr_title ) {
                it -> set_title(borr_title);
                it -> set_access(false);
                it -> set_name(name);
                it -> set_surname(surname);
                it -> set_phone(phone);
                cout << " >> Film zostal poprawnie wyporzyczony.\n" << endl;
                saveToFile();
                return;
            }
        }
        cout << "ERROR: Nie znaleziono filmu.\n" << endl;
        return;
    }

    //Wyświetla wszystkie filmy z osobami które go wyporzyczyły
    void displayAllMovies() {
        loadFromFile();
        sortRentalRecordsByTitle(films);
        cout << " --------------- WSZYSTKIE FILMY -------------- \n" << endl;
        for (const RentalRecord& film : films) {
            film.display_admin();
        }
        cout << endl;
    }

    //Wyświetla wszystkie dostępne do wyporzyczenia filmy
    void displayAviableMovies() {
        loadFromFile();
        sortRentalRecordsByTitle(films);
        cout << " --------------- DOSTEPNE FILMY -------------- " << endl;
        cout << "Dane w formacie Tytul, Rezyser, Rok produkcji: \n" << endl;
        for (const RentalRecord& film : films) {
            film.display_available();
        }
        cout << endl;
    }

    //Wyświetla wszystkie wyporzyczone filmy
    void displayNotAviableMovies() {
        loadFromFile();
        sortRentalRecordsByTitle(films);
        cout << "-------------- NIEDOSTEPNE FILMY ------------" << endl;
        for (const RentalRecord& film : films) {
            film.display_not_available();
        }
    }

    //Dokonuje zapisu do bazy danych plików w odpowiednim formacie
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

    //Wczytuje wszystkie filmy z bazy danych do wektora klasy
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
