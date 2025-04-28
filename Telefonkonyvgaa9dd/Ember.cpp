#include "Ember.h"
#include  <iostream>
#include <string>
using namespace std;
/**
* 
* 
* 
* 
*/
bool Ember::operator<(const Ember& a)const {        //Nevsor szerint elobb van-e a megadott Ember objektum
        return this->Nev < a.getnev();           
}

bool Ember::operator==(const Ember& rhs)const {     //Ket Ember egyenlo-e (csak vezetek es keresztnev hasonlitas alapjan)
        string kisnev1 = kisbetu(this->Nev);   
        string kisnev2 = kisbetu(rhs.getnev());
        if (kisnev1 == kisnev2){
            return true;
        }
        else {
            return false;
        }
    }
bool Ember::operator!=(const Ember& rhs)const {     ///Ket ember != operatora  !(==)
        return !(this->Nev == rhs.Nev);
}

Ember Ember::operator=(const Ember& rhs) {          
    this->Nev = rhs.getnev();
    this->Becenev = rhs.getBecenev();
    this->Telefonszamok = rhs.gettel();
    this->cim = rhs.getlakcim();
    return *this;
}

                            
 bool ellenorizhogybetu(const std::string& nev) {       ///megnezi hogy az adott nev csak betukat tartalmaz - e
    for (size_t i = 0; i < nev.size(); i++) {
        if (!std::isalpha(nev[i]) && nev[i] != ' ') {
            throw std::runtime_error("A megadott nev nem engedelyezett karaktereket tartalmaz");
            return false;
        }
    }
    return true;
}

 ostream& operator<<(ostream& os, const Ember& rhs) {       ///Kiir egy Ember objektumot a megadott ostreamre
    os << rhs.getnev()
        << " "
        << rhs.getBecenev()
        << " "
        << rhs.gettel()
        << " "
        << rhs.getlakcim();
    return os;
}

 string kisbetu(string str) {                 ///Megadott string kisbetus valtozatat adja vissza
     string kisb = "";
     for (size_t i = 0; i < str.length(); i++) {
         kisb.push_back(tolower(str[i]));
     }
     return kisb;
}



