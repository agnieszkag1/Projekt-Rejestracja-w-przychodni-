#include "Osoba.h"
#include <utility>

///Metoda, kt�ra ma za zadanie zwr�ci� dane osoby 
/// 
/// Metoda, kt�ra ��czy poszczeg�lne stringi w jeden - imi�, nazwisko oraz numer telefonu
///@returns Metoda zwraca string, kt�ry zawiera imie, nazwisko oraz numer telefonu osoby
std::string Osoba::pobierzDaneOsoby() {
    std::string retVal; //**< Zmienna, w kt�rej sumowane s� poszczeg�lne stringi - dane osoby*/
    retVal += "Imie: " + imie + "\n";
    retVal += "Nazwisko: " + nazwisko + "\n";
    retVal += "Numer telefonu: " + numerTelefonu + "\n";

    return retVal;
}

Osoba::Osoba(std::string imie,std::string nazwisko,std::string numerTelefonu) : imie(std::move(imie)),nazwisko(std::move(nazwisko)), numerTelefonu(std::move(numerTelefonu)) {}

///Metoda, kt�ra ma za zadanie zwr�ci� zmienn� nazwisko z klasy Osoba
/// 
///@returns Zwraca zmienn� typu string - nazwisko z klasy Osoba
std::string Osoba::pobierzNazwisko() {
    return nazwisko;
}
