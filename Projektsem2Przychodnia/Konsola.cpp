#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "string"
#include "Konsola.h"


///Metoda, która  wyświetla główne menu programu i przekierowywuje użytkownika do konkretnych funkcji programu, 
///poza tym metoda ta wywołuje funkcje odpowiedzialne za wczytywnie danych z pliku (pacjentów, lekarzy oraz wizyt).
/// 
void Konsola::start() {

    wczytajPacjentow();
    wczytajLekarzy();
    logowanie();

    while (true) {
        unsigned short int wybor = 0;
        std::cout << std::endl;
        std::cout << "Zalogowano, wybierz co chcesz zrobic. Aby wybrac opcje wybierz numer jej odpowiadajacy" << std::endl;
        std::cout << "1. Wybor lekarza oraz zapisywaine sie na wizyte" << std::endl;
        std::cout << "2. Wyswietl grafik (godziny pracy) wybranego lekarza" << std::endl;
        std::cout << "3. Sprawdz swoje dane" << std::endl;
        std::cout << "4. Sprawdz umowione wizyty" << std::endl;
        std::cout << "5. Wyloguj" << std::endl;
        std::cout << "6. Zamknij" << std::endl;
        std::cin >> wybor;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");

        switch (wybor) {
            case 1:
                system("cls");
                SzukajLekarza();
                break;
            case 2:
                system("cls");
                WyswietlGrafikIDane();
                break;
            case 3:
                system("cls");
                SprawdzProfil();
                break;
            case 4:
                system("cls");
                SprawdzWizyty();

                break;
            case 5:
                system("cls");
                uzytkownikPtr = nullptr;
                start();
                return;
            case 6:
                system("cls");
                ZapiszWizytyDoPliku();
                return;
        }

    }
}

/// Metoda odpowiedzialna za logowanie do systemu za pomocą numeru Pesel. Oraz ewentualną rejestrację nowych użytkowników.
/// 
void Konsola::logowanie() {
    std::cout << "WITAJ W PROGRAMIE DO REJESTRACJI WIZYT LEKARSKICH, ABY ROZPOCZAC PODAJ SWOJ NUMER PESEL" << std::endl << std::endl;
    std::string pesel;
    do {

        std::cout <<"Upewnij sie, ze podajesz POPRAWNE dane, pesel sklada sie z 11 CYFR, NIE ZAWIERA znakow specjalych, zawiera TYLKO CYFRY od 0 do 9" <<std::endl<<std::endl<< "Podaj PESEL:" << std::endl;
        std::cin >> pesel;
        system("cls");

    } while(!czyPoprawnyPesel(pesel));

    //sprawdzenie czy pacjent znajduje się w bazie pacjentów, czy będzie trzeba stowrzyć nowe konto
    for (auto pacjent : spisPacjentow) {
        if (pacjent.pobierzPesel() == pesel) {
            uzytkownikPtr = std::make_unique<Pacjent>(pacjent); // jeśli pacjent jest w bazie to adres tego pacjenta przypisujemy do wskaźnika
        }
    }

    if (uzytkownikPtr == nullptr) { // jeśli użytkownik nie istnieje jeszcze w bazie
        std::cout << "WITAJ W REJESTRACJI" << std::endl << std:: endl;
        std::cout << " Jeszcze nie posiadasz konta w naszym systemie, zaraz zajmiemy sie zalozeniem go, podaj dane zgodnie z instrukcjami wyswietlanymi w konsoli";
        std::cout << " Nie zapomnij sprawdzić poprawnosci danych przed wpisaniem. Zaczynamy!" << std::endl << std::endl;

        std::string imie, nazwisko, DataUrodzenia, numerTelefonu;
        do {
            std::cout << "Imie: " << std::endl;
            std::cin >> imie;
            std::cout << std::endl;
            system("cls");
        } while (!czyPoprawnaNazwa(imie));

        do {
        std::cout << "Nazwisko" << std::endl;
        std::cin >> nazwisko;
        std::cout << std::endl;
        system("cls");
        } while (!czyPoprawnaNazwa(nazwisko));

        do {
            std::cout << "Data urodzenia: (format daty: dd.mm.rrrr) " << std::endl;
            std::cin >> DataUrodzenia;
            std::cout << std::endl;
            system("cls");
        } while (!czyPoprawnaData(DataUrodzenia));
      
        do {
            std::cout << "Numer telefonu (przyklad: 739234920)" << std::endl;
            std::cin >> numerTelefonu;
            std::cout << std::endl;
            system("cls");
        } while (!czyPoprawnyNumer(numerTelefonu));

        Pacjent nowyPacjent{imie, nazwisko, numerTelefonu, pesel, DataUrodzenia};
        spisPacjentow.push_back(nowyPacjent);
        uzytkownikPtr = std::make_unique<Pacjent>(nowyPacjent); // adres nowego pacjenta przypisujemy pod wskaźnik
        zapiszDanePacjenta(imie, nazwisko, pesel, DataUrodzenia, numerTelefonu); //wpisuje do pliku nowego pacjenta
    }
}

