#include <iostream>
#include <cstring>
#include "rate.h"

///Functie pentru eliberarea memoriei
void Rate::eliberare()
{
    nrLuna = 0;
    valoareRata = 0,
    partePrincipal = 0,
    parteDobanda = 0;
    platita = false;
}

///constructor initial
Rate::Rate(const int nrLuna,
           const float valoareRata,
           const float partePrincipal,
           const float parteDobanda,
           const bool platita)
{
    if (valoareRata > 0)
        this -> valoareRata = valoareRata;
    else
        this -> valoareRata = 0;

    if (nrLuna > 0)
        this -> nrLuna = nrLuna;
    else
        this -> nrLuna = 0;

    if (partePrincipal > 0)
        this -> partePrincipal = partePrincipal;
    else
        this -> partePrincipal = 0;

    if (parteDobanda > 0)
        this -> parteDobanda = parteDobanda;
    else
        this -> parteDobanda = 0;

    this -> platita = platita;
}

///constructor de copiere
Rate::Rate (const Rate &sursa)
{

    this -> nrLuna = sursa.nrLuna;

    this -> valoareRata = sursa.valoareRata;

    this -> partePrincipal = sursa.partePrincipal;

    this -> parteDobanda = sursa.parteDobanda;

    this -> platita = sursa.platita;
}

///Destructor
Rate::~Rate()
{
    eliberare();
}

///Operator de asignare
Rate& Rate::operator=(const Rate &sursa)
{
    if (this != &sursa)
    {
        eliberare();

        this -> nrLuna = sursa.nrLuna;

        this -> valoareRata = sursa.valoareRata;

        this -> partePrincipal = sursa.partePrincipal;

        this -> parteDobanda = sursa.parteDobanda;

        this -> platita = sursa.platita;

    }
    return *this;
}

std::ostream &operator<<(std::ostream& COUT, const Rate &rata)
{

    if (rata.nrLuna != 0)
        COUT<<"Luna: "<<rata.nrLuna<<'\n';
    else
        COUT<<"Luna: -\n";
    if (rata.valoareRata != 0)
        COUT<<"Valoare Rata: "<<rata.valoareRata<<'\n';
    else
        COUT<<"Valoare Rata: -\n";

    if (rata.partePrincipal != 0)
        COUT<<"Parte principal: "<<rata.partePrincipal<<'\n';
    else
        COUT<<"Parte principal: -\n";

    if (rata.parteDobanda != 0)
        COUT<<"Parte Dobanda: "<<rata.parteDobanda<<'\n';
    else
        COUT<<"Parte Dobanda: 0\n";

    if (rata.platita == true)
        COUT << "Platita\n";
    else
        COUT << "Neplatita\n";

    COUT<<"--------------------------\n";
}

///Getter pentru platita
bool Rate::isPlatita() const
{
    return platita;
}

///Getter pentru valoarea ratii
float Rate::getValoareRata() const
{
    return valoareRata;
}

///modificam statusul platii
void Rate::modicaPlata()
{
    this -> platita = !platita;
}
