#include "Wizyta.h"

#include <utility>
#include "chrono"

//**KONSTRUKTOR**//
Wizyta::Wizyta(const std::string &peslPacjenta, unsigned int numerLekrza, const std::string &data,
               int godzina) : peselPacjenta(peslPacjenta), numerLekrza(numerLekrza), data(data),
                                             godzina(godzina) {}

/// Metoda odpowiedzialna za zwracanie stringa, który przechowuje date wizyty
///
/// @returns daya - string, w którym przechowana jest data wizyty
std::string Wizyta::pobierzDate() {
    return data;
}

/// Metoda odpowiedzialna za zwracanie zmiennej typu int, który przechowuje godzine wizyty
///
/// @returns godzina - int, w którym przechowana jest godzina
int Wizyta::pobierzGodzine() {
    return godzina;
}

/// Metoda odpowiedzialna za zwracanie stringa, który przechowuje numer pesel pacjenta zapisanego na dan¹ wizytê
///
/// @returns peselPacjenta - zmienna typu string przechowuj¹ca pesel pacjenta zapisanego na dan¹ wizytê
std::string Wizyta::pobierzPeselPacjenta() {
    return peselPacjenta;
}

/// Metoda odpowiedzialna za zwracanie zmiennej typu int, który przechowuje numer lekarza
///
/// @returns godzina - int, w którym przechowany jest numer lekarza
int Wizyta::pobierzNumerLekarza() {
    return numerLekrza;
}

/// Metoda odpowiedzialna za sprawdzanie czy dana wizyta ju¿ mia³a miejsce
///
/// @returns true jeœli wizyta jest z przesz³oœci lub false, jeœli wizyta siê jeszcze nie odby³a i jest zaplanowana
bool Wizyta::czySieOdbyla() {
    auto teraz = std::chrono::system_clock::now(); // pobiera aktualny czas z komputera
    auto terazWTimeT = std::chrono::system_clock::to_time_t(teraz); //przeniesienie do time t

    std::string dzien, miesiac, rok;
    dzien = data.substr(0, 2);
    miesiac = data.substr(3, 2);
    rok = data.substr(6, 4);

    std::tm tm{};
    tm.tm_mday = stoi(dzien); // stoi - string to int
    tm.tm_mon = stoi(miesiac);
    tm.tm_year = stoi(rok);
    tm.tm_hour = godzina;

    std::time_t czasWizyty = mktime(&tm);

    return std::difftime(terazWTimeT, czasWizyty) > 0;
}
