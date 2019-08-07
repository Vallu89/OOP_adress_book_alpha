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

    int id, idUzytkownika, idAdresata;
    string imie, nazwisko, numerTelefonu, email, adres;
    string nazwaPlikuZAdresatami;
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    int idOstatniegoAdresata;
    string daneOstaniegoAdresataWPliku;
    string liniaZDanymiAdresata;

    UzytkownikMenadzer uzytkownikMenadzer;
    PlikZUzytkownikami plikzuzytkownikami;


    vector <Adresat> adresaci;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    Adresat podajDaneNowegoAdresata();
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);




public:
    AdresatMenadzer(string nazwaPlikuZAdresatami);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata(vector <Adresat> &adresaci);
    void wyswietlWszystkichAdresatow(vector <Adresat> &adresaci);
    void wyswietlDaneAdresata(Adresat adresat);

};

#endif
