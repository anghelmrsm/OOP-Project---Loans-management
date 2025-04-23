📌 Sistem de Gestionare Clienți și Credite Bancare
🔍 Descriere Generală
Acest proiect implementează un sistem de gestionare a clienților și creditelor bancare, dezvoltat în C++ folosind principii de Programare Orientată pe Obiect (OOP).

Aplicația este organizată modular, oferind:

o arhitectură clară și extensibilă,

o separare logică riguroasă a componentelor,

funcționalități specifice pentru gestionarea împrumuturilor și a plăților lunare.

Funcționalitățile principale includ:

gestionarea unui portofoliu de clienți,

fiecare client poate deține unul sau mai multe credite,

fiecare credit este format din rate lunare, monitorizate individual.

🧱 Structura OOP
✅ Clasa Rate
Reprezintă o rată lunară dintr-un credit.

Atribute:

nrLuna – numărul lunii

valoareRata – suma totală a ratei

partePrincipal – componenta principală

parteDobanda – componenta dobândă

platita – statusul de plată

Funcționalități:

Constructori / Destructor

Getter: isPlatita(), getValoareRata()

modificaPlata() – marchează rata ca fiind plătită

Operator << suprascris pentru afișare

✅ Clasa Credit
Reprezintă un împrumut bancar.

Atribute:

dataPornire, dataSfarsit, perioada

sumaImprumutata, dobanda, soldRamas

vector<Rate> – lista ratelor asociate

Funcționalități:

Constructori / Destructor / Copiere / Asignare

Gettere: getDobanda(), getSumaImprumutata(), getPerioada()

primeleRatePlatite(int x) – verifică dacă primele x rate sunt achitate

Operator << suprascris pentru afișare

✅ Clasa Client
Gestionează informațiile personale ale clientului și creditele asociate.

Atribute:

nume, prenume, adresa, tel, varsta, vechime

char** denumiriCredite, int nrCredite

vector<Credit> – lista creditelor clientului

Funcționalități:

Constructori / Destructor / Copiere / Asignare

AddCredit(const char*, const Credit&) – adaugă un nou credit

DelCredit(const char*) – șterge un credit după denumire

getFullName() – returnează numele complet

getVechime(), setIncVechime(int)

AfisareDetaliiClient() – afișează informațiile clientului

Operator << suprascris

genereazaRate(...) – simulează ratele unui credit

🔧 Funcționalități Cheie
✔️ Adăugare, ștergere și afișare a creditelor

✔️ Simulare rate lunare (dobândă + principal + status plată)

✔️ Verificare plăți efectuate (ex. primele X luni)

✔️ Comasare credite (funcționalitate opțională)

✔️ Afișare detalii cu operatori suprascriși

✔️ Gestionare dinamică a denumirilor creditelor

✔️ Corectă eliberare a memoriei (deep copy, destructori)
