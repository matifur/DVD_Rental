#ifndef DVD_RENTAL_ADMIN_RUNNING_H
#define DVD_RENTAL_ADMIN_RUNNING_H

#include <iostream>
#include "Movie.h"
#include "DVD_Database.h"
#include "StringValidation.h"
#include <exception>


//Funkcja działa jako menu klienta
//Pozwala ona adminowi na zdecydowanie większą swobodę nież klientowi.
//Może on dodawać, usuwać, wyświetlać w różnych konfiguracjach filmy oraz ich dostępność.
//Może on równierz sprawdzić kto wyporżyczył dany film
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
        cout << "6. Oddaj film klienta" << endl;
        cout << "7. Wyjdz" << endl;
        cout << "Wybierz opcje: ";


        cin >> choice;
        system("CLS");
        try {
            switch (choice) {
                case 1: {
                    string title, director;
                    int year;
                    cout << "Podaj tytul: ";
                    cin.ignore();
                    getline(cin, title);
                    if(title == "exit"){return;}

                    cout << "Podaj rezysera: ";
                    getline(cin, director);
                    if(title == "exit"){return;}

                    cout << "Podaj rok produkcji: ";
                    cin >> year;

                    if (!isValidString(title) or !isValidString(director) or !(year>1888 and year<2050)) {
                        throw "Nieproprawny format wpisanych danych, prosze sprobowac ponownie";
                        break;
                    }
                    RentalRecord film(title, director, year, true);
                    database.addMovie(film);
                    break;
                }
                case 2: {
                    string rm_title;
                    cout << "Podaj tytul filmu do usuniecia: ";
                    cin.ignore();
                    getline(cin, rm_title);
                    if (rm_title == "exit")
                        return;
                    if(!isValidString(rm_title)){
                        throw "Niepoprawny format wpisanych danych sprobuj ponownie";
                        break;
                    }
                    database.removeMovie(rm_title);
                    cout << endl;
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
                    cout << "Podaj tytul filmu: ";
                    cin >> client_title;
                    if (client_title == "exit")
                        return;
                    if(!isValidString(client_title)){
                        throw "Niepoprawny format wpisanych danych sprobuj ponownie";
                        break;
                    }
                    database.ReturnMovie(client_title);
                    break;
                case 7:
                    return;
                default:
                    cout << "Nieprawidlowa opcja. Wybierz ponownie." << endl;
                    break;
            }

        }
        catch (const char* ex){
            cerr << "ERROR: " << ex << "\n" << endl;
        }
    }
}

#endif //DVD_RENTAL_ADMIN_RUNNING_H
