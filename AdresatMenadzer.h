#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "uzytkownik.h"
#include "UzytkownikMenadzer.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class AdresatMenadzer{

    Adresat adresat;
    int idAdresata;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    string nazwaPlikuZAdresatami;
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    int idOstatniegoAdresata;
    string daneOstaniegoAdresataWPliku;
    string liniaZDanymiAdresata;

    vector <Adresat> adresaci;

    friend class KsiazkaAdresowa;

    AdresatMenadzer( string NAZWAPLIKUZADRESATAMI , int idZalogowanegoUzytkownika )
        : nazwaPlikuZAdresatami ( NAZWAPLIKUZADRESATAMI ), ID_ZALOGOWANEGO_UZYTKOWNIKA ( idZalogowanegoUzytkownika ) {

        adresat = wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    Adresat podajDaneNowegoAdresata();
    void dopiszAdresataDoPliku();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami();
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:

    Adresat wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata();

};

#endif