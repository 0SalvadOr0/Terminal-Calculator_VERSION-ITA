#include "..\include\converter.hpp"

using json = nlohmann::json;

// Funzione per gestire la risposta HTTP
size_t WriteCallbackConverter(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

void exangeMoney() {
    // Interagisci con l'utente
    std::string fromCurrency, toCurrency, apiKey;
    double amount;
    std::cout << "Inserisci la tua apiKey del sito exchangerate-api: ";
    std::cin >> apiKey;
    std::cout << "Inserisci la valuta di partenza (es. USD): ";
    std::cin >> fromCurrency;
    std::cout << "Inserisci l'importo: ";
    std::cin >> amount;
    std::cout << "Inserisci la valuta di destinazione (es. EUR): ";
    std::cin >> toCurrency;

    // Inizializza libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Errore nell'inizializzazione di libcurl." << std::endl;
    }


    // URL dell'API di cambio valuta
    std::string apiURL = "https://v6.exchangerate-api.com/v6/"+ apiKey+ "/latest/" + fromCurrency;

    // Effettua la richiesta HTTP
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, apiURL.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallbackConverter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "Errore nella richiesta HTTP: " << curl_easy_strerror(res) << std::endl;
    }

    // Parsa la risposta JSON
    json exchangeData = json::parse(response);
    if (exchangeData["result"] != "success") {
        std::cerr << "Errore nella risposta dell'API." << std::endl;
    }

    // Calcola la conversione
    double exchangeRate = exchangeData["conversion_rates"][toCurrency];
    double convertedAmount = amount * exchangeRate;

    std::cout << amount << " " << fromCurrency << " corrispondono a " << convertedAmount << " " << toCurrency << std::endl;

    // Pulisci e rilascia risorse
    curl_easy_cleanup(curl);
}



