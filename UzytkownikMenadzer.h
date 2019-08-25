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

private:

    PlikZUzytkownikami plikZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;

    int idZalogowanegoUzytkownika;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin( string login );
    string wczytajLinie();

    friend class KsiazkaAdresowa;

public:

    UzytkownikMenadzer( string nazwaPlikuZUzytkownikami, int IDZALOGOWANEGOUZYTKOWNIKA = 0 )
        : plikZUzytkownikami( nazwaPlikuZUzytkownikami ), idZalogowanegoUzytkownika( IDZALOGOWANEGOUZYTKOWNIKA ){
        //idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    int logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika( int noweIdZalogowanegoUzytkownika );
    void wylogujUzytkownika();
    vector <Uzytkownik> zmianaHaslaZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    vector< Uzytkownik > &pobierzUzytkownicy(){ return uzytkownicy
    ; };



};

#endif