/// Metoda odpowiedzialna za sprawdzanie czy w podanym stringu na pewno znajdują się same litery
///
/// @param nazwa ciąg znaków do sprawdzenia
/// @returns zwraca wartość true jeśli ciąg znaków zawiera tylko litery, zwraca wartość false, jesli ciąg znaków zawiera nie tylko litery
bool Konsola::czyPoprawnaNazwa(std::string nazwa) {
    for (char znak : nazwa) {
        if (znak < 48 || znak > 57) return true;

        return false;
    }
}


/// Metoda odpowiedzialna za sprawdzanie czy data została podana w poprawny sposób
///
/// @param data - ciąg znaków do sprawdzenia
/// @returns zwraca wartość true jeśli data została podana poprawie tj dd.mm.rrrr, zwraca wartość false, jeśli data została podana niepoprawie
bool Konsola::czyPoprawnaData(std::string data){
    

    if (data.size() == 10 && data[2] == '.' && data[5] == '.')
    {
        if (isdigit(data[0]) && isdigit(data[1]) && isdigit(data[3]) && isdigit(data[4]) && isdigit(data[6]) && isdigit(data[7]) && isdigit(data[8]) && isdigit(data[9]))
        {
 
            if ((data[0]=='1' || data[0] =='0' || data[0] =='2' || data[0]=='3') &&
                (data[3] == '0' || data[3] == '1')&&
                (data[6]=='1' || data[6]=='2'))
            {
                return true;
            }
            else return false;
        }

    }

    return false;
  
}

/// Metoda odpowiedzialna za sprawdzanie czy w podanym stringu (numerze telefonu) na pewno znajdują się same cyfry oraz czy ciąg składa się z 9 cyfr
///
/// @param numer - ciąg znaków do sprawdzenia
/// @returns zwraca wartość true jeśli ciąg znaków zawiera tylko cyfry oraz jest długości 9, zwraca wartość false, jesli ciąg znaków nie spełnia któregoś z warunków
bool Konsola::czyPoprawnyNumer(std::string numer) {

    if (numer.size() == 9 && isdigit(numer[0]) && isdigit(numer[1]) && isdigit(numer[2]) && isdigit(numer[3]) && isdigit(numer[4]) && isdigit(numer[5]) && isdigit(numer[6]) && isdigit(numer[7]) && isdigit(numer[8])) {
        return true;
    }
else return false;

}

