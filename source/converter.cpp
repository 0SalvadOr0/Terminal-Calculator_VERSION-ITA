#include "..\include\converter.hpp"

void Converters() {
    int choice;
    float value;
    std::string fromUnit, toUnit;
    double exchangeRateUSDToEUR = 0.85;
    double exchangeRateGBPToEUR = 1.18;



    std::cout << "Scegli il tipo di conversione:\n 1. Lunghezza\n 2. Calorie\n 3. Massa\n 4. Temperatura\n 5. Velocità\n 6. Denaro\n 7. Dati Mobili\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Inserisci il valore da convertire: ";
            std::cin >> value;
            std::cout << "Inserisci l'unità di misura da cui convertire (m, km, cm, mm): ";
            std::cin >> fromUnit;
            std::cout << "Inserisci l'unità di misura a cui convertire (m, km, cm, mm): ";
            std::cin >> toUnit;

            if (fromUnit == "m") {
                if (toUnit == "km") {
                    std::cout << "Valore finale: " << value / 1000 << " km" << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << "Valore finale: " << value * 100 << " cm" << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << "Valore finale: " << value * 1000 << " mm" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "km") {
                if (toUnit == "m") {
                    std::cout << "Valore finale: " << value * 1000 << " m" << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << "Valore finale: " << value * 100000 << " cm" << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << "Valore finale: " << value * 1000000 << " mm" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "cm") {
                if (toUnit == "m") {
                    std::cout << "Valore finale: " << value / 100 << " m" << std::endl;
                } else if (toUnit == "km") {
                    std::cout << "Valore finale: " << value / 100000 << " km" << std::endl;
                } else if (toUnit == "mm") {
                    std::cout << "Valore finale: " << value * 10 << " mm" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "mm") {
                if (toUnit == "m") {
                    std::cout << "Valore finale: " << value / 1000 << " m" << std::endl;
                } else if (toUnit == "km") {
                    std::cout << "Valore finale: " << value / 1000000 << " km" << std::endl;
                } else if (toUnit == "cm") {
                    std::cout << "Valore finale: " << value / 10 << " cm" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else {
                std::cout << "Unità di misura di partenza non valida." << std::endl;
            }
            break;

            case 2:
            std::cout << "Inserisci il valore da convertire: ";
            std::cin >> value;
            std::cout << "Inserisci l'unità di misura da cui convertire (cal, kcal, kJ): ";
            std::cin >> fromUnit;
            std::cout << "Inserisci l'unità di misura a cui convertire (cal, kcal, kJ): ";
            std::cin >> toUnit;

            if (fromUnit == "cal") {
                if (toUnit == "kcal") {
                    std::cout << "Valore finale: " << value / 1000 << " kcal" << std::endl;
                } else if (toUnit == "kJ") {
                    std::cout << "Valore finale: " << value * 0.004184 << " kJ" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "kcal") {
                if (toUnit == "cal") {
                    std::cout << "Valore finale: " << value * 1000 << " cal" << std::endl;
                } else if (toUnit == "kJ") {
                    std::cout << "Valore finale: " << value * 4.184 << " kJ" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "kJ") {
                if (toUnit == "cal") {
                    std::cout << "Valore finale: " << value * 239.006 << " cal" << std::endl;
                } else if (toUnit == "kcal") {
                    std::cout << "Valore finale: " << value * 0.239006 << " kcal" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else {
                std::cout << "Unità di misura di partenza non valida." << std::endl;
            }
            break;

            case 3: 
            std::cout << "Inserisci il valore da convertire: ";
            std::cin >> value;
            std::cout << "Inserisci l'unità di misura da cui convertire (kg, g, lb): ";
            std::cin >> fromUnit;
            std::cout << "Inserisci l'unità di misura a cui convertire (kg, g, lb): ";
            std::cin >> toUnit;

            if (fromUnit == "kg") {
                if (toUnit == "g") {
                    std::cout << "Valore finale: " << value * 1000 << " g" << std::endl;
                } else if (toUnit == "lb") {
                    std::cout << "Valore finale: " << value * 2.2046 << " lb" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "g") {
                if (toUnit == "kg") {
                    std::cout << "Valore finale: " << value / 1000 << " kg" << std::endl;
                } else if (toUnit == "lb") {
                    std::cout << "Valore finale: " << value *  0.00220462 << " lb" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else if (fromUnit == "lb") {
                if (toUnit == "kg") {
                    std::cout << "Valore finale: " << value / 2.2046 << " kg" << std::endl;
                } else if (toUnit == "g") {
                    std::cout << "Valore finale: " << value / 0.00220462 << " g" << std::endl;
                } else {
                    std::cout << "Unità di misura di destinazione non valida." << std::endl;
                }
            } else {
                std::cout << "Unità di misura di partenza non valida." << std::endl;
            }
            break;

            case 4:
    std::cout << "Inserisci il valore da convertire: ";
    std::cin >> value;
    std::cout << "Inserisci l'unità di misura da cui convertire (C, F, K): ";
    std::cin >> fromUnit;
    std::cout << "Inserisci l'unità di misura a cui convertire (C, F, K): ";
    std::cin >> toUnit;

    if (fromUnit == "C" || fromUnit == "c") {
        if (toUnit == "F" || toUnit == "f") {
            std::cout << "Valore finale: " << (value * 9 / 5) + 32 << " °F" << std::endl;
        } else if (toUnit == "K" || toUnit == "k") {
            std::cout << "Valore finale: " << value + 273.15 << " K" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else if (fromUnit == "F" || fromUnit == "f") {
        if (toUnit == "C" || toUnit == "c") {
            std::cout << "Valore finale: " << (value - 32) * 5 / 9 << " °C" << std::endl;
        } else if (toUnit == "K" || toUnit == "k") {
            std::cout << "Valore finale: " << (value - 32) * 5 / 9 + 273.15 << " K" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else if (fromUnit == "K" || fromUnit == "k") {
        if (toUnit == "C" || toUnit == "c") {
            std::cout << "Valore finale: " << value - 273.15 << " °C" << std::endl;
        } else if (toUnit == "F" || toUnit == "f") {
            std::cout << "Valore finale: " << (value - 273.15) * 9 / 5 + 32 << " °F" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else {
        std::cout << "Unità di misura di partenza non valida." << std::endl;
    }
    break;

         case 5:
    std::cout << "Inserisci il valore da convertire: ";
    std::cin >> value;
    std::cout << "Inserisci l'unità di misura da cui convertire (m/s, km/h, mph): ";
    std::cin >> fromUnit;
    std::cout << "Inserisci l'unità di misura a cui convertire (m/s, km/h, mph): ";
    std::cin >> toUnit;

    if (fromUnit == "m/s" || fromUnit == "mS" || fromUnit == "M/S") {
        if (toUnit == "km/h" || toUnit == "kmh" || toUnit == "KM/H") {
            std::cout << "Valore finale: " << value * 3.6 << " km/h" << std::endl;
        } else if (toUnit == "mph" || toUnit == "MPH") {
            std::cout << "Valore finale: " << value * 2.23694 << " mph" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else if (fromUnit == "km/h" || fromUnit == "kmh" || fromUnit == "KM/H") {
        if (toUnit == "m/s" || toUnit == "mS" || toUnit == "M/S") {
            std::cout << "Valore finale: " << value / 3.6 << " m/s" << std::endl;
        } else if (toUnit == "mph" || toUnit == "MPH") {
            std::cout << "Valore finale: " << value / 1.60934 << " mph" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else if (fromUnit == "mph" || fromUnit == "MPH") {
        if (toUnit == "m/s" || toUnit == "mS" || toUnit == "M/S") {
            std::cout << "Valore finale: " << value / 2.23694 << " m/s" << std::endl;
        } else if (toUnit == "km/h" || toUnit == "kmh" || toUnit == "KM/H") {
            std::cout << "Valore finale: " << value * 1.60934 << " km/h" << std::endl;
        } else {
            std::cout << "Unità di misura di destinazione non valida." << std::endl;
        }
    } else {
        std::cout << "Unità di misura di partenza non valida." << std::endl;
    }
    break;

    case 6:
        std::cout << "Inserisci il valore da convertire: ";
        std::cin >> value;
        std::cout << "Inserisci la valuta da cui convertire (EUR, USD, GBP): ";
        std::cin >> fromUnit;
        std::cout << "Inserisci la valuta a cui convertire (EUR, USD, GBP): ";
        std::cin >> toUnit;

     
        if (fromUnit == "EUR") {
            if (toUnit == "USD") {
                std::cout << "Valore finale: " << value / exchangeRateUSDToEUR << " USD" << std::endl;
            } else if (toUnit == "GBP") {
                std::cout << "Valore finale: " << value / exchangeRateGBPToEUR << " GBP" << std::endl;
            } else {
                std::cout << "Valuta di destinazione non valida." << std::endl;
            }
        } else if (fromUnit == "USD") {
            if (toUnit == "EUR") {
                std::cout << "Valore finale: " << value * exchangeRateUSDToEUR << " EUR" << std::endl;
            } else if (toUnit == "GBP") {
                std::cout << "Valore finale: " << (value * exchangeRateUSDToEUR) / exchangeRateGBPToEUR << " GBP" << std::endl;
            } else {
                std::cout << "Valuta di destinazione non valida." << std::endl;
            }
        } else if (fromUnit == "GBP") {
            if (toUnit == "EUR") {
                std::cout << "Valore finale: " << value * exchangeRateGBPToEUR << " EUR" << std::endl;
            } else if (toUnit == "USD") {
                std::cout << "Valore finale: " << (value * exchangeRateGBPToEUR) * exchangeRateUSDToEUR << " USD" << std::endl;
            } else {
                std::cout << "Valuta di destinazione non valida." << std::endl;
            }
        } else {
            std::cout << "Valuta di partenza non valida." << std::endl;
        }
        break;

        case 7:
        std::cout << "Inserisci il valore da convertire: ";
        std::cin >> value;
        std::cout << "Inserisci l'unità di misura da cui convertire (GB, MB): ";
        std::cin >> fromUnit;
        std::cout << "Inserisci l'unità di misura a cui convertire (GB, MB): ";
        std::cin >> toUnit;

        if (fromUnit == "GB") {
            if (toUnit == "MB") {
                std::cout << "Valore finale: " << value * 1024 << " MB" << std::endl;
            } else {
                std::cout << "Unità di misura di destinazione non valida." << std::endl;
            }
        } else if (fromUnit == "MB") {
            if (toUnit == "GB") {
                std::cout << "Valore finale: " << value / 1024 << " GB" << std::endl;
            } else {
                std::cout << "Unità di misura di destinazione non valida." << std::endl;
            }
        } else {
            std::cout << "Unità di misura di partenza non valida." << std::endl;
        }
        break;


        default:
            std::cout << "Scelta non valida." << std::endl;
            break;
    }
}