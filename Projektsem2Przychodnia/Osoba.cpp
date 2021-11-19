#include "Osoba.h"
#include <utility>

///Metoda, która ma za zadanie zwróciæ dane osoby 
/// 
/// Metoda, która ³¹czy poszczególne stringi w jeden - imiê, nazwisko oraz numer telefonu
///@returns Metoda zwraca string, który zawiera imie, nazwisko oraz numer telefonu osoby
std::string Osoba::pobierzDaneOsoby() {
    std::string retVal; //**< Zmienna, w której sumowane s¹ poszczególne stringi - dane osoby*/
    retVal += "Imie: " + imie + "\n";
    retVal += "Nazwisko: " + nazwisko + "\n";
    retVal += "Numer telefonu: " + numerTelefonu + "\n";

    return retVal;
}

Osoba::Osoba(std::string imie,std::string nazwisko,std::string numerTelefonu) : imie(std::move(imie)),nazwisko(std::move(nazwisko)), numerTelefonu(std::move(numerTelefonu)) {}

///Metoda, która ma za zadanie zwróciæ zmienn¹ nazwisko z klasy Osoba
/// 
///@returns Zwraca zmienn¹ typu string - nazwisko z klasy Osoba
std::string Osoba::pobierzNazwisko() {
    return nazwisko;
}