/// Metoda odpowiedzialna za sprawdzanie czy podany sting (Pesel) został wprowadzony poprawnie tj, czy spełnia założenia sumy kontrolnej (ustalonej odgórnie) oraz czy ma 11 cyfr
///
/// @param PESEL - ciąg znaków do sprawdzenia
/// @returns zwraca wartość true jeśli ciąg znaków spełnia warunki, w przeciwnym razie zwraca wartość false
bool Konsola::czyPoprawnyPesel(std::string PESEL) {
    if (PESEL.length() != 11)return false;
    int suma_kontrolna = (PESEL[0] - '0');
    suma_kontrolna += (PESEL[1] - '0') * 3 % 10;
    suma_kontrolna += (PESEL[2] - '0') * 7 % 10;
    suma_kontrolna += (PESEL[3] - '0') * 9 % 10;
    suma_kontrolna += PESEL[4] - '0';
    suma_kontrolna += (PESEL[5] - '0') * 3 % 10;
    suma_kontrolna += (PESEL[6] - '0') * 7 % 10;
    suma_kontrolna += (PESEL[7] - '0') * 9 % 10;
    suma_kontrolna += PESEL[8] - '0';
    suma_kontrolna += (PESEL[9] - '0') * 3 % 10;
    suma_kontrolna = suma_kontrolna % 10;
    suma_kontrolna = 10 - suma_kontrolna;
    if (suma_kontrolna != PESEL[10]-'0')return false;
    return true;
}

/// Metoda odpowiedzialna za wczytywanie danych z pliku
///
/// Metoda wczytuje pacjentów z pliku tekstowego o nazwie "pacjenci_dane.txt", sprawdza ich poprawność i poprawne umieszcza w wektorze pacjentów (spisie pacjentów). 
/// Po zakończeniu działań zamyka plik
void Konsola::wczytajPacjentow() {
    std::fstream plik;
    std::string linia;
    plik.open("pacjenci_dane.txt", std::ios::in);

    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE";
        exit(0);
    }

    std::string imie, nazwisko, PESEL, DataUrodzenia, numerTelefonu;
    while (plik >> imie >> nazwisko >> PESEL >> DataUrodzenia >> numerTelefonu) {
        if (czyPoprawnaNazwa(imie) == true && czyPoprawnaNazwa(nazwisko) == true && czyPoprawnyPesel(PESEL) == true && czyPoprawnaData(DataUrodzenia) == true && czyPoprawnyNumer(numerTelefonu) == true) {
            Pacjent pacjent{ imie, nazwisko, numerTelefonu, PESEL, DataUrodzenia };
            spisPacjentow.push_back(pacjent);
        }
    }

    plik.close();
}

/// Metoda odpowiedzialna za wczytywanie danych z pliku
///
/// Metoda wczytujelekarzy oraz ich godziny pracy (swego rodzaju grafik pracy na dane dni tygodnia) z pliku tekstowego o nazwie "lekarze_dane.txt", sprawdza ich poprawność i poprawne umieszcza w wektorze pacjentów (spisie lekarzy). 
/// Po zakończeniu działań zamyka plik
void Konsola::wczytajLekarzy() {
    std::fstream plik;
    std::string linia;
    plik.open("lekarze_dane.txt", std::ios::in);

    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE";
        exit(0);
    }

    std::string imie, nazwisko, numerTelefonu, specjializacja;
    int numerLekarza;
    while (plik >> imie >> nazwisko >> numerTelefonu >> numerLekarza >> specjializacja) {
        if (czyPoprawnaNazwa(imie) == true && czyPoprawnaNazwa(nazwisko) == true && czyPoprawnyNumer(numerTelefonu) == true && czyPoprawnaNazwa(specjializacja) == true)
        {
            int dzienTygodnia, godzinaRozpoczecia, godzinaZakonczenia;

            std::vector<Zmiana> zmiany;

        //teraz pobiera godziny pracy
            for (int i = 0; i < 7; i++) {
                plik >> dzienTygodnia >> godzinaRozpoczecia >> godzinaZakonczenia;
                if (godzinaRozpoczecia == 0 && godzinaZakonczenia == 0) {
                    dzienTygodnia = Wolne;
                }
                else {
                    dzienTygodnia = dzienTygodnia-1;
                }
                zmiany.push_back(Zmiana(static_cast<Dzien>(dzienTygodnia), godzinaRozpoczecia, godzinaZakonczenia)); // static_cast - rzutowanie na typ Dzien
            }
            lekarze.push_back(Lekarz(imie, nazwisko, numerTelefonu, numerLekarza, specjializacja, zmiany));
        }
    }

    plik.close();
}

