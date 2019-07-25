#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H



#include <iostream>
#include <vector>
#include <fstream>


#include "uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZUzytkownikami {

    friend class UzytkownikMenadzer;

    const string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    vector <Uzytkownik> zapiszWszystkichUzytkownikowDoPliku();

};

#endif // PLIKZUZYTKOWNIKAMI_H
