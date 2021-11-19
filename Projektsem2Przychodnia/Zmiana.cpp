#include "Zmiana.h"

//*KONSTRUKTOR*//
Zmiana::Zmiana(Dzien dzien, unsigned short godzinaRozpoczecia, unsigned short godzinaZakonczenia) : dzien(dzien),
                                                                                                    godzinaRozpoczecia(
                                                                                                            godzinaRozpoczecia),
                                                                                                    godzinaZakonczenia(
                                                                                                            godzinaZakonczenia) {}

/// Metoda odpowiedzialna za zwracanie zmiennej typu Dzieñ 
///
/// @returns dzien - zwraca dzien z danej zmiany
Dzien Zmiana::pobierzDzien() {
    return dzien;
}

/// Metoda odpowiedzialna za zwracanie godziny rozpoczêcia lekarza dla danej zmiany 
///
/// @returns godzinaRozpoczecia - zmienna typu int, godzina rozpoczêcia pracy przez lekarza
int Zmiana::pobierzGodzineRozpoczecia() {
    return godzinaRozpoczecia;
}

/// Metoda odpowiedzialna za zwracanie godziny zakoñczenia lekarza dla danej zmiany 
///
/// @returns godzinaZakonczenia - zmienna typu int, godzina zakoñczenia pracy przez lekarza
int Zmiana::pobierzGodzineZakonczenia() {
    return godzinaZakonczenia;
}
