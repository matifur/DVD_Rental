#ifndef DVD_RENTAL_RENTALRECORD_H
#define DVD_RENTAL_RENTALRECORD_H

#include <iostream>
#include <string>
#include <utility>
#include "Movie.h"
using namespace std;

class RentalRecord : public Movie{
private:
    string fname;
    string fsurname;
    string fphone;
public:
    RentalRecord(const string &t, const string &d, int y, bool a, const string &name = "empty", const string &surname = "empty",
                 const string &phone = "empty")
            : Movie(t, d, y, a), fname{name}, fsurname{surname}, fphone{phone} {}

    string get_name() const {return fname;}
    string get_surname() const {return fsurname;}
    string get_phone() const {return fphone;}

    void set_name(string name){ fname = name;}
    void set_surname(string surname){ fsurname = surname;}
    void set_phone(string phone){ fphone = phone;}


    void display_admin() const {
        cout << get_title() << ", " << get_director() << ", " << get_year() << "\n\t^^ Pozyczony przez: " << fname
             << " " << fsurname << " tel: " << fphone << endl;
    }
    void display_not_available() const {
        if(!get_access())
            cout << get_title() << ", " << get_director() << ", " << get_year() << "\n\t^^ Pozyczony przez: " << fname
                 << " " << fsurname << " tel: " << fphone << endl;
        else
            return;
    }
    void display_available() const {
        if(get_access())
            cout << get_title() << ", " << get_director() << ", " << get_year() << endl;
        else
            return;
    }

};



#endif //DVD_RENTAL_RENTALRECORD_H
