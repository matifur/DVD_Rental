#ifndef DVD_RENTAL_STRINGVALIDATION_H
#define DVD_RENTAL_STRINGVALIDATION_H

#include <string>

//Funkcja sprawdza czy znaki w zmiennych string należą do zbioru: litery, cyfry, znak '_'
bool isValidString(const std::string& str) {
    for (char c: str) {
        if (!std::isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

#endif //DVD_RENTAL_STRINGVALIDATION_H
