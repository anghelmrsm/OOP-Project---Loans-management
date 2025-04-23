#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "client.h"
#include "credit.h"

///constructor initial
Client::Client (const char *nume,
                const char *prenume,
                const char *adresa,
                const char *tel,
                const int varsta,
                const int vechime,
                const int nrCredite,
                const char *denumiriCredite[],
                const std::vector<Credit>& vectorCredite)
{

    this -> nume = AlocCpyString(nume);
    this -> prenume = AlocCpyString(prenume);
    this -> adresa = AlocCpyString(adresa);
    this -> tel = AlocCpyString(tel);

    if (varsta > 0)
    {
        this -> varsta = varsta;
    }
    else
        this -> varsta = 0;

    if (vechime > 0)
    {
        this -> vechime = vechime;
    }
    else
        this -> vechime = 0;

    if (nrCredite > 0 and denumiriCredite != nullptr)
    {
        this -> nrCredite = nrCredite;
        this -> denumiriCredite = new char *[nrCredite];

        for (int i=0; i < nrCredite; i++)
            if (denumiriCredite[i] != nullptr)
            {
                this -> denumiriCredite[i] = AlocCpyString(denumiriCredite[i]);
            }
    }
    else
        this -> nrCredite = 0;

    this -> vectorCredite = vectorCredite;
}

///Constructor de copiere
Client::Client (const Client &sursa)
{
    this -> nume = new char[strlen(sursa.nume) + 1];
    strcpy(nume, sursa.nume);

    this -> prenume = new char[strlen(sursa.prenume) + 1];
    strcpy(prenume, sursa.prenume);

    this -> adresa = new char[strlen(sursa.adresa) + 1];
    strcpy(adresa, sursa.adresa);

    this -> tel = new char[strlen(sursa.tel) + 1];
    strcpy(tel, sursa.tel);

    this -> varsta = sursa.varsta;

    this -> vechime = sursa.vechime;

    this -> nrCredite = sursa.nrCredite;

    if (sursa.nrCredite > 0 and sursa.denumiriCredite != nullptr)
    {
        this -> denumiriCredite = new char *[sursa.nrCredite];
        for (int i=0; i< sursa.nrCredite; i++)
        {
            this -> denumiriCredite[i] = new char[strlen(sursa.denumiriCredite[i]) + 1];
            strcpy(this -> denumiriCredite[i], sursa.denumiriCredite[i]);
        }
    }

    this -> vectorCredite = vectorCredite;
}

///Functie pentru eliberarea memoriei
void Client::eliberare()
{
    delete [] nume;
    delete [] prenume;
    delete [] adresa;
    delete [] tel;
    varsta = 0;
    vechime = 0;

    if (denumiriCredite != nullptr)
    {
        for (int i=0; i<nrCredite; i++)
            delete [] denumiriCredite[i];
        delete [] denumiriCredite;
    }

    nrCredite = 0;

    vectorCredite.clear();
}

///Functie pentru alocare si copiere siruri de carctere
char* Client::AlocCpyString(const char* sursa)
{
    if (sursa == nullptr)
        return nullptr;

    char *temp = new char[strlen(sursa) + 1];
    strcpy(temp, sursa);
    return temp;
}

///Destructor
Client::~Client()
{
    eliberare();
}

///Functie de afisare a datelor
Client::AfisareDetaliiClient() const
{
    if (nume != nullptr)
        std::cout<<"Nume: "<<nume<<'\n';
    else
        std::cout<<"Nume: -\n";
    if (prenume != nullptr)
        std::cout<<"Preume: "<<prenume<<'\n';
    else
        std::cout<<"Prenume: -\n";
    if (adresa != nullptr)
        std::cout<<"Adresa: "<<adresa<<'\n';
    else
        std::cout<<"Adresa: -\n";
    if (tel != nullptr)
        std::cout<<"Telefon: "<<tel<<'\n';
    else
        std::cout<<"Telefon: -\n";
    if (varsta != 0)
        std::cout<<"Varsta: "<<varsta<<'\n';
    else
        std::cout<<"Varsta: 0\n";
    if (vechime != 0)
        std::cout<<"Vechime: "<<vechime<<'\n';
    else
        std::cout<<"Vechime: 0\n";
    if (nrCredite > 0)
    {
        std::cout<<"Numar de credite: "<<nrCredite<<'\n';
        for (int i=0; i < nrCredite - 1; i++)
        {
            std::cout<<"Detalii despre creditul: "<<denumiriCredite[i]<<"\n";
            std::cout<<vectorCredite[i]<<"\n";
        }
        std::cout<<denumiriCredite[nrCredite - 1]<<'\n';

    }
    else
        std::cout<<"Numar de credite: 0\n";
    std::cout<<"--------------------------\n";
}

///Functie Getter pentru extragerea numelui complet
char* Client::getFullName() const
{
    char *fullName = new char[strlen(nume) + strlen(prenume) + 2];
    strcpy(fullName,nume);
    strcat(fullName," ");
    strcat(fullName,prenume);
    return fullName;
}

///Functie Getter pentru extragerea vechimii
int Client::getVechime() const
{
    return vechime;
}

///Functie Setter pentru vechime
void Client::setIncVechime(int nou)
{
    /// IDEE - Legandu ma de data de infintare a unui credit din clasa credit modfific vechimea
    vechime = nou;
}

