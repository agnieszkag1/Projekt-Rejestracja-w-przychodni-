#ifndef PRZYCHODNIA_ZMIANA_H
#define PRZYCHODNIA_ZMIANA_H
#include "Dzien.h"

/// Klasa obrazuj¹ca poszczególne zmiany lekarza
class Zmiana {
public:
    Zmiana(Dzien dzien, unsigned short godzinaRozpoczecia, unsigned short godzinaZakonczenia);
    
    Dzien pobierzDzien();
    int pobierzGodzineRozpoczecia();
    int pobierzGodzineZakonczenia();

private:
    Dzien dzien; /**< Zmienna typu Dzien, która ma przechowywaæ konktetnie dzieñ tygodnia ze zmiany */
    unsigned short int godzinaRozpoczecia; /**< Zmienna typu int, która przechowuje godzine rozpoczêcia pracy lekarza dla danego dnia (zmiany)*/
    unsigned short int godzinaZakonczenia;/**< Zmienna typu int, która przechowuje godzine zakoñcznia pracy lekarza dla danego dnia (zmiany)*/
};


#endif //PRZYCHODNIA_ZMIANA_H
