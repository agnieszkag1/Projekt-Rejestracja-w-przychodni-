#include "Zmiana.h"

//*KONSTRUKTOR*//
Zmiana::Zmiana(Dzien dzien, unsigned short godzinaRozpoczecia, unsigned short godzinaZakonczenia) : dzien(dzien),
                                                                                                    godzinaRozpoczecia(
                                                                                                            godzinaRozpoczecia),
                                                                                                    godzinaZakonczenia(
                                                                                                            godzinaZakonczenia) {}

/// Metoda odpowiedzialna za zwracanie zmiennej typu Dzień 
///
/// @returns dzien - zwraca dzien z danej zmiany
Dzien Zmiana::pobierzDzien() {
    return dzien;
}

/// Metoda odpowiedzialna za zwracanie godziny rozpoczęcia lekarza dla danej zmiany 
///
/// @returns godzinaRozpoczecia - zmienna typu int, godzina rozpoczęcia pracy przez lekarza
int Zmiana::pobierzGodzineRozpoczecia() {
    return godzinaRozpoczecia;
}

/// Metoda odpowiedzialna za zwracanie godziny zakończenia lekarza dla danej zmiany 
///
/// @returns godzinaZakonczenia - zmienna typu int, godzina zakończenia pracy przez lekarza
int Zmiana::pobierzGodzineZakonczenia() {
    return godzinaZakonczenia;
}