///Functie Adaugare credit
void Client::AddCredit (const char *creditNou, const Credit &c)
{
    char **temp = new char*[nrCredite + 1];

    for (int i = 0; i < nrCredite; i++) {
        temp[i] = new char[strlen(denumiriCredite[i]) + 1];
        strcpy(temp[i], denumiriCredite[i]);
    }

    temp[nrCredite] = new char[strlen(creditNou) + 1];
    strcpy(temp[nrCredite],creditNou);

    delete [] denumiriCredite;
    denumiriCredite = temp;
    nrCredite++;

    vectorCredite.push_back(c);
}


///Functie Eliminare credit x
void Client::DelCredit (const char *creditElim)
{
    /// numar cate credite cu denumirea data apar in lista
    int cnt = 0;
    for (int i = 0; i < nrCredite; i++)
        if (strcmp(denumiriCredite[i],creditElim) == 0)
            cnt++;

    /// aloc spatiu pentru temp si adaug creditele ramase
    char **temp = new char *[nrCredite - cnt];

    int j = 0;
    for (int i = 0; i < nrCredite; i++)
        if (strcmp(denumiriCredite[i],creditElim) != 0)
        {
            temp[j++] = denumiriCredite[i];
            vectorCredite.erase(vectorCredite.begin() + i);
        }

    /// sterg DOAR vectorul de pointeri pentru a il actualiza cu cel al temp
    delete [] denumiriCredite;
    denumiriCredite = temp;
    nrCredite = nrCredite - cnt;
}

///Operator de asignare
Client& Client::operator=(const Client &sursa)
{
    if (this != &sursa)
    {
        eliberare();

        this -> nume = AlocCpyString(sursa.nume);
        this -> prenume = AlocCpyString(sursa.prenume);
        this -> adresa = AlocCpyString(sursa.adresa);
        this -> tel = AlocCpyString(sursa.tel);

        this -> varsta = sursa.varsta;
        this -> vechime = sursa.vechime;
        this -> nrCredite = sursa.nrCredite;

        if (sursa.nrCredite > 0 and sursa.denumiriCredite != nullptr)
        {
            this -> denumiriCredite = new char *[sursa.nrCredite];
            for (int i = 0; i < sursa.nrCredite; i++)
            {
                this -> denumiriCredite[i] = new char[strlen(sursa.denumiriCredite[i]) + 1];
                strcpy(this -> denumiriCredite[i], sursa.denumiriCredite[i]);
            }
        }

        this -> vectorCredite = sursa.vectorCredite;
    }
    return *this;
}

std::ostream &operator<<(std::ostream& COUT, const Client &client)
{
    if (client.nume != nullptr)
        COUT<<"Nume: "<<client.nume<<'\n';
    else
        COUT<<"Nume: -\n";
    if (client.prenume != nullptr)
        COUT<<"Preume: "<<client.prenume<<'\n';
    else
        COUT<<"Prenume: -\n";
    if (client.adresa != nullptr)
        COUT<<"Adresa: "<<client.adresa<<'\n';
    else
        COUT<<"Adresa: -\n";
    if (client.tel != nullptr)
        COUT<<"Telefon: "<<client.tel<<'\n';
    else
        COUT<<"Telefon: -\n";
    if (client.varsta != 0)
        COUT<<"Varsta: "<<client.varsta<<'\n';
    else
        COUT<<"Varsta: 0\n";
    if (client.vechime != 0)
        COUT<<"Vechime: "<<client.vechime<<'\n';
    else
        COUT<<"Vechime: 0\n";
    if (client.nrCredite > 0)
    {
        COUT<<"Numar de credite: "<<client.nrCredite<<'\n';
        for (int i=0; i < client.nrCredite - 1; i++)
            COUT<<"Detalii despre creditul "<<client.denumiriCredite[i]<<":\n"<<client.vectorCredite[i];
        COUT<<"Detalii despre creditul "<<client.denumiriCredite[client.nrCredite - 1]<<":\n"<<client.vectorCredite[client.nrCredite - 1];
    }
    else
        COUT<<"Numar de credite: 0\n";
}

void Client::genereazaRate(float sumaImprumutata, int perioadaLuni, float dobandaAnuala, const std::vector<int>& luniPlatite) const
{
    float dobandaLunara = dobandaAnuala / 12 / 100;
    float valoareRata = (sumaImprumutata * dobandaLunara) / (1 - pow(1 + dobandaLunara, -perioadaLuni));
    float soldRamas = sumaImprumutata;

    std::cout << "\n--- Simulare Rate ---\n";
    std::cout << "Suma: " << sumaImprumutata << " | Dobanda Anuala: " << dobandaAnuala << "% | Perioada: " << perioadaLuni << " luni\n\n";

    for (int luna = 1; luna <= perioadaLuni; luna++)
    {
        float parteDobanda = soldRamas * dobandaLunara;
        float partePrincipal = valoareRata - parteDobanda;

        bool platita = std::find(luniPlatite.begin(), luniPlatite.end(), luna) != luniPlatite.end();

        std::cout << "Luna " << luna << ":\n";
        std::cout << "  Rata: " << valoareRata << "\n";
        std::cout << "  Parte Dobanda: " << parteDobanda << "\n";
        std::cout << "  Parte Principal: " << partePrincipal << "\n";
        std::cout << "  Platita: " << (platita ? "DA" : "NU") << "\n";
        std::cout << "-----------------------------\n";

        soldRamas -= partePrincipal;
    }
}

