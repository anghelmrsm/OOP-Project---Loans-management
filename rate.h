///Includem Guard pentru includerea fisierului atat in main.cpp cat si in client.h
#ifndef RATE_H
#define RATE_H

class Rate
{
private:
    float nrLuna, valoareRata, partePrincipal, parteDobanda;
    bool platita;

    ///Functie pentru eliberarea memoriei
    void eliberare();

public:
    ///constructor initial
    Rate(const int nrLuna = 0,
         const float valoareRata = 0,
         const float partePrincipal = 0,
         const float parteDobanda = 0,
         const bool platita = false);

    ///constructor de copiere
    Rate (const Rate &sursa);

    ///Destructor
    ~Rate();

    ///Operator de asignare
    Rate& operator=(const Rate& rataNoua);

    ///Supraincarcare
    friend std::ostream &operator<<(std::ostream& COUT, const Rate &rata);

    ///Geter pentru platita
    bool isPlatita() const;

    ///Getter pentru platita
    float getValoareRata() const;

    ///modificam statusul platii
    void modicaPlata();

};

#endif
