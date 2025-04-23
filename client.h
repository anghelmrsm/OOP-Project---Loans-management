#include <vector>
#include "credit.h"

class Client
{
private:
    char *nume, *prenume, *adresa, *tel, **denumiriCredite;
    int varsta, vechime, nrCredite;
    std::vector <Credit> vectorCredite;

    ///Functie pentru eliberarea memoriei
    void eliberare();

    ///Functie pentru alocare si copiere siruri de carctere
    char* AlocCpyString(const char* sursa);

public:
    ///Constructor initial
    Client (const char *nume = nullptr,
            const char *prenume = nullptr,
            const char *adresa = nullptr,
            const char *tel = nullptr,
            const int varsta = 0,
            const int vechime = 0,
            const int nrCredite = 0,
            const char *denumiriCredite[] = nullptr,
            const std::vector <Credit>& vectorCredite = {});

    ///Constructor de copiere
    Client (const Client &sursa);

    ///Destructor
    ~Client();

    ///Functie de afisare a datelor
    AfisareDetaliiClient() const;

    ///Functie Getter pentru extragerea numelui complet
    char* getFullName() const;

    ///Functie Getter pentru extragerea vechimii
    int getVechime() const;

    ///Functie Setter pentru vechime
    void setIncVechime(const int nou);

    ///Functie Adaugare credit
    void AddCredit (const char *creditNou, const Credit &c);

    ///Functie Eliminare credit x
    void DelCredit (const char *creditElim);

    ///Operator de asignare
    Client& operator=(const Client& clientNou);

    ///Supraincarcare
    friend std::ostream &operator<<(std::ostream& COUT, const Client &client);

    ///Simulator rate
    void genereazaRate(float sumaImprumutata,
                       int perioadaLuni,
                       float dobandaAnuala,
                       const std::vector<int>& luniPlatite = {}) const;


};
