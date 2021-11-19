#ifndef PRZYCHODNIA_WIZYTY_H
#define PRZYCHODNIA_WIZYTY_H
#include "Wizyta.h"

/// Klasa maj�ca symbolizowa� spis Wizyt np dla danego lekarza

class Wizyty {
public:
    Wizyty();

    std::vector<Wizyta> pobierzDlaDanegoLekarz(unsigned int numerLekarza);

    void dodaj(std::shared_ptr<Wizyta> wizytaPtr);

    std::vector<Wizyta> pobierzDlaDanegoPacjenta(std::string peselPacjenta);

    void usun(std::string data, std::string godzina);

    std::vector<Wizyta> pobierzWszystkieWizyty();

private:
    unsigned int wielkosc = 0; /**< zmienna przechowuj�ca wielko�� wektora wizyt */
    std::shared_ptr<Wizyta> pierwszaWizyta; /**< Inteligentny wska�nik na obiekt klasy Wizyta, ma wskazywa� na pierwsz� wizyt� */

};


#endif //PRZYCHODNIA_WIZYTY_H
