#include "Pacjent.h"

#include <utility>
/// Metoda odpowiedzialna za zwracanie stringa z³o¿onego z wyrazów
///
/// @returns zwraca string w tym przypadku zmienn¹ o nazwie retVal, która przechowuje dane pacjenta
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
/// Metoda odpowiedzialna za zwracanie stringa, który przechowuje numer pesel pacjenta
///
/// @returns pesel - string, w którym przechowany jest numer pesel pacjenta
std::string Pacjent::pobierzPesel() {
    return pesel;
}

