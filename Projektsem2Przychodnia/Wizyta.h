#ifndef PRZYCHODNIA_WIZYTA_H
#define PRZYCHODNIA_WIZYTA_H
#include <string>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

/// Klasa maj�ca za zadanie obrazowanie pojedynczej wizyty.

class Wizyta {

    std::string peselPacjenta; /**< zmienna przechowuj�ca pesel pacjenta, kt�ry jest um�wiony na dan� wizyte */
    unsigned int numerLekrza; /**< zmienna przechowuj�ca numer lekarza, do kt�ego jest zapisany pacjent */
    std::string data; /**< zmienna przechowuj�ca dat� wizyty, na kt�r� jest um�wiony pacjent*/
    int godzina; /**< zmienna przechowuj�ca godzin� wizyty, na kt�r� jest um�wiony pacjent*/

public:
    //KONSTRUKTOR
    Wizyta(const std::string &peslPacjenta, unsigned int numerLekrza, const std::string &data,int godzina); 
    
    //ZMIENNE
    std::shared_ptr<Wizyta> kolejnaWizyta; /**< Inteligentny wska�nik na obiekt klasy Wizyta, ma wskazywa� na kolej� wizyt� jaka zosta�a wprowadzona do programu */

    // MEDOTY
    int pobierzNumerLekarza();
    std::string pobierzDate();
    std::string pobierzPeselPacjenta();
    int pobierzGodzine();
    bool czySieOdbyla();


};


#endif //PRZYCHODNIA_WIZYTA_H
