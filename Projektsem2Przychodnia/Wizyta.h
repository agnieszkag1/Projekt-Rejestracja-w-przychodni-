#ifndef PRZYCHODNIA_WIZYTA_H
#define PRZYCHODNIA_WIZYTA_H
#include <string>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

/// Klasa maj¹ca za zadanie obrazowanie pojedynczej wizyty.

class Wizyta {

    std::string peselPacjenta; /**< zmienna przechowuj¹ca pesel pacjenta, który jest umówiony na dan¹ wizyte */
    unsigned int numerLekrza; /**< zmienna przechowuj¹ca numer lekarza, do któego jest zapisany pacjent */
    std::string data; /**< zmienna przechowuj¹ca datê wizyty, na któr¹ jest umówiony pacjent*/
    int godzina; /**< zmienna przechowuj¹ca godzinê wizyty, na któr¹ jest umówiony pacjent*/

public:
    //KONSTRUKTOR
    Wizyta(const std::string &peslPacjenta, unsigned int numerLekrza, const std::string &data,int godzina); 
    
    //ZMIENNE
    std::shared_ptr<Wizyta> kolejnaWizyta; /**< Inteligentny wskaŸnik na obiekt klasy Wizyta, ma wskazywaæ na kolej¹ wizytê jaka zosta³a wprowadzona do programu */

    // MEDOTY
    int pobierzNumerLekarza();
    std::string pobierzDate();
    std::string pobierzPeselPacjenta();
    int pobierzGodzine();
    bool czySieOdbyla();


};


#endif //PRZYCHODNIA_WIZYTA_H
