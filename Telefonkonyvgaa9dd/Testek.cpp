#include "gtest_lite.h"
#include "memtrace.h"
#include "Lista.hpp"


inline void Testel(){
	TEST(Listaint, hozzad_keres) {
		Lista<int>lista;
		lista.hozzaad(2);
		lista.hozzaad(4);
		lista.hozzaad(3);

		EXPECT_EQ(2,lista.keres(2).elem);		///sima hozzaadas
		EXPECT_EQ(4,lista.keres(4).elem);
		EXPECT_EQ(3,lista.keres(3).elem);
	}END

	TEST(Listadouble, torles) {
		Lista<double>lista;
		lista.hozzaad(2.1);
		lista.hozzaad(1.3);
		lista.hozzaad(4.2);
		lista.torol(2.1);
		
		EXPECT_THROW(lista.torol(2.2), std::runtime_error);		///nem letezo torlese
		EXPECT_THROW(lista.keres(2.1),std::runtime_error);		///tenyleg torol-e 
		EXPECT_EQ(4.2, lista.keres(4.2).elem);					///mast nem torolt-e veletlen
		

	}END

	TEST(Listaint, mentes_beolvasas) {
		Lista<int> lista;
		lista.hozzaad(1);
		lista.hozzaad(2);
		lista.hozzaad(3);

		fstream fajl;
		fajl.open("mentestest.txt", ios::trunc | ios::out);
		if (!fajl) {
			cout << "nem sikerult";					///fajlba iras, visszaolvasas
		}
		else {
			lista.mentes(fajl);		
		}
		lista.beolvas(fajl);

		EXPECT_EQ(1, lista.keres(1).elem);			///betoltes utan leteznek-e
		EXPECT_EQ(2, lista.keres(2).elem);
		EXPECT_EQ(3, lista.keres(3).elem);	
		EXPECT_THROW(lista.keres(4), runtime_error);///nem lett e valami + elem ( jo az olvasas)
	}END
	
	TEST(Listachar, kiir) {
		Lista<char>lista;
		stringstream os;

		EXPECT_THROW(lista.kiir(os), runtime_error);

		lista.hozzaad('a');
		lista.hozzaad('c');
		lista.hozzaad('b');

	//	string elvart = "a\nb\nc\n";				/// objektum utan endl menteskor
		lista.kiir(os);

		EXPECT_TRUE("a\nb\nc\n" == os.str());				///kiiras helyessege
		

	}END

	TEST(Ember, operatorok) {
		Ember Lajos("Nagy Lajos");
		Ember Bela = Lajos;
		Ember Tobias("Kis Tobias");
		Ember Belaa(Bela);

		EXPECT_TRUE(Bela == Belaa);					/// masolo konstruktor, == operator
		EXPECT_TRUE(Bela == Lajos);					/// = , ==
		EXPECT_FALSE(Bela == Tobias);				/// ==
		EXPECT_TRUE(Lajos != Tobias);				///!=
		EXPECT_TRUE(Bela.getnev() == "Nagy Lajos");	/// =
		EXPECT_TRUE(Tobias < Bela);					/// Kis Tobias hamarabb van e nevsorban mint Nagy Lajos		

	}END

	TEST(Egyeb, fuggvenyek) {
		string csakbetu = "a b c";
		string csakszam = "123";
		string vegyes = "a 1 3 + 1 h";
		string NAGY = "HELLO";
											
		EXPECT_TRUE(ellenorizhogybetu(csakbetu));				///betuk + space ellenorzese		
		EXPECT_THROW(ellenorizhogybetu(csakszam),runtime_error);/// szamokra
		EXPECT_THROW(ellenorizhogybetu(vegyes),runtime_error );	///vegyesre

		EXPECT_TRUE(ellenorizhogyszam(csakszam));				///szamokra teszt
		EXPECT_THROW(ellenorizhogyszam(csakbetu),runtime_error);///betuk + space
		EXPECT_THROW(ellenorizhogyszam(vegyes),runtime_error);	///szamok + space + betuk

		string kicsi = kisbetu(NAGY);
		string has = "hello";
		EXPECT_TRUE(has == kicsi);		///Csak nagybetus string atalakitasa
	}END


}