#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <fstream>


using namespace std;

class PlikTekstowy {

protected:

    const string NAZWA_PLIKU;

public:

    PlikTekstowy (string nazwa_pliku): NAZWA_PLIKU(nazwa_pliku){};
    bool czyPlikJestPusty(fstream &plikTekstowy);


};

#endif
