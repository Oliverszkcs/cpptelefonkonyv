#include <iostream>
#include "Lista.hpp"
#include "Testek.cpp"
#include <cctype>
#include "Ember.h"

using namespace std;
//#define RUN_TEST


int main()
{

#ifndef RUN_TEST

    int valasztas = 10;
    Lista<Ember> lista;
    while (valasztas != -1) {
        cout << endl;
        cout << "Telefonkonyv" << endl;
        cout << "1. Ember hozzadasa" << endl;
        cout << "2. Ember torlese" << endl;
        cout << "3. Emberek listazasa" << endl;
        cout << "4. Ember keresese" << endl;
        cout << "5. Lista mentese" << endl;
        cout << "6. Lista betoltese" << endl;
        cout << "0. Kilepes" << endl;

        cin >> valasztas;
        cin.ignore(1);
        switch (valasztas) {

        case 1: {///Bekeri az adatokat es letrehozza az objektumot amit hozzaad a lancolt listahoz
            string nev("nev"); string becenev("-"); string tel1("tel1"); string tel2("-"); string lakcim("utcanev ut/utca hazszam");
            cout << "Kerem az ember nevet" << endl;
            std::getline(cin, nev);
            try {
                ellenorizhogybetu(nev);               
            }
            catch (std::runtime_error e) {
                cout << e.what() << endl;
                break;
            }

            cout << "Kerem az ember becenevet (Ha nincs irjon - jelet vagy nyomjon [Enter])" << endl;
            
            std::getline(cin, becenev);
           
            if (becenev == "") {
                becenev = '-';
            }

            cout << "Kerem a privat telefonszamat" << endl;
            std::getline(cin, tel1);
            try {
                ellenorizhogyszam(tel1);
            }
            catch (std::runtime_error e) {
                cout << e.what() << endl;
                break;
            }

            cout << "Kerem a munkahelyit szamat(Ha nincs irjon - jelet vagy nyomjon [Enter])" << endl;
            std::getline(cin, tel2);
            try {
                ellenorizhogyszam(tel2);
            }
            catch (std::runtime_error e) {
                cout << e.what() << endl;
                break;
            }

            if (tel2 == "") {
                tel2 = '-';
            }

            cout << "Kerem a lakcimet ebben a formatumban: \n utca nev , ut/utca , hazszam " << endl;
            std::getline(cin, lakcim);
            Ember uj(nev, becenev, tel1, tel2, lakcim);
            lista.hozzaad(uj);
            break;
        }

        case 2: {//Nev alapjan torol
            string name;
            cout << "Add meg a torolni kivant ember nevet:" << endl;
            std::getline(cin, name);
            string kisbetuname = kisbetu(name);
            Ember torol(kisbetuname);
            try { lista.torol(torol); }
            catch (std::runtime_error e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 3: {
            try { lista.kiir(cout); }
            catch (std::runtime_error e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 4: {
            cout << "Adja meg a keresni kivant ember nevet" << endl;
            string keresnev;
            std::getline(cin, keresnev);
            try { cout << lista.keres(keresnev).elem << endl;}
            catch (std::runtime_error e) {
                cout << e.what() << endl;
            }
            break;

        }

        case 5: {
            cout << "Adja meg a fajl nevet igy (pelda.txt)" << endl;
            string fajlnev;
            getline(cin, fajlnev);
            fstream mentes;
            try { mentes.open(fajlnev, ios::out | ios::trunc); }            //hiba van e fajl megnyitasakor
            catch (std::runtime_error e) {
                cout << e.what() << endl;
            }
            try { lista.mentes(mentes); }
            catch (std::runtime_error e) {          //ervenytelen fajl
                cout << e.what() << endl;
            }

            mentes.close();
            break;


        }

        case 6: {
            cout << "Kerem a betolteshez a fajl nevet igy (pelda.txt)" << endl;
            string fajlbenev;
            std::getline(cin, fajlbenev);
            fstream mentes;
            mentes.open(fajlbenev); 
            if (!!mentes) {
                string sor;
                string nev;
                while (std::getline(mentes, sor)) {
                    std::stringstream sstream(sor);
                    string name, becnev, tel1, tel2, lakcim;
                    std::getline(sstream, name, ';');
                    std::getline(sstream, becnev, ';');
                    std::getline(sstream, tel1, ';');
                    std::getline(sstream, tel2, ';');
                    std::getline(sstream, lakcim, ';');
                    Ember uj(name, becnev, tel1, tel2, lakcim);
                    cout << "Elem betoltve: " << uj << endl;
                    lista.hozzaad(uj);
                }
                
            }
            else
                cout << "A fajlt nem lehet megnyitni" << endl;
            break;
        }
        case 0: {

            return 0;
        }

        default: {
            cout << "Ervenytelen szam" << endl;

        }

        }

    }
#else
    Testel();
    return 0;
#endif // RUN_TEST
  
}
/*to do
* .txt - a nev moge                 nem kell? (labvvez) 
* also a nev getline(mentes,beolvas)kesz
* Nev csak betukbul alljon          kesz
* tesztek                           kb kesz
* keresek kisbetu/nagybetu          kesz
* fuggvenybe a beolvast
* dokumentacio
* mindent cpp fajlba xd             kesz
* minden osztaly operaotr=, masolo konstruktor   kesz
*/