#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main(){


    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    UzytkownikMenadzer uzytkownikMenadzer("Uzytkownicy.txt");

        while (true)
    {
        if (uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika() == 0)
        {

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuGlownego())
            {
            case '1':
                uzytkownikMenadzer.rejestracjaUzytkownika();
                break;

            case '2':
                uzytkownikMenadzer.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
        AdresatMenadzer adresatMenadzer ("Adresaci.txt",uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
            if (adresatMenadzer.pobierzAdresaci().empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
            idOstatniegoAdresata = adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika())
            {
            case '1':
                idOstatniegoAdresata = adresatMenadzer.dodajAdresata();
                break;
            case '2':
                adresatMenadzer.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                adresatMenadzer.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                adresatMenadzer.wyswietlWszystkichAdresatow();
                break;
            case '5':
                adresatMenadzer.usunAdresata();
                break;
            case '6':
                adresatMenadzer.edytujAdresata();
                break;
            case '7':
                uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '9':
                uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(0);
                adresatMenadzer.pobierzAdresaci().clear();
                break;
            }
        }
    }
    return 0;
}

int _main(){


AdresatMenadzer adresatMenadzer ("Adresaci.txt",1 );
adresatMenadzer.edytujAdresata();

    return 0;
}

int __main(){


UzytkownikMenadzer uzytkownikMenadzer("Uzytkownicy.txt",6);
uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();

    return 0;
}
