#ifndef PRZYCHODNIA_OSOBA_H
#define PRZYCHODNIA_OSOBA_H
#include "string"

/// Klasa opisuj�ca osob�, podstawowe informacje personalne ka�dego bywalca przychodni

class Osoba {
public:
    Osoba(std::string imie, std::string nazwisko, std::string numerTelefonu);

    virtual std::string pobierzDaneOsoby();
    std::string pobierzNazwisko();

private:
    std::string imie; /**< zmienna przechowuj�ca imi� osoby */
    std::string nazwisko; /**< zmienna przechowuj�ca nazwisko osoby */
    std::string numerTelefonu; /**< zmienna przechowuj�ca numerTelefonu osoby */
};


#endif //PRZYCHODNIA_OSOBA_H
