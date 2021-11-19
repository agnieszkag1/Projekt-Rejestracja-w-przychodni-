#include "Pacjent.h"

#include <utility>
/// Metoda odpowiedzialna za zwracanie stringa z�o�onego z wyraz�w
///
/// @returns zwraca string w tym przypadku zmienn� o nazwie retVal, kt�ra przechowuje dane pacjenta
std::string Pacjent::pobierzDaneOsoby() {
    std::string retVal = Osoba::pobierzDaneOsoby();
    retVal += "PESEL: " + pesel;

    return retVal;
}

//**KONSTRUKTOR**//
Pacjent::Pacjent(const std::string &imie, const std::string &nazwisko, const std::string &numerTelefonu,
                 const std::string &pesl, const std::string &dataUrodzenia) : Osoba(imie, nazwisko, numerTelefonu),
                                                                              pesel(pesl),
                                                                              dataUrodzenia(dataUrodzenia) {}
/// Metoda odpowiedzialna za zwracanie stringa, kt�ry przechowuje numer pesel pacjenta
///
/// @returns pesel - string, w kt�rym przechowany jest numer pesel pacjenta
std::string Pacjent::pobierzPesel() {
    return pesel;
}

