#ifndef PRZYCHODNIA_LEKARZ_H
#define PRZYCHODNIA_LEKARZ_H
#include <vector>
#include "Osoba.h"
#include "Zmiana.h"


/// Klasa, kt�ra dzieciczy z klasy Osoba, maj�ca za zadanie obrazowa� Lekarza w przychodni 

class Lekarz : Osoba {
public:
    Lekarz(const std::string &imie, const std::string &nazwisko, const std::string &numerTelefonu,
            int numerLekarza, const std::string &specjalizacja, const std::vector<Zmiana> &zmiany);

    std::string pobierzSpecjalizacje();
    std::string pobierzDaneOsoby();
    int pobierzNumerLekarza();

    Zmiana pobierzZmianeZDnia(std::string data);

    std::vector<Zmiana> pobierzZmiany(); 

private:
    std::string specjalizacja; /**< zmienna przechowuj�ca specjalizacj� lekarza */
    int numerLekarza; /**< zmienna przechowuj�ca numer lekarza */
    std::vector<Zmiana> zmiany; /**< wektor przechowyj�cy zmiany danego lekarza (grafik pracy danego lekarza) */
};


#endif //PRZYCHODNIA_LEKARZ_H