/// Metoda odpowiedzialna za wczytywanie wizyt z pliku tekstowego
///
/// Metoda wczytuje wizyty z pliku tekstowego o nazwie "wizyty.txt", sprawdza ich poprawność i umieszcza je w wektorze wizyt. 
/// Po zakończeniu działań zamyka plik
void Konsola::ZapiszWizytyDoPliku() {
    std::ofstream plik;
    std::string linia;
    plik.open("wizyty.txt", std::ios::trunc);

    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE";
        exit(0);
    }

    std::vector<Wizyta> wszystkieWizyty = wizyty.pobierzWszystkieWizyty();
    for (auto wizyta : wszystkieWizyty) {
        plik << wizyta.pobierzPeselPacjenta() << " " << wizyta.pobierzNumerLekarza() << " " << wizyta.pobierzDate() << " " << wizyta.pobierzGodzine() << std::endl;
    }
}

/// Metoda odpowiedzialna za wyszukiwanie lekarza
///
/// Użytkownik jest pytany o to, do którego lekarza chce się zapiać, metoda przeszukuje listę lekarzy i jeśli lekarz istnieje oraz 
/// pacjent chce się zapisać to wywoałana zostaje metoda void zapiszSie()
void Konsola::SzukajLekarza() {
    
    std::cout << "Jakiego specjalisty szukasz?" << std::endl;
    std::string specjalizacja;
    std::cout << "Nazwa specjializacji: " << std::endl;
    std::cin >> specjalizacja;
    system("cls");

    bool czyIstniejeDanaSpecjalizacja = false;

    for (auto lekarz : lekarze) {
        if (lekarz.pobierzSpecjalizacje() == specjalizacja) {
            std::cout << lekarz.pobierzDaneOsoby() << std::endl;
            czyIstniejeDanaSpecjalizacja = true;
        }
    }

    if (!czyIstniejeDanaSpecjalizacja) {
        std::cout << "Przykro nam, lekrze nie posiadaja zadanej specjalizacji" << std::endl;
        return;
    }
  
    std::cout << "Czy chcesz sie zapisac do lekarza? jesli tak podaj jego numer, jesli nie to wpisz 0" << std::endl;
    int numerLekarza = 0;
    std::cin >> numerLekarza;
    system("cls");
    if (numerLekarza == 0) {
        system("cls");
        return;
    }

    for (auto lekarz : lekarze) {
        if (lekarz.pobierzNumerLekarza() == numerLekarza) {
            zapiszSie(lekarz);
            system("cls");
            std::cout << "ZAPISANO NA WIZYTE" << std::endl;
            return;
        }
    }
    std::cout << "NIE ZNALEZIONO LEKARZA Z PODANYM NUMEREM" << std::endl;
}

/// Metoda odpowiedzialna za sprawdzanie czy data wraz z godziną nie jest z przeszłości (tj. czy na pewno wyprzedza czas pobrany z komputera)
///
/// @param data - zmienna typu sting, która przechowuje datę
/// @param godzina - zmienna typu int, która przechowuje godzinę
/// @returns zwraca true jeśli data jest z przeszłości lub zwraca false jeśli data jest z przyszłości
bool Konsola::czyZPrzeszlosci(std::string data, int godzina) {
    auto teraz = std::chrono::system_clock::now(); // pobiera aktualny czas z komputera
    auto terazWTimeT = std::chrono::system_clock::to_time_t(teraz); //zmiana aktualnego czasu na time t // https://en.cppreference.com/w/cpp/chrono/c/tm //

    std::string dzien, miesiac, rok; // wyciąganie z daty konkternych liczb
    dzien = data.substr(0, 2);
    miesiac = data.substr(3, 2);
    rok = data.substr(6, 4);

    std::tm tm{};
    tm.tm_mday = stoi(dzien); // stoi - string to int
    tm.tm_mon = stoi(miesiac);
    tm.tm_year = stoi(rok);
    tm.tm_hour = godzina;

    std::time_t czasWizyty = mktime(&tm); // https://www.cplusplus.com/reference/ctime/time/ //

    return std::difftime(terazWTimeT, czasWizyty) > 0; // jeśli rónica jest większa niż 0 to prawda, czyli jeśli data jest z przeszłości to prawda

}

