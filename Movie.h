#ifndef DVD_RENTAL_MOVIE_H
#define DVD_RENTAL_MOVIE_H

#include <string>
#include <iostream>
using namespace std;

//Zmiana
class Movie {
private:
    string ftitle;
    string fdirector;
    int fyear;
    bool faccess;
public:
    Movie(const string& t, const string& d, int y, bool a) : ftitle{t}, fdirector{d}, fyear{y}, faccess{a}{}

    string get_title() const {return ftitle; }
    string get_director() const{return fdirector; }
    int get_year() const {return fyear; }
    bool get_access() const {return faccess; }

    void set_title(string t){ftitle = t;}
    void set_director(string d){ftitle = d;}
    void set_year(int y){ftitle = y;}
    void set_access(bool a){ftitle = a;}

    void display_admin() const {
        cout << ftitle << ", " << fdirector <<  ", " << fyear << ", Dostepnosc: " << faccess << endl;
    }
    void display_available() const {
        if(faccess)
            cout << ftitle << ", " << fdirector <<  ", " << fyear << endl;
        else
            return;
    }
    void display_not_available() const {
        if(!faccess)
            cout << ftitle << ", " << fdirector <<  ", " << fyear << endl;
        else
            return;

    }
};

#endif //DVD_RENTAL_MOVIE_H
