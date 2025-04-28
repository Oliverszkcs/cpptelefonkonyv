#include <string>
#include <iostream>

using namespace std;


class Telefon {
private:
    string Privat;
    string Munkahelyi;
public:
    Telefon() {Privat = ""; Munkahelyi = "";}
    Telefon(string privattel, string munkahelyitel) :Privat(privattel), Munkahelyi(munkahelyitel) {}
    Telefon(const Telefon& t) { this->Privat = t.Privat, this->Munkahelyi = t.Munkahelyi; }
    string getprivate()const { return Privat; }
    string getmunkahelyi()const { return Munkahelyi; }
    void mentes(ostream& os)const {os << Privat << ";" << Munkahelyi;}
    Telefon operator=(const Telefon& t) { this->Privat = t.getprivate(); this->Munkahelyi = t.getmunkahelyi(); return *this; }
};

std::ostream& operator<<(std::ostream& os, const Telefon& rhs);

bool ellenorizhogyszam(const std::string& telszam);


