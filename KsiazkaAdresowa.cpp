#include "KsiazkaAdresowa.h"




void KsiazkaAdresowa::rejestracjaUzytkownika(){

     uzytkownikMenadzer.rejestracjaUzytkownika();

}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){

        adresatMenadzer = new AdresatMenadzer( NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.idZalogowanegoUzytkownika);
    }

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika(){

    uzytkownikMenadzer.wylogujUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;

}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){

    adresatMenadzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku();

}

void KsiazkaAdresowa::dodajAdresata(){

    adresatMenadzer->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){

    adresatMenadzer->wyswietlWszystkichAdresatow();
}
