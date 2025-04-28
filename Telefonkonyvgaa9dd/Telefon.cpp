#include "Telefon.h"
#include <iostream>


using namespace std;



 std::ostream& operator<<(std::ostream& os, const Telefon& rhs) { ///kiir egy telefon objektumot a megadott ostreamre
    os << rhs.getprivate()                                 
        << " "
        << rhs.getmunkahelyi();
    return os;
}

 bool ellenorizhogyszam(const std::string& telszam) {           ///Megnezi hogy az adott telefonszam csak szamokat tartalmaz-e
    for (size_t i = 0; i < telszam.size(); i++) {
        if (!std::isdigit(telszam[i]) && telszam[i]!=' ') {
            throw std::runtime_error("A megadott szam nem engedelyezett karaktereket tartalmaz");
            return false;
        }
    }
    return true;
}

