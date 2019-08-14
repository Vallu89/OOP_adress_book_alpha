#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H



#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"




using namespace std;

class PlikZUzytkownikami {



    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI)
        : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(NAZWAPLIKUZUZYTKOWNIKAMI){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);



};

#endif // PLIKZUZYTKOWNIKAMI_H
