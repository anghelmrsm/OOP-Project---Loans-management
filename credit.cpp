#include <iostream>
#include <cstring>
#include <vector>
#include "credit.h"
#include "rate.h"

///Functie pentru alocare si copiere siruri de carctere
char* Credit::AlocCpyString(const char* sursa)
{
    if (sursa == nullptr)
        return nullptr;

    char *temp = new char[strlen(sursa) + 1];
    strcpy(temp, sursa);
    return temp;
}

///Functie pentru eliberarea memoriei
void Credit::eliberare()
{
    delete [] dataPornire;
    delete [] dataSfarsit;
    perioada = 0;
    sumaImprumutata = 0;
    dobanda = 0;
    soldRamas = 0;
    vectorRate.clear();
}

///Constructor initial
Credit::Credit(const char *dataPornire,
               const char *dataSfarsit,
               const int perioada,
               const float sumaImprumutata,
               const float dobanda,
               const float soldRamas,
               const std::vector <Rate> &vectorRate)
{
    this -> dataPornire = AlocCpyString(dataPornire);
    this -> dataSfarsit = AlocCpyString(dataSfarsit);

    if (perioada > 0)
        this -> perioada = perioada;
    else
        this -> perioada = 0;

    if (sumaImprumutata > 0)
        this -> sumaImprumutata = sumaImprumutata;
    else
        this -> sumaImprumutata = 0;

    if (dobanda > 0)
        this -> dobanda = dobanda;
    else
        this -> dobanda = 0;

    if (soldRamas > 0)
        this -> soldRamas = soldRamas;
    else
        this -> soldRamas = 0;

    this -> vectorRate = vectorRate;
}

///constructor de copiere
Credit::Credit (const Credit &sursa)
{
    this -> dataPornire = new char[strlen(sursa.dataPornire) + 1];
    strcpy(dataPornire, sursa.dataPornire);

    this -> dataSfarsit = new char[strlen(sursa.dataSfarsit) + 1];
    strcpy(dataSfarsit, sursa.dataSfarsit);

    this -> perioada = sursa.perioada;

    this -> sumaImprumutata = sursa.sumaImprumutata;

    this -> dobanda = sursa.dobanda;

    this -> soldRamas = sursa.soldRamas;

    this -> vectorRate = sursa.vectorRate;
}

///Destructor
Credit::~Credit()
{
    eliberare();
}

///Operator de asignare
Credit& Credit::operator=(const Credit &sursa)
{
    if (this != &sursa)
    {
        eliberare();

        this -> dataPornire = AlocCpyString(sursa.dataPornire);
        this -> dataSfarsit = AlocCpyString(sursa.dataSfarsit);

        this -> perioada = sursa.perioada;
        this -> sumaImprumutata = sursa.sumaImprumutata;
        this -> dobanda = sursa.dobanda;
        this -> soldRamas = sursa.soldRamas;

        this -> vectorRate = sursa.vectorRate;

    }
    return *this;
}

std::ostream &operator<<(std::ostream& COUT, const Credit &credit)
{
    if (credit.dataPornire != nullptr)
        COUT<<"Data pornire credit: "<<credit.dataPornire<<'\n';
    else
        COUT<<"Data pornire credit: -\n";

    if (credit.dataSfarsit != nullptr)
        COUT<<"Data sfarsit credit: "<<credit.dataSfarsit<<'\n';
    else
        COUT<<"Data sfarsit credit: -\n";

    if (credit.perioada != 0)
        COUT<<"Perioada: "<<credit.perioada<<'\n';
    else
        COUT<<"Perioada: -\n";
    if (credit.sumaImprumutata != 0)
        COUT<<"Suma Imprumutata: "<<credit.sumaImprumutata<<'\n';
    else
        COUT<<"Suma Imprumutata: -\n";

    if (credit.dobanda != 0)
        COUT<<"Dobanda: "<<credit.dobanda<<'\n';
    else
        COUT<<"Dobanda: -\n";

    if (credit.soldRamas != 0)
        COUT<<"Sold Ramas: "<<credit.soldRamas<<'\n';
    else
        COUT<<"Sold Ramas: -\n";

    for (int i = 0; i < credit.vectorRate.size(); i++)
        COUT<<"Rata "<< i + 1<< ":\n"<<credit.vectorRate[i];

    COUT<<"--------------------------\n";
}

///Getter pentru dobanda
float Credit::getDobanda() const
{
    return dobanda;
}

///Getter pentru suma imprumutata
float Credit::getSumaImprumutata() const
{
    return sumaImprumutata;
}

///Getter pentru perioada
int Credit::getPerioada() const
{
    return perioada;
}

///verificam sa avem rate platite
void Credit::primeleRatePlatite() const
{
    int i = 0;
    bool ok = 1;
    while (vectorRate[i].isPlatita() == true)
        i++;

    for (int j = i; j < vectorRate.size(); j++)
        if (vectorRate[j].isPlatita() == true)
        {
            ok = 0;
            break;
        }

    if (ok == true)
        std::cout<<"Ratele au fost platite in ordine\n";
    else
        std::cout<<"Ratele nu au fost platite in ordine\n";
}

