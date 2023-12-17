#include <iostream>
#include "admin_running.h"
#include "client_running.h"
using namespace std;

int main() {
    while(true) {
        int choice;
        string imie, nazwisko, telefon;
        cout << "Prosze wybrac uzytkownika: " << endl;
        cout << "1. ADMIN " << endl;
        cout << "2. GOSC " << endl;
        cout << "3. Wyjscie" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                admin_running();
                break;
            case 2:
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;
                cout << "Podaj numer telefonu: ";
                cin >> telefon;
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

    return 0;
}
