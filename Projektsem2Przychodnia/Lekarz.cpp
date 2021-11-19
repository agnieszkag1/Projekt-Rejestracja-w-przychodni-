#include "Lekarz.h"

#include <utility>
#include <ctime>

/// Metoda odpowiedzialna za zwracanie stringa z�o�onego z wyraz�w
///
/// @returns retVal - zwraca string w tym przypadku zmienn� o nazwie retVal, kt�ra przechowuje dane lekarza
std::string Lekarz::pobierzDaneOsoby() {
    std::string retVal = Osoba::pobierzDaneOsoby();
    retVal += "Specializacja: " +  specjalizacja + "\n";
    retVal += "Numer lekarza: " +  std::to_string(numerLekarza) + "\n";

    return retVal;
}

/// Metoda odpowiedzialna za zwracanie stringa, kt�ry przechowuje specjalizacje lekarza
///
/// @returns specjalizacja - string, w kt�rym przechowana jest specjalizacja lekarza
std::string Lekarz::pobierzSpecjalizacje() {
    return specjalizacja;
}

/// Metoda odpowiedzialna za zwracanie zmiennej typu int, kt�ry przechowuje numer lekarza
///
/// @returns numerLekarza - int, w kt�rym przechowany jest numer lekarza
int Lekarz::pobierzNumerLekarza() {
    return numerLekarza;
}

/// Metoda odpowiedzialna za zwracanie zmiennej typu Zmiana
/// 
/// Metoda zraca zmian� lekarza z danego dnia (zmiana tj godziny pracy w danym dniu)
/// @param data - string, w kt�rym do metody podajemy dat�
/// @returns zwraca zmian� lekarza z danej daty
Zmiana Lekarz::pobierzZmianeZDnia(std::string data) {
    std::string dzien, miesiac, rok;
    dzien = data.substr(0, 2);
    miesiac = data.substr(3, 2);
    rok = data.substr(6, 4);

    std::tm tm{};
    tm.tm_mday = stoi(dzien);
    tm.tm_mon = stoi(miesiac);
    tm.tm_year = stoi(rok)-1900; //-1900 bo od tego roku liczymy czas i trzeba go odj�� �eby wart wy�a poprawna
    tm.tm_hour = 23;

    std::time_t timestamp = mktime(&tm);
    #pragma warning(suppress : 4996) //wyj�tek bo localtime 
    std::tm* formatedDate = std::localtime(&timestamp);
    Dzien dzienEnum = static_cast<Dzien>((formatedDate->tm_wday+3)%7); //rzutowanie na dzie� tygodnia, przesuni�te czwartek = 0 

    for (auto zmiana : zmiany) {
        if (dzienEnum == zmiana.pobierzDzien()) {
            return zmiana;
        }
    }

    return Zmiana(Wolne, 0, 0);
}

/// Metoda odpowiedzialna za zwracanie zmian (godzin pracy z dniami) danego lekarza
///
/// @returns zmiany - wektor zmian danego lekarza
std::vector<Zmiana> Lekarz::pobierzZmiany() {
    return zmiany;
}

//**KONSTRUKTOR**//
Lekarz::Lekarz(const std::string &imie, const std::string &nazwisko, const std::string &numerTelefonu, 
    int numerLekarza, const std::string &specjalizacja, const std::vector<Zmiana> &zmiany) : Osoba (imie, nazwisko,numerTelefonu),
    specjalizacja(specjalizacja),numerLekarza(numerLekarza),zmiany(zmiany) {}