/// Metoda odpowiedzialna za zapisywanie pacjentów na wizyty
/// 
/// @param lekarz - zmienna typu lekarz, metoda przyjmuje lekarza, do którego chce się zapisać dany pacjent
void Konsola::zapiszSie(Lekarz lekarz) {
    std::string data;
    do {
        std::cout << "Podaj dzien dd.mm.rrrr:" << std::endl;
        std::cin >> data;
        system("cls");
    } while (!czyPoprawnaData(data)&&!czyZPrzeszlosci(data)); // podanie daty z walidacją

    auto wizytyLekarza = wizyty.pobierzDlaDanegoLekarz(lekarz.pobierzNumerLekarza());
    for (int i = 0; i < wizytyLekarza.size(); i++) {
        if (wizytyLekarza[i].pobierzDate() != data) {
            wizytyLekarza.erase(wizytyLekarza.begin() + i); // usuwanie wizyt z innego dnia niż ten, który nas obchodzi 
        }
    }

    Zmiana zmiana = lekarz.pobierzZmianeZDnia(data); // pobiera grafik lekarza z danego dnia
    
    if (zmiana.pobierzDzien() == Wolne) {
        std::cout << "Lekarz w tym dniu nie pracuje lub podano bledna date, prosze wybierz opcje jeszce raz";
        return;
    }

    for (int godzina = zmiana.pobierzGodzineRozpoczecia(); godzina <= zmiana.pobierzGodzineZakonczenia(); godzina++) {
        std::string nazwiskoZapisanejOsobyNaGodzine;
        for (auto wizyta : wizytyLekarza) {
           if (wizyta.pobierzGodzine() == godzina) {
               nazwiskoZapisanejOsobyNaGodzine = znajdzPacjentaPoPesel(wizyta.pobierzPeselPacjenta()).pobierzNazwisko();
           }
        }

        std::cout << godzina << ":00";
        if (nazwiskoZapisanejOsobyNaGodzine.empty()) {
            std::cout << " === Mozesz sie zapisac na ta godzine ===";
        } else {
            std::cout << "  PACJENT: " << nazwiskoZapisanejOsobyNaGodzine;
        }
        std::cout << std::endl;
    }

    int godzina = 0;
    do {
        std::cout << "Podaj gdzine by sie zapisac, lub wybierz 0 aby powrocic do menu" << std::endl;
        std::cin >> godzina;
        system("cls");
        if (godzina == 0) {
            return;
        }
    } while (godzina>0 && godzina<25 && czyZPrzeszlosci(data,godzina) && godzina<=zmiana.pobierzGodzineRozpoczecia() && godzina>=zmiana.pobierzGodzineZakonczenia());

    wizyty.dodaj(std::make_shared<Wizyta>(uzytkownikPtr->pobierzPesel(), lekarz.pobierzNumerLekarza(), data, godzina));  // https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared/  tworzymy nową wizytę //
}

/// Metoda odpowiedzialna za wyszukiwanie pacjenta po numerze pesel
/// 
/// @param pesel - zmienna typu string, funkcja przyjmuje pesel pacjenta
/// @returns funkcja zwraca obiekt klasy pacjent, którego odnalazł w spisie pacjentów
Pacjent Konsola::znajdzPacjentaPoPesel(std::string pesel) {
    for (auto pacjent : spisPacjentow) {
        if (pacjent.pobierzPesel() == pesel) {
            return pacjent;
        }
    }
}

/// Metoda służąca do wyświetlania danych zalogowanego użytkownika
/// 
void Konsola::SprawdzProfil() {
    std::cout << uzytkownikPtr->pobierzDaneOsoby()<<std::endl;
}

