#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"

using namespace std;



char wybierzOpcjeZMenuGlownego( char wybor )
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

char wybierzOpcjeZMenuUzytkownika( char wybor )
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




int main(){

    char wybor;
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
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = wybierzOpcjeZMenuGlownego( wybor );

            switch (wybor)
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

            wybor = wybierzOpcjeZMenuUzytkownika( wybor );

            switch (wybor)
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



