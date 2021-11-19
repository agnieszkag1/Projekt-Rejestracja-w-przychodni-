#ifndef PRZYCHODNIA_KONSOLA_H
#define PRZYCHODNIA_KONSOLA_H
#include <vector>
#include "Lekarz.h"
#include "Pacjent.h"
#include "Wizyty.h"

/// Klasa ta jest odpowiedzialna za komunikacj� z u�ytkownikiem oraz wy�wietlanie danych w konsoli i za wczytanie danych. 
class Konsola {
public:
    void start();

private:
    void wczytajPacjentow();
    void wczytajLekarzy();
    void logowanie();
    bool czyPoprawnyPesel(std::string PESEL);
    bool czyPoprawnaData(std::string data);
    bool czyPoprawnaNazwa(std::string nazwa);
    bool czyPoprawnyNumer(std::string numer);
    bool czyZPrzeszlosci(std::string data, int godzina = 0);
    void SzukajLekarza();
    void zapiszSie(Lekarz lekarz);
    void SprawdzWizyty();
    void WyswietlGrafikIDane();
    void WyszukiwanieLekrza();
    static bool funkcja_sort(Zmiana a, Zmiana b);


    // Zakladamy ze pacjent istnieje w spsie (wgrywamy spis, wi�c je�li pacjent tam jest to go znajdzie)
    Pacjent znajdzPacjentaPoPesel(std::string pesel);

    std::vector<Lekarz> lekarze; /**< Zmienna typu wektor przechowuj�ca spis lekarzy z danej przychodni (w wektorze znajduj� si� obiekty klasy Lekarz) */
    std::vector<Pacjent> spisPacjentow; /**< Zmienna typu wektor przechowuj�ca spis pacjent�w z danej przychodni (w wektorze znajduj� si� obiekty klasy Pacjent) */
    Wizyty wizyty; /**< Zmienna obrazuj�ca spis wizyt */
    std::unique_ptr<Pacjent> uzytkownikPtr; /**< Inteligenty wska�nik na obiekt klasy Pacjent */

    void SprawdzProfil();

    Lekarz znajdzLekarzaPoNumerzeLekarza(unsigned int lekarza);

    void ZapiszWizytyDoPliku();

    void zapiszDanePacjenta(std::string imie, std::string nazwisko, std::string PESEL, std::string DataUrodzenia,
                            std::string numerTelefonu);
};


#endif //PRZYCHODNIA_KONSOLA_H
