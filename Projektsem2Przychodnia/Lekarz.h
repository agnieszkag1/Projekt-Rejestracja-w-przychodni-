#ifndef PRZYCHODNIA_LEKARZ_H
#define PRZYCHODNIA_LEKARZ_H
#include <vector>
#include "Osoba.h"
#include "Zmiana.h"


/// Klasa, która dzieciczy z klasy Osoba, mająca za zadanie obrazować Lekarza w przychodni 

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
    std::string specjalizacja; /**< zmienna przechowująca specjalizację lekarza */
    int numerLekarza; /**< zmienna przechowująca numer lekarza */
    std::vector<Zmiana> zmiany; /**< wektor przechowyjący zmiany danego lekarza (grafik pracy danego lekarza) */
};


#endif //PRZYCHODNIA_LEKARZ_H
