#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H


#include <iostream>


using namespace std;

class MetodyPomocnicze{

public:
        static string konwerjsaIntNaString(int liczba);
        static int konwersjaStringNaInt(string liczba);
        static string pobierzLiczbe(string tekst, int pozycjaZnaku);
        static string wczytajLinie();
        bool czyPlikJestPusty(fstream &plikTekstowy);
        char wczytajZnak();

};

#endif