/// Metoda służąca do wyświetlania wizyt zalogowanego użytkownika 
/// 
/// Użytkownik może wybrać, czy chce sprawdzić wizyty, które już się odbyły, czy zaplanowane,
/// ma także możliwość odwołania zaplanowanej wizyty.
void Konsola::SprawdzWizyty() {
    auto wizytyPacjenta = wizyty.pobierzDlaDanegoPacjenta(uzytkownikPtr->pobierzPesel()); //szuka wizyt po peselu
    std::cout << "Twoje wizyty" << std::endl;
    std::cout << "0 - Powrot do menu" << std::endl;
    std::cout << "1 - Zaplanowane" << std::endl;
    std::cout << "2 - Odbyte" << std::endl;
    int wybor;
    bool czyWyswitlicOdbyte = false;
    std::cin >> wybor;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
 
  switch (wybor) {
        case 1:
            czyWyswitlicOdbyte = false;
            break;
        case 2 :
            czyWyswitlicOdbyte = true;
            break;
        case 0: 
        default:
            return;
        
    }

    bool czyPacjentMaZaplanowaneWizyty = false;
    if (wizytyPacjenta.size() == 0) std::cout << "Nie ma wizyt do wyswietlenia" << std::endl;
    for(auto wizyta : wizytyPacjenta) {

        if (czyWyswitlicOdbyte == wizyta.czySieOdbyla()) {
            czyPacjentMaZaplanowaneWizyty = true;
            std::cout << "Data: " << wizyta.pobierzDate() << " " << wizyta.pobierzGodzine() << ":00" << std::endl;
            Lekarz lekarz = znajdzLekarzaPoNumerzeLekarza(wizyta.pobierzNumerLekarza());
            std::cout << "Lekarz: " << lekarz.pobierzDaneOsoby()<<std::endl << std::endl;
        }
    }

    if (czyWyswitlicOdbyte && !czyPacjentMaZaplanowaneWizyty) {
        return;
    }

    std::string data, godzina;
    do {
        std::cout << "Jezeli chcesz odwolac istniejaca wizyte napisz jej date w formacie dd.mm.rrrr lub wpisz 0 aby powrocic do menu" << std::endl;
        std::cin >> data;
        system("cls");

       
        if (stoi(data) == 0) {
            return;
        }
        system("cls");

    } while (!czyPoprawnaData(data));

    do {
        std::cout << "Podaj godzine w fromacie gg (np 14)" << std::endl;
        std::cin >> godzina;
    } while (godzina.length() != 2 && isdigit(godzina[0]) && isdigit(godzina[1]) && (godzina[0] == '1' || godzina[0] == '0' || godzina[0] == '2') && (godzina[0] != '0' && godzina[1] != '0'));


    wizyty.usun(data, godzina);
    std::cout << "WIZYTA ZOSTALA ODWOLANA" << std::endl;
}

/// Metoda odpowiedzialna za wyszukiwanie lekarza po jego numerze
/// 
/// @param numer - zmienna typu string, funkcja przyjmuje numer lekarza
/// @returns funkcja zwraca obiekt klasy lekarz, którego odnalazł w spisie lekarzy
Lekarz Konsola::znajdzLekarzaPoNumerzeLekarza(unsigned int numerLekarza) {
    for (auto lekarz : lekarze) {
        if (numerLekarza == lekarz.pobierzNumerLekarza()) {
            return lekarz;
        }
    }
}

/// Metoda odpowiedzialna za sortowanie godzin pracy lekarzy
/// 
/// @param a - zmienna typu Zmiana
/// @param b - zmienna typu Zmiana
/// @returns funkcja zwraca true jeśli dzień zapisany w zmiennej a jest wcześniejszy niż dzień zapisany w zmiennej b, w przeciwnym wypadku zwraca false
bool Konsola::funkcja_sort(Zmiana a, Zmiana b) {
    return a.pobierzDzien() < b.pobierzDzien();
}

