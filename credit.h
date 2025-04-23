///Includem Guard pentru includerea fisierului atat in main.cpp cat si in client.h
#ifndef CREDIT_H
#define CREDIT_H

#include <vector>
#include "rate.h"

class Credit
{
private:
    char *dataPornire,*dataSfarsit;
    int perioada, sumaImprumutata, dobanda, soldRamas;
    std::vector <Rate> vectorRate;

    ///Functie pentru alocare si copiere siruri de carctere
    char* AlocCpyString(const char* sursa);

    ///Functie pentru eliberarea memoriei
    void eliberare();
public:

    ///constructor initial
    Credit(const char *dataPornire = nullptr,
           const char *dataSfarsit = nullptr,
           const int perioada = 0,
           const float sumaImprumutata = 0,
           const float dobanda = 0,
           const float soldRamas = 0,
           const std::vector <Rate> &vectorRate = {});

    ///constructor de copiere
    Credit (const Credit &sursa);

    ///Destructor
    ~Credit();

    ///Operator de asignare
    Credit& operator=(const Credit& creditNou);

    ///Supraincarcare
    friend std::ostream &operator<<(std::ostream& COUT, const Credit &credit);

    ///Getter pentru dobanda
    float getDobanda() const;

    ///Getter pentru suma imprumutata
    float getSumaImprumutata() const;

    ///Getter pentru perioada
    int getPerioada() const;

    ///verificam sa avem rate platite
    void primeleRatePlatite() const;
};



#endif
