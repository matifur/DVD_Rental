#ifndef DVD_RENTAL_CLIENT_RUNNING_H
#define DVD_RENTAL_CLIENT_RUNNING_H

#include <iostream>
#include "Movie.h"
#include "DVD_Database.h"
#include "StringValidation.h"


//Funkcja działa jako menu klienta
//Daje mu podstawowe opcje wyporzyczania i oddawania filmów
void client_running(const string& name, const string& surname, const string& phone) {
    DVD_Database database;
    bool running = true;
    string title_return;
    string title_borrow;

    while (running) {
        cout << "Menu:" << endl;
        cout << "1. Wyswietl dostepne filmy do wypozyczenia" << endl;
        cout << "2. Wyporzycz film" << endl;
        cout << "3. Oddaj film" << endl;
        cout << "4. Wyjdz" << endl;
        cout << "Wybierz opcje: ";

        int choice;
        cin >> choice;
        system("CLS");
        try {
            switch (choice) {
                case 1:
                    cout << "Dostępne filmy: \n" << endl;
                    database.displayAviableMovies();
                    break;
                case 2:
                    cout << "Dostępne filmy: \n" << endl;
                    database.displayAviableMovies();
                    cout << "\n" << endl;

                    cout << "Podaj tytul filmu do wyporzyczenia: ";
                    cin.ignore();
                    getline(cin, title_borrow);
                    if (title_borrow == "exit")
                        return;
                    if (!isValidString(title_borrow)) {
                        throw "Niepoprawny format wpisanych danych sprobuj ponownie\n";
                        break;
                    }
                    database.BorrowMovie(title_borrow, name, surname, phone);
                    break;
                case 3:
                    cout << "Podaj tytul filmu do oddania: ";
                    cin >> title_return;
                    if (title_return == "exit")
                        return;
                    if (!isValidString(title_return)) {
                        throw "Niepoprawny format wpisanych danych sprobuj ponownie";
                        break;
                    }
                    database.ReturnMovie(title_return);
                    break;
                case 4:
                    return;

                default:
                    cout << "Nieprawidłowa opcja. Wybierz ponownie.\n" << endl;
            }
        }
        catch (const char* er) {
            cerr << "ERROR: " << er << "\n" << endl;
        }
    }
}



#endif //DVD_RENTAL_CLIENT_RUNNING_H
