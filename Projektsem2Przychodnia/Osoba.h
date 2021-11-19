#ifndef PRZYCHODNIA_OSOBA_H
#define PRZYCHODNIA_OSOBA_H
#include "string"

/// Klasa opisuj¹ca osobê, podstawowe informacje personalne ka¿dego bywalca przychodni

class Osoba {
public:
    Osoba(std::string imie, std::string nazwisko, std::string numerTelefonu);

    virtual std::string pobierzDaneOsoby();
    std::string pobierzNazwisko();

private:
    std::string imie; /**< zmienna przechowuj¹ca imiê osoby */
    std::string nazwisko; /**< zmienna przechowuj¹ca nazwisko osoby */
    std::string numerTelefonu; /**< zmienna przechowuj¹ca numerTelefonu osoby */
};


#endif //PRZYCHODNIA_OSOBA_H
