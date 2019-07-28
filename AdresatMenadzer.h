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

using namespace std;

class AdresatMenadzer{

    int id, idUzytkownika, idAdresata;
    string imie, nazwisko, numerTelefonu, email, adres;
    string nazwaPlikuZAdresatami;
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    int idOstatniegoAdresata;
    string daneOstaniegoAdresataWPliku;


    vector <Adresat> adresaci;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();




public:
    AdresatMenadzer();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();


};

#endif