/// Metoda odpowiedzialna za wyświetlanie grafiku oraz danych wybranego lekarza
/// 
/// Metoda pozwala użytkownikowi wybrać lekarza, następnie wyświetla jego tygodniowy grafik pracy
void Konsola::WyswietlGrafikIDane() {
    
    WyszukiwanieLekrza();

    std::cout << "Jesli lekarz istnieje, czy chcesz sie zapoznac z godzinami pracy danego lekarza? Jesli tak podaj jego numer" << 
        std::endl << "Jesli lekarz nie istnieje lub chcesz wrocic do menu to wpisz 0"<<std::endl<<std::endl;
    int numerLekarza = 0;
    std::cin >> numerLekarza;
    system("cls");

    if (numerLekarza == 0) {
        return;
    }

    
    for (auto lekarz : lekarze) {
        if (lekarz.pobierzNumerLekarza() == numerLekarza) {

            auto zmianylekarza = lekarz.pobierzZmiany();
            std::sort(zmianylekarza.begin(), zmianylekarza.end(), &funkcja_sort); // https://en.cppreference.com/w/cpp/algorithm/sort //

            for (auto zmiana : zmianylekarza) {
                if (zmiana.pobierzDzien() == Wolne) continue;
                switch (zmiana.pobierzDzien()) {
                    case Poniedzialek:
                        std::cout << "Poniedzialek";
                        break;
                    case Wtorek:
                        std::cout << "Wtorek";
                        break;
                    case Sroda:
                        std::cout << "Sroda";
                        break;
                    case Czwartek:
                        std::cout << "Czwartek";
                        break;
                    case Piatek:
                        std::cout << "Piatek";
                        break;
                    case Sobota:
                        std::cout << "Sobota";
                        break;
                    case Niedziela:
                        std::cout << "Niedziela";
                        break;
                    case Wolne:
                        continue;
                }

                std::cout << " " << zmiana.pobierzGodzineRozpoczecia() << "-" << zmiana.pobierzGodzineZakonczenia() << std::endl<<std::endl;
            }
            int powrot;
            std::cout << "POWROT DO MENU - WPISZ 1";
            std::cin >> powrot;
            

            if (powrot == 1) {
                system("cls");
                return;
            };
        }
    }
}


/// Metoda odpowiedzialna za wyszukiwanie lekarzy (specjalizacji)
/// 
/// Metoda sprawdza czy istnieje jakiś lekarz z podaną specjalizacją
void Konsola::WyszukiwanieLekrza() {

    std::cout << "Jakiego specjalisty szukasz?" << std::endl;
    std::string specjalizacja;
    std::cout << "Nazwa specjializacji: " << std::endl;
    std::cin >> specjalizacja;
    system ("cls");

    bool czyIstniejeDanaSpecjalizacja = false;

    for(auto lekarz : lekarze) {
        if (lekarz.pobierzSpecjalizacje() == specjalizacja) {
            std::cout << lekarz.pobierzDaneOsoby()<<std::endl;
            czyIstniejeDanaSpecjalizacja = true;
        }
    }

    if (!czyIstniejeDanaSpecjalizacja) {
        std::cout << "Przykro nam, lekrze nie posiadaja zadanej specjalizacji"<<std::endl;
        return;
    }
}

/// Metoda odpowiedzialna za zapisywanie danych pacjenta do pliku. Po zakończeniu zapisywania zamyka plik
/// 
///@param imie - zmienna typu sting, będzie to imie pacjenta, które będziemy zapisywać w plik
///@param nazwisko - zmienna typu sting, będzie to nazwisko pacjenta, które będziemy zapisywać w plik
///@param PESEL - zmienna typu sting, będzie to numer pesel pacjenta, który będziemy zapisywać w plik
///@param DataUrodzenia - zmienna typu sting, będzie to data urodzenia pacjenta, którą będziemy zapisywać w plik
///@param numerTelefonu - zmienna typu sting, będzie to numer telefonu pacjenta, który będziemy zapisywać w plik
void Konsola::zapiszDanePacjenta(std::string imie, std::string nazwisko, std::string PESEL, std::string DataUrodzenia, std::string numerTelefonu) {
    std::ofstream plik;
    std::string linia;
    plik.open("pacjenci_dane.txt", std::ios::app);

    if (!plik.good()) {
        std::cout << "PLIK NIE ZOSTAŁ OTWARTY POPRAWNIE";
        exit(0);
    }
    plik << imie << " " << nazwisko << " " << PESEL << " " << DataUrodzenia << " " << numerTelefonu << std::endl;

    plik.close();
}