void Converters() {
    int choice;
    float value;
    std::string fromUnit, toUnit;



    std::cout << ANSI_COLOR_BLUE << "Scegli il tipo di conversione:\n 1. Lunghezza\n 2. Calorie\n 3. Massa\n 4. Temperatura\n 5. Velocità\n 6. Denaro\n 7. Dati Mobili\n" << ANSI_COLOR_RESET;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
            std::cin >> value;
            std::cout << ANSI_COLOR_CYAN << "Inserisci l'unità di misura da cui convertire (m, km, cm, mm): " << ANSI_COLOR_RESET;
            std::cin >> fromUnit;
            std::cout << ANSI_COLOR_CYAN << "Inserisci l'unità di misura a cui convertire (m, km, cm, mm): " << ANSI_COLOR_RESET;
            std::cin >> toUnit;

            if (fromUnit == "m") {
                if (toUnit == "km") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 1000 << " km" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 100 << " cm" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 1000 << " mm" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else if (fromUnit == "km") {
                if (toUnit == "m") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 1000 << " m" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 100000 << " cm" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 1000000 << " mm" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else if (fromUnit == "cm") {
                if (toUnit == "m") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 100 << " m" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "km") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 100000 << " km" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 10 << " mm" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else if (fromUnit == "mm") {
                if (toUnit == "m") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 1000 << " m" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "km") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 1000000 << " km" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 10 << " cm" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else {
                std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
            }
            break;

            case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
            std::cin >> value;
            std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura da cui convertire (cal, kcal, kJ): " << ANSI_COLOR_RESET;
            std::cin >> fromUnit;
            std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura a cui convertire (cal, kcal, kJ): " << ANSI_COLOR_RESET;
            std::cin >> toUnit;

            if (fromUnit == "cal") {
                if (toUnit == "kcal") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value / 1000 << " kcal" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "kJ") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 0.004184 << " kJ" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else if (fromUnit == "kcal") {
                if (toUnit == "cal") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 1000 << " cal" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "kJ") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 4.184 << " kJ" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else if (fromUnit == "kJ") {
                if (toUnit == "cal") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 239.006 << " cal" << ANSI_COLOR_RESET << std::endl;
                } else if (toUnit == "kcal") {
                    std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << value * 0.239006 << " kcal" << ANSI_COLOR_RESET << std::endl;
                } else {
                    std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
                }
            } else {
                std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
            }
            break;

            case 3:
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
    std::cin >> value;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura da cui convertire (kg, g, lb): " << ANSI_COLOR_RESET;
    std::cin >> fromUnit;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura a cui convertire (kg, g, lb): " << ANSI_COLOR_RESET;
    std::cin >> toUnit;

    if (fromUnit == "kg") {
        if (toUnit == "g") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 1000 << " g" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "lb") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 2.2046 << " lb" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "g") {
        if (toUnit == "kg") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 1000 << " kg" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "lb") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 0.00220462 << " lb" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "lb") {
        if (toUnit == "kg") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 2.2046 << " kg" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "g") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 0.00220462 << " g" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else {
        std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
    }
    break;


           case 4:
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
    std::cin >> value;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura da cui convertire (C, F, K): " << ANSI_COLOR_RESET;
    std::cin >> fromUnit;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura a cui convertire (C, F, K): " << ANSI_COLOR_RESET;
    std::cin >> toUnit;

    if (fromUnit == "C" || fromUnit == "c") {
        if (toUnit == "F" || toUnit == "f") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << (value * 9 / 5) + 32 << " °F" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "K" || toUnit == "k") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value + 273.15 << " K" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "F" || fromUnit == "f") {
        if (toUnit == "C" || toUnit == "c") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << (value - 32) * 5 / 9 << " °C" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "K" || toUnit == "k") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << (value - 32) * 5 / 9 + 273.15 << " K" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "K" || fromUnit == "k") {
        if (toUnit == "C" || toUnit == "c") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value - 273.15 << " °C" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "F" || toUnit == "f") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << (value - 273.15) * 9 / 5 + 32 << " °F" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else {
        std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
    }
    break;


         case 5:
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
    std::cin >> value;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura da cui convertire (m/s, km/h, mph): " << ANSI_COLOR_RESET;
    std::cin >> fromUnit;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura a cui convertire (m/s, km/h, mph): " << ANSI_COLOR_RESET;
    std::cin >> toUnit;

    if (fromUnit == "m/s" || fromUnit == "mS" || fromUnit == "M/S") {
        if (toUnit == "km/h" || toUnit == "kmh" || toUnit == "KM/H") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 3.6 << " km/h" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "mph" || toUnit == "MPH") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 2.23694 << " mph" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "km/h" || fromUnit == "kmh" || fromUnit == "KM/H") {
        if (toUnit == "m/s" || toUnit == "mS" || toUnit == "M/S") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 3.6 << " m/s" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "mph" || toUnit == "MPH") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 1.60934 << " mph" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "mph" || fromUnit == "MPH") {
        if (toUnit == "m/s" || toUnit == "mS" || toUnit == "M/S") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 2.23694 << " m/s" << ANSI_COLOR_RESET << std::endl;
        } else if (toUnit == "km/h" || toUnit == "kmh" || toUnit == "KM/H") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 1.60934 << " km/h" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else {
        std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
    }
    break;


   case 6:
    exangeMoney();
    break;


        case 7:
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore da convertire: " << ANSI_COLOR_RESET;
    std::cin >> value;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura da cui convertire (GB, MB): " << ANSI_COLOR_RESET;
    std::cin >> fromUnit;
    std::cout << ANSI_COLOR_BLUE << "Inserisci l'unità di misura a cui convertire (GB, MB): " << ANSI_COLOR_RESET;
    std::cin >> toUnit;

    if (fromUnit == "GB") {
        if (toUnit == "MB") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value * 1024 << " MB" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else if (fromUnit == "MB") {
        if (toUnit == "GB") {
            std::cout << ANSI_COLOR_GREEN << "Valore finale: " << ANSI_COLOR_YELLOW << value / 1024 << " GB" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_RED << "Unità di misura di destinazione non valida." << ANSI_COLOR_RESET << std::endl;
        }
    } else {
        std::cout << ANSI_COLOR_RED << "Unità di misura di partenza non valida." << ANSI_COLOR_RESET << std::endl;
    }
    break;


        default:
            std::cout << ANSI_COLOR_RED << "Scelta non valida." << ANSI_COLOR_RESET << std::endl;
            break;
    }
}