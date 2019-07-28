#include "AdresatMenadzer.h"

AdresatMenadzer::AdresatMenadzer(){

    nazwaPlikuZAdresatami = "Adresaci.txt";
}

int AdresatMenadzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    Adresat adresat;
    daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    daneJednegoAdresataOddzielonePionowymiKreskami = "";
    idOstatniegoAdresata = 0;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(UzytkownikMenadzer::idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami())
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

int AdresatMenadzer::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami()
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat AdresatMenadzer::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.id = atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 2:
                adresat.idUzytkownika = atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 3:
                adresat.imie = pojedynczaDanaAdresata;
                break;
            case 4:
                adresat.nazwisko = pojedynczaDanaAdresata;
                break;
            case 5:
                adresat.numerTelefonu = pojedynczaDanaAdresata;
                break;
            case 6:
                adresat.email = pojedynczaDanaAdresata;
                break;
            case 7:
                adresat.adres = pojedynczaDanaAdresata;
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int AdresatMenadzer::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami()
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
