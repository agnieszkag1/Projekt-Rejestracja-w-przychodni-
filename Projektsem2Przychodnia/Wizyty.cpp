#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include "Wizyty.h"

//*KONSTRUKTOR*//
Wizyty::Wizyty() {
    std::fstream plik;
    std::string linia;
    plik.open("wizyty.txt", std::ios::in);

    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE";
        exit(0);
    }

    std::string peselPacjenta, data;
    unsigned int numerLekarza;
    int godzina;
    std::shared_ptr<Wizyta> poprzedniaWizyta = nullptr;
    while(plik >> peselPacjenta >> numerLekarza >> data >> godzina) {
        auto wizyta = std::make_shared<Wizyta>(peselPacjenta, numerLekarza, data, godzina);
        if (poprzedniaWizyta) {
            poprzedniaWizyta->kolejnaWizyta = std::move(wizyta);
        }

        if (pierwszaWizyta == nullptr) {
            pierwszaWizyta = std::move(wizyta);
        }
        wielkosc++;
    }
}

/// Metoda odpowiedzialna za zwrócenie wizyt danego lekarza
///
/// @returns wizyty - zwraca wektor wizyt danego lekarza 
std::vector<Wizyta> Wizyty::pobierzDlaDanegoLekarz(unsigned int numerLekarza) {
    auto wizyty = std::vector<Wizyta>();

    auto wizytaPtr = pierwszaWizyta;
    while(wizytaPtr) {
        if (wizytaPtr->pobierzNumerLekarza() == numerLekarza) {
            wizyty.push_back(*wizytaPtr); // Odwskaznikowanie, urzycie instacji zamiast wskaznika
        }
        wizytaPtr = wizytaPtr->kolejnaWizyta;
    }

    return wizyty;
}

/// Metoda służąca do doawania wizyt do wektora wizyt
/// @param wizytaPtr - wskaźnik na wizytę, którą dodajemy do pamięci
void Wizyty::dodaj(std::shared_ptr<Wizyta> wizytaPtr) {
    auto wizyta = pierwszaWizyta;
    if (wizyta == nullptr) {
        pierwszaWizyta = wizytaPtr;
        return;
    }
    while(wizyta && wizyta->kolejnaWizyta) {
        wizyta = wizyta->kolejnaWizyta;
    }
    wizyta->kolejnaWizyta = std::move(wizytaPtr); // https://en.cppreference.com/w/cpp/utility/move //
}

/// Metoda odpowiedzialna za zwrócenie wizyt danego pacjenta
///
/// @returns wizyty - zwraca wektor wizyt danego pacjenta
std::vector<Wizyta> Wizyty::pobierzDlaDanegoPacjenta(std::string peselPacjenta) {
    auto wizyty = std::vector<Wizyta>();

    auto wizytaPtr = pierwszaWizyta;
    while(wizytaPtr) {
        if (wizytaPtr->pobierzPeselPacjenta() == peselPacjenta) {
            wizyty.push_back(*wizytaPtr); // Odwskaznikowanie, urzycie instacji zamiast wskaznika
        }
        wizytaPtr = wizytaPtr->kolejnaWizyta;
    }

    return wizyty;
}

/// Metoda służąca do usuwania konkretnej wizyty z wektora wizyt
/// @param data - zmienna typu string, za pomocą której podajemy datę wizyty
/// @param godzina - zmienna typu int, za pomocą której podajemy godzinę wizyty
void Wizyty::usun(std::string data, std::string godzina) {
    auto wizytaPtr = pierwszaWizyta;
    std::shared_ptr<Wizyta> poprzedniaWizyta;

    while(wizytaPtr) {
        if (wizytaPtr->pobierzDate() == data && wizytaPtr->pobierzGodzine() == stoi(godzina)) {
            if (wizytaPtr == pierwszaWizyta) {
                pierwszaWizyta = wizytaPtr->kolejnaWizyta;
            } else {
                auto kolejnaWizyta = wizytaPtr->kolejnaWizyta;
                poprzedniaWizyta->kolejnaWizyta = kolejnaWizyta;
            }
        }
        poprzedniaWizyta = wizytaPtr;
        wizytaPtr = wizytaPtr->kolejnaWizyta;
    }
}

///Metoda która zwraca wszystkie wizyty jakie istnieją
///@returns wizyty - zwraca wektor wszystkich wizyt
std::vector<Wizyta> Wizyty::pobierzWszystkieWizyty() {
    auto wizyty = std::vector<Wizyta>();

    auto wizytaPtr = pierwszaWizyta;
    while(wizytaPtr) {
        wizyty.push_back(*wizytaPtr); // Odwskaznikowanie, urzycie instacji zamiast wskaznika
        wizytaPtr = wizytaPtr->kolejnaWizyta;
    }

    return wizyty;
}
