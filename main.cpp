#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main(){

    //char wybor;
    //vector <Uzytkownik> uzytkownicy;
    //vector <Adresat> adresaci;

    int idOstatniegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    UzytkownikMenadzer uzytkownikMenadzer("Uzytkownicy.txt");
    AdresatMenadzer adresatMenadzer ("Adresaci.txt");
    /*
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    */
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

            //if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
            idOstatniegoAdresata = adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika())
            {
            case '1':
                idOstatniegoAdresata = adresatMenadzer.dodajAdresata();
                break;
            /*case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break; */
            case '4':
                adresatMenadzer.wyswietlWszystkichAdresatow();
                break;
            /*case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break; */
            case '7':
                uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(0);
                adresatMenadzer.pobierzAdresaci().clear();
                break;
            }
        }
    }
    return 0;
}



