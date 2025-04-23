/*
    DESCRIERE GENERALA
            Proiectul implementează un sistem de gestionare a clienților și creditelor bancare,
        construit pe principii de Programare Orientată pe Obiect (OOP) în limbajul C++.
        Aplicația este structurată modular, oferind o arhitectură clară și extensibilă,
        cu accent pe organizarea și manipularea datelor legate de împrumuturi și plăți lunare.
            Sistemul permite gestionarea unui portofoliu de clienți, fiecare client putând avea unul
        sau mai multe credite, iar fiecare credit este compus dintr-un set de rate lunare care pot
        fi urmărite individual. Fiecare clasă este responsabilă de o componentă logică bine definită:

    CLASE:

    RATE:
        Reprezintă o rată lunară dintr-un credit.

    Atribute:
        nrLuna, valoareRata, partePrincipal, parteDobanda, platita

    Funcționalități:
        Constructori / Destructor
        Getter pentru isPlatita() și getValoareRata()
        modificaPlata() – modifică starea unei rate în „plătită”
        Operator << suprascris pentru afișare

    CREDIT:
        Reprezintă un împrumut bancar.

        Atribute:
            dataPornire, dataSfarsit, perioada, sumaImprumutata, dobanda, soldRamas, vector<Rate>

        Funcționalități:
            Constructori / Destructor / Copiere / Asignare
            Gettere: getDobanda(), getSumaImprumutata(), getPerioada()
            primeleRatePlatite(int x) – verifică dacă primele x rate sunt plătite
            Operator << suprascris pentru afișare

    CLIENT:
        Gestionează datele personale ale unui client și lista sa de credite.

        Atribute:
            nume, prenume, adresa, tel, varsta, vechime
            char** denumiriCredite, int nrCredite
            vector<Credit> vectorCredite

        Funcționalități:

            Constructori / Destructor / Copiere / Asignare
            AddCredit(const char*, const Credit&) – adaugă un nou credit și denumirea lui
            DelCredit(const char*) – elimină un credit după denumire
            getFullName() – returnează numele complet al clientului
            getVechime() / setIncVechime(int) – accesori pentru vechime
            AfisareDetaliiClient() – afișează toate datele clientului
            Supraincarcare operator<< pentru afișare rapidă
            genereazaRate(...) – simulează ratele unui credit cu parametri: sumă, perioadă, dobândă, luni plătite


        Funcționalități cheie:
            Adăugare, ștergere și afișare credite
            Simulare rate lunare (cu parte dobândă, principal, status plată)
            Verificare rate plătite (primele x luni)
            Comasare credite (opțional, implementată anterior)
            Afișare date prin operatori <<
            Gestionare dinamică a denumirilor creditelor
            Corectă eliberare a memoriei (destructor, deep copy etc.)

        Mai jos am adaugat utilitatile spuse la laborator
*/

#include <iostream>
#include <vector>
#include "client.h"
#include "credit.h"

int main()
{
    ///Cream 2 credite
    Credit credit1("01-01-2024", "01-01-2025", 12, 12000, 5, 12000);
    Credit credit2("01-06-2024", "01-06-2026", 24, 8000, 7, 8000);

    ///Le adaugam in vectorul de credite ale clientului
    std::vector<Credit> crediteClient = {credit1, credit2};
    const char* denumiri[] = {"CreditMasina", "CreditVacanta"};

    ///Construim obiectul client
    Client client1("Popescu", "Ion", "Str. Lalelelor 3", "0722333444", 35, 5, 2, denumiri, crediteClient);

    ///Afisam clientul
    std::cout << client1;

    ///Adaugam un nou credit
    Credit credit3("01-03-2025", "01-03-2026", 12, 5000, 6, 5000);
    client1.AddCredit("CreditTelefon", credit3);

    ///Simulam un credit ipotetic
    std::cout << " Simulare rate pentru credit ipotetic:\n";
    client1.genereazaRate(15000, 18, 6.5, {1, 2, 5, 6, 7});

    ///Stergem un credit
    client1.DelCredit("CreditVacanta");

    ///DE AICI AM COMPLETAT LA LABORATOR

    ///Vector de rate
    std::vector<Rate> rateTest1 =
    {
        Rate(1, 100, 80, 20, true),
        Rate(2, 100, 80, 20, true),
        Rate(3, 100, 80, 20, false),
        Rate(4, 100, 80, 20, false),
        Rate(5, 100, 80, 20, false),
        Rate(6, 100, 80, 20, false)
    };

    ///Creez un credit pentru a verifica daca ratele sunt platite in ordine
    Credit creditTest1("01-01-2024", "01-06-2024", 6, 600, 5, 600, rateTest1);

    ///Creditul este valid, ordinea fiind una valida
    creditTest1.primeleRatePlatite();

    ///Vector de rate
    std::vector<Rate> rateTest2 =
    {
        Rate(1, 100, 80, 20, true),
        Rate(2, 100, 80, 20, true),
        Rate(3, 100, 80, 20, false),
        Rate(4, 100, 80, 20, true),
        Rate(5, 100, 80, 20, false),
        Rate(6, 100, 80, 20, false)
    };

    ///Creez un credit pentru a verifica daca ratele sunt platite in ordine
    Credit creditTest2("01-01-2024", "01-06-2024", 6, 600, 5, 600, rateTest2);

    ///Creditul nu este valid, rata a 3 a fiind true
    creditTest2.primeleRatePlatite();

    ///Modific rata a 3 a cu modificaPlata din clasa rate
    rateTest2[3].modicaPlata();
    creditTest2 = Credit ("01-01-2024", "01-06-2024", 6, 600, 5, 600, rateTest2);

    ///Creditul nostru va deveni valid dupa modificare
    creditTest2.primeleRatePlatite();

    return 0;
}
