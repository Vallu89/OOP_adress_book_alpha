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

 bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){

   if (uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika() == 0)
        return true;
    else
        return false;
 }

 char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    MetodyPomocnicze metodyPomocnicze;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    MetodyPomocnicze metodyPomocnicze;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    //cout << "5. Usun adresata" << endl;
    //cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    //cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}
