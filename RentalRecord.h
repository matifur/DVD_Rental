#ifndef DVD_RENTAL_RENTALRECORD_H
#define DVD_RENTAL_RENTALRECORD_H

#include<string>
#include <utility>
using namespace std;

class RentalRecord {
private:
    string borrower_name;
    string borrower_surname;
    string borrower_phone;
public:
    RentalRecord(const string& name, const string& surname, const string& phone)
            : borrower_name{name}, borrower_surname{surname}, borrower_phone{phone} {}

    string get_name() const {return borrower_name;}
    string get_surname() const {return borrower_surname;}
    string get_phone() const {return borrower_phone;}

    void set_name(string name){borrower_name = name;}
    void set_surname(string surname){borrower_surname = surname;}
    void set_phone(string phone){borrower_phone = phone;}
};



#endif //DVD_RENTAL_RENTALRECORD_H
