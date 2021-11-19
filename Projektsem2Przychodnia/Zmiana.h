#ifndef PRZYCHODNIA_ZMIANA_H
#define PRZYCHODNIA_ZMIANA_H
#include "Dzien.h"

/// Klasa obrazuj�ca poszczeg�lne zmiany lekarza
class Zmiana {
public:
    Zmiana(Dzien dzien, unsigned short godzinaRozpoczecia, unsigned short godzinaZakonczenia);
    
    Dzien pobierzDzien();
    int pobierzGodzineRozpoczecia();
    int pobierzGodzineZakonczenia();

private:
    Dzien dzien; /**< Zmienna typu Dzien, kt�ra ma przechowywa� konktetnie dzie� tygodnia ze zmiany */
    unsigned short int godzinaRozpoczecia; /**< Zmienna typu int, kt�ra przechowuje godzine rozpocz�cia pracy lekarza dla danego dnia (zmiany)*/
    unsigned short int godzinaZakonczenia;/**< Zmienna typu int, kt�ra przechowuje godzine zako�cznia pracy lekarza dla danego dnia (zmiany)*/
};


#endif //PRZYCHODNIA_ZMIANA_H
