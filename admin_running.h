#ifndef DVD_RENTAL_ADMIN_RUNNING_H
#define DVD_RENTAL_ADMIN_RUNNING_H

#include <iostream>
#include "Movie.h"
#include "DVD_Database.h"
using namespace std;

void admin_running() {
    DVD_Database database;
    bool running = true;
    int choice;
    string client_title;
    while (running) {
        cout << "Menu:" << endl;
        cout << "1. Dodaj film" << endl;
        cout << "2. Usun film" << endl;
        cout << "3. Wyswietl wszystkie filmy" << endl;
        cout << "4. Wyswietl dostepne filmy" << endl;
        cout << "5. Wyswietl niedostepne filmy" << endl;
        cout << "6. Oddaj film" << endl;
        cout << "7. Wyjdz" << endl;
        cout << "Wybierz opcje: ";

        cin >> choice;
        system("CLS");

        switch (choice) {
            case 1: {
                string title, director;
                int year;
                double rating;

                cout << "Podaj tytul: ";
                cin.ignore();
                getline(cin, title);
                if(title == "exit")
                    return;
                cout << "Podaj rezysera: ";
                getline(cin, director);
                cout << "Podaj rok produkcji: ";
                cin >> year;


                RentalRecord film(title, director, year, true);
                database.addMovie(film);
                cout << "Film został dodany do bazy danych.\n" << endl;
                break;
            }
            case 2: {
                string title;
                cout << "Podaj tytul filmu do usunięcia: ";
                cin >> title;
                if(title == "exit")
                    return;
                database.removeMovie(title);
                cout << "Film zostal usunięty z bazy danych.\n" << endl;
                break;
            }
            case 3:
                cout << "Baza danych filmów na DVD:\n" << endl;
                database.displayAllMovies();
                break;
            case 4:
                cout << "Dostępne filmy: \n" << endl;
                database.displayAviableMovies();
                break;
            case 5:
                cout << "Niedostepne filmy: \n" << endl;
                database.displayNotAviableMovies();
                break;
            case 6:
                cout << "Podaj tytuł filmu: ";
                cin >> client_title;
                database.ReturnMovie(client_title);
                break;
            case 7:
                return;
            default:
                cout << "Nieprawidłowa opcja. Wybierz ponownie." << endl;
        }
    }
}

#endif //DVD_RENTAL_ADMIN_RUNNING_H
