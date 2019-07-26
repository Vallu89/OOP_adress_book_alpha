#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenadzer {

    friend class AdresatMenadzer;

    int idZalogowanegoUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin( string login );
    string wczytajLinie();


public:

    UzytkownikMenadzer( string nazwaPlikuZUzytkownikami ): plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    int logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void wylogujUzytkownika();
    vector <Uzytkownik> zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();

};

#endif
