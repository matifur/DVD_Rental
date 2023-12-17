#include <iostream>
#include "admin_running.h"
#include "client_running.h"
#include "StringValidation.h"


int main() {
    while(true) {
        int choice;
        string imie, nazwisko, telefon;
        cout << "Prosze wybrac uzytkownika: " << endl;
        cout << "1. ADMIN " << endl;
        cout << "2. GOSC " << endl;
        cout << "3. Wyjscie" << endl;
        cin >> choice;
        system("cls");
        try {
            switch (choice) {
                case 1:
                    admin_running();
                    break;
                case 2:
                    cout << "Podaj imie: ";
                    cin.ignore();
                    getline(cin, imie);
                    if(imie == "exit"){return 0;}

                    cout << "Podaj nazwisko: ";
                    getline(cin, nazwisko);
                    if(nazwisko == "exit"){return 0;}

                    cout << "Podaj numer telefonu: ";
                    getline(cin, telefon);
                    if(telefon == "exit"){return 0;}

                    if (!isValidString(imie) or !isValidString(nazwisko) or !isValidString(telefon)) {
                        cerr << "ERROR: Nieproprawny format wpisanych danych, prosze sprobowac ponownie" << endl;
                        break;
                    }
                    client_running(imie, nazwisko, telefon);
                    break;
                case 3:
                    return 0;
                default:
                    system("cls");
                    cout << "ERROR: Blad podczas wyboru opcji, prosze wybrac ponownie.\n" << endl;
                    break;
            }
        }
        catch (const char* er){
            cerr << "ERROR: " << er << endl;
        }
    }

    return 0;
}
