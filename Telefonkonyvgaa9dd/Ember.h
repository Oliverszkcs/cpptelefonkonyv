#ifndef EMBER_H_INCLUDED
#define EMBER_H_INCLUDED
#include "Telefon.h"
#include "Lakcim.h"
using namespace std;


class Ember {
private:
    string Nev;
    string Becenev;
    Telefon Telefonszamok;
    Lakcim cim;
public:
    Ember() :Nev(""), Becenev(""), Telefonszamok("", ""), cim("") {}
    Ember(const Ember& e){
        this->Nev = e.Nev; this->Becenev = e.Becenev; this->Telefonszamok = e.Telefonszamok; this->cim = e.cim;
    }
    Ember(string nev) :Telefonszamok("", ""), cim("") {
        this->Nev = nev;
        Becenev = "";
    }
    Ember(string neve, string bece, string privat, string munkahelyi, string cimecske) : Nev(neve),Becenev(bece),Telefonszamok(privat, munkahelyi),cim(cimecske) {}
    
    string getnev()const { return Nev;}

    string getBecenev()const {return Becenev;}

    const Telefon& gettel()const {return Telefonszamok;}

    const Lakcim& getlakcim()const {return cim;}

    bool operator<(const Ember& a)const;

    bool operator==(const Ember& rhs)const;

    bool operator!=(const Ember& rhs)const;

    Ember operator=(const Ember& rhs);


  
};
ostream& operator<<(ostream& os, const Ember& rhs);
bool ellenorizhogybetu(const std::string& nev);
string kisbetu(string str);


#endif // EMBER_H_INCLUDED
