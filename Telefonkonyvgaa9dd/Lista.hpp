#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Ember.h"
#include <fstream>
#include <iostream>

using namespace std;

template<typename T>
inline void save(ostream& os, const T& a) {         ///Ment egy ostreambe
    os << a;
}
template<>
inline void save(ostream& os, const Ember& e) {         ///Ember specifikus mentes
    os << e.getnev()
        << ";"
        << e.getBecenev()
        << ";";
        e.gettel().mentes(os);
        os << ";"
            << e.getlakcim();
}
template <typename T >
class Lista {
private:
    template<typename C>
    class ListaElem {
    public:
        ListaElem<C>* kov;
        C elem;
        ListaElem(const C& elem) {          ///Generikus lista ListaEleme
            this->elem = elem;
            kov = NULL;
        }

    };

    ListaElem<T>* eleje;

public:
    Lista() {
        eleje = NULL;               ///Letrehozza az ures listat
    }

    void hozzaad(const T& elem) {           ///Hozzad egy elemet a listahoz(rendezve epit)
        ListaElem<T>* uj = new ListaElem<T>(elem);
        ListaElem<T>* lemarado = NULL;
        ListaElem<T>* mozgo = eleje;
        while (mozgo != NULL && mozgo->elem < uj->elem) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            uj->kov = eleje;
            eleje = uj;
        }
        else {
            lemarado->kov = uj;
            uj->kov = mozgo;
        }
    }

    ostream& kiir(ostream& os)const {           ///Megadott ostreamre irja a listat
        if (eleje == NULL) {
            throw std::runtime_error("A listas ures");
        }
        ListaElem<T>* mozgo = eleje;
        while (mozgo != NULL) {
            os << mozgo->elem;
            os << endl;
            mozgo = mozgo->kov;
        }
        return os;
    }

    ListaElem<T>& keres(const T& x)const {          ///Megkeres egy adott listaelem adattagjat, listaelemmel ter vissza
        if (eleje == NULL) {
            throw std::runtime_error("A listas ures");
        }
        ListaElem<T>* mozgo = eleje;
        while (mozgo != NULL) {
            if (mozgo->elem == x) {
                return *mozgo;
            }
            mozgo = mozgo->kov;
        }
        throw std::runtime_error("Nem talalt elem");
    }

    void torol(const T& x) {            ///megadott adattag alapjan torol egy listaelemet
        ListaElem<T>* mozgo = eleje;
        ListaElem<T>* lemarado = NULL;
        if (eleje == NULL) {
            throw std::runtime_error("Nem letezik a lista amibol torolni akar");
        }
        while (mozgo != NULL && mozgo->elem != x) {
            lemarado = mozgo;                           ///lepked a listan, megkeresi az adott elemet
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            ListaElem<T>* ujelso = mozgo->kov;          /// ha az elejerol kell torolni
            delete mozgo;
            eleje = ujelso;
        }
        else if (mozgo == NULL) {
            throw std::runtime_error("Nem talalt elemet akar torolni");     /// Nincs ilyen elem
        }


        else {
            lemarado->kov = mozgo->kov;             ///Barhonnan a listabol
            delete mozgo;

        }

    }

    ~Lista() {                          ///Felszabaditja a listat es torli
        ListaElem<T>* mozgo = eleje;
        while (mozgo != NULL) {
            ListaElem<T>* x = mozgo->kov;       
            delete mozgo;
            mozgo = x;
        }
    }

    void mentes(fstream& fs) {              ///fajlba mentes megvalositasa
        if (eleje == NULL) {
            throw std::runtime_error("Ures listat akar menteni");
        }
        if (!fs) {
            throw std::runtime_error("Nem sikerult megnyitni a fajlt");
        }

        ListaElem<T>* mozgo = eleje;
        while (mozgo != NULL) {
            save<T>(fs, mozgo->elem);           ///azert hiv meg fuggvenyt hogy ha T=Ember akkor masfajta modon mentse el ne az operator <<-t hasznalja
            fs << endl;
            mozgo = mozgo->kov;
        }
        cout << "Sikeres mentes" << endl;
    }

  

    bool egyenlo(const T& a, const T& b) {          ///Ketto T tipusu parameter osszehasonlitasa
        return a.elem == b.elem;
    }


    void fajlbololvas(fstream& fs, const T& t) {        ///Beolvasas fajlbol (1 adat)
        if (!fs) {
            throw std::runtime_error("Nem sikerult megnyitni a fajlt");
        }
        fs >> t;
    }
    void beolvas(fstream& fs) {                 ///Beolvasas fajlbol(osszes adat)
        if (!fs) {
            throw std::runtime_error("Nem sikerult megnyitni");
        }
        else {
            string sor;
            T adat;
            while (getline(fs, sor)) {
                stringstream ss(sor);
                ss >> adat;
                hozzaad(adat);
            }
            cout << "Sikeres betoltes" << endl;
        }
    }

};


#endif // LISTA_H_INCLUDED
