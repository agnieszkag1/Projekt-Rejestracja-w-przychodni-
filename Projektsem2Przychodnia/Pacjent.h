#ifndef PRZYCHODNIA_PACJENT_H
#define PRZYCHODNIA_PACJENT_H
#include "Osoba.h"
#include "chrono"

/// Klasa, kt�ra dziedziczy z klasy Osoba, maj�ca za zadanie obrazowa� Pacjenta w przychodni 

class Pacjent : public Osoba {
public:

    Pacjent(const std::string &imie, const std::string &nazwisko, const std::string &numerTelefonu,
            const std::string &pesl, const std::string &dataUrodzenia);

    std::string pobierzDaneOsoby(); 
    std::string pobierzPesel();

private:
    std::string pesel; /**< zmienna przechowuj�ca pesel pacjenta */
    std::string dataUrodzenia; /**< zmienna przechowuj�ca dat� urodzenia pacjenta */
    
//TODO time

};


#endif //PRZYCHODNIA_PACJENT_H
