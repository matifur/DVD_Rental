#ifndef DVD_RENTAL_CLIENT_RUNNING_H
#define DVD_RENTAL_CLIENT_RUNNING_H

#include <iostream>
#include "Movie.h"
#include "DVD_Database.h"
using namespace std;

void client_running(const string& name, const string& surname, const string& phone) {
    DVD_Database database;
    bool running = true;
    string title_return;
    string title_borrow;

    while (running) {
        cout << "Menu:" << endl;
        cout << "1. Wyswietl dostępne filmy do wypozyczenia" << endl;
        cout << "2. Wyporzycz film" << endl;
        cout << "3. Oddaj film" << endl;
        cout << "4. Wyjdz" << endl;
        cout << "Wybierz opcje: ";

        int choice;
        cin >> choice;
        system("CLS");

        switch (choice) {
            case 1:
                cout << "Dostępne filmy: \n" << endl;
                database.displayAviableMovies();
                break;
            case 2:
                cout << "Dostępne filmy: \n" << endl;
                database.displayAviableMovies();
                cout << "Podaj tytul filmu do wyporzyczenia: ";
                cin.ignore();
                getline(cin, title_borrow);
                if(title_borrow == "exit")
                    return;
                database.BorrowMovie(title_borrow, name, surname, phone);
                cout << "Film zostal wyporzyczony.\n" << endl;
                break;
            case 3:
                cout << "Podaj tytul filmu do oddania: ";
                cin >> title_return;
                if(title_return == "exit")
                    return;
                database.ReturnMovie(title_return);
                cout << "Film oddany.\n" << endl;
                break;
            case 4:
                running = false;
                break;

            default:
                cout << "EROR: Nieprawidłowa opcja. Wybierz ponownie." << endl;
        }
    }
}



#endif //DVD_RENTAL_CLIENT_RUNNING_H
