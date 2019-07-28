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

using namespace std;

class AdresatMenadzer{

    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;
    string nazwaPlikuZAdresatami;

    vector <Adresat> adresaci;





public:
    AdresatMenadzer();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

};

#endif
