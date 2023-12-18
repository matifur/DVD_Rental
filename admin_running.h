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
    string client_title, category, name_search, surname_search, title_search;
    while (running) {
        cout << "Menu:" << endl;
        cout << "1. Dodaj film" << endl;
        cout << "2. Usun film" << endl;
        cout << "3. Wyswietl wszystkie filmy" << endl;
        cout << "4. Wyswietl dostepne filmy" << endl;
        cout << "5. Wyswietl niedostepne filmy" << endl;
        cout << "6. Oddaj film klienta" << endl;
        cout << "7. SZUKAJ" << endl;
        cout << "8. Wyjdz" << endl;
        cout << "Wybierz opcje: ";


        cin >> choice;
        system("cls||clear");
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
                    cin.ignore();
                    getline(cin, client_title);
                    if (client_title == "exit")
                        return;
                    if(!isValidString(client_title)){
                        throw "Niepoprawny format wpisanych danych sprobuj ponownie";
                        break;
                    }
                    database.ReturnMovie(client_title);
                    break;

                case 7:
                    system("cls");
                    cout << " --------------- WYSZUKIWARKA -------------- " << endl;
                    cout << "Czego szukasz: " << endl;
                    cout << " > klient " << endl;
                    cout << " > film " << endl;
                    cout << "Wybierz opcje: ";
                    cin.ignore();
                    getline(cin, category);
                    if (category == "exit")
                        return;

                    if(category == "klient") {
                        cout << "Imie: ";
                        getline(cin, name_search);
                        cout << "Nazwisko: ";
                        getline(cin, surname_search);
                        if (name_search == "exit" or surname_search == "exit")
                            return;
                        if (!isValidString(category) or !isValidString(name_search) or !isValidString(surname_search)) {
                            throw "Niepoprawny format wpisanych danych sprobuj ponownie.";
                            break;
                        }
                        database.search_client(name_search, surname_search);
                    }
                    else if(category == "film") {
                        cout << "Tytul: ";
                        getline(cin, title_search);
                        if (name_search == "exit")
                            return;
                        if (!isValidString(category) or !isValidString(name_search)) {
                            throw "Niepoprawny format wpisanych danych sprobuj ponownie.";
                            break;
                        }
                        database.search_title(title_search);
                    }
                    else{
                        throw "Nieznany typ wyszukiwania. Sprobuj ponownie";
                        break;
                    }
                    break;

                case 8:
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
