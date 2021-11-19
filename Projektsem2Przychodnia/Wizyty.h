#ifndef PRZYCHODNIA_WIZYTY_H
#define PRZYCHODNIA_WIZYTY_H
#include "Wizyta.h"

/// Klasa maj¹ca symbolizowaæ spis Wizyt np dla danego lekarza

class Wizyty {
public:
    Wizyty();

    std::vector<Wizyta> pobierzDlaDanegoLekarz(unsigned int numerLekarza);

    void dodaj(std::shared_ptr<Wizyta> wizytaPtr);

    std::vector<Wizyta> pobierzDlaDanegoPacjenta(std::string peselPacjenta);

    void usun(std::string data, std::string godzina);

    std::vector<Wizyta> pobierzWszystkieWizyty();

private:
    unsigned int wielkosc = 0; /**< zmienna przechowuj¹ca wielkoœæ wektora wizyt */
    std::shared_ptr<Wizyta> pierwszaWizyta; /**< Inteligentny wskaŸnik na obiekt klasy Wizyta, ma wskazywaæ na pierwsz¹ wizytê */

};


#endif //PRZYCHODNIA_WIZYTY_H
