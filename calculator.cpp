#include "calculator.h"

// Definizione di M_PI se non è già definito
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Dichiarazione delle funzioni
void Title();
void choice();
void addition(float &a, float &b);
void subtraction(float &a, float &b);
void multiplication(float &a, float &b);
void division(float &a, float &b);
void Pow(float &a, float &b);
void Sqrt(float &a);
void Triangle();
void TrigonometricOperations();
void PercentageCalculations();
void Converters();

// Funzione per stampare il titolo stilizzato
void Title(){
// Stampa del titolo con caratteri speciali
std::cout<<"******************************"<<std::endl;
std::cout<<"  ----------------- "<<std::endl;
std::cout<<" |                  | "<<std::endl;
std::cout<<"  -------   --------  "<<std::endl;
std::cout<<"        |   |     -------- "<<std::endl;
std::cout<<"        |   |    /  ------ "<<std::endl;
std::cout<<"        |   |    || "<<std::endl;
std::cout<<"        |   |    || "<<std::endl;
std::cout<<"         ---     || "<<std::endl;
std::cout<<"                 \\ "<<std::endl;
std::cout<<"                  --------"<<std::endl;
std::cout<<"******************************"<<std::endl;
}


void Menu(){
    std::cout << "******************************" << std::endl;
    std::cout << "Scegli l'opzione:\n";
    std::cout << " 1. Addizione\n";
    std::cout << " 2. Sottrazione\n";
    std::cout << " 3. Moltiplicazione\n";
    std::cout << " 4. Divisione\n";
    std::cout << " 5. Potenza\n";
    std::cout << " 6. Radice quadrata\n";
    std::cout << " 7. Opzioni triangolo\n";
    std::cout << " 8. Operazioni di trigonometria\n";
    std::cout << " 9. Percentuali\n";
    std::cout << " 10. Convertitore\n";
    std::cout << " 11. Calcolo BMI\n"; // Aggiunta dell'opzione per il calcolo del BMI
    std::cout << " 12. Calcolo Area e Perimetro\n";
    std::cout << " 13. Calcolatore dell'età\n";
    std::cout << " 14. Calcolatore delle tasse\n";
    std::cout << " 15. Esci\n"; // Aggiornamento del numero dell'opzione "Esci"
    std::cout << "******************************" << std::endl;
}

// Funzione per la scelta dell'operazione
void choice() {
    int option;
    bool exitProgram = false;  // Aggiunta della variabile di controllo per l'uscita

    while (!exitProgram) {  // Utilizzo di un ciclo per mantenere il menu attivo
        Menu();
        std::cin >> option;

        float a, b, c;

        switch (option) {
            case 1:
                addition(a, b);
                break;
            case 2:
                subtraction(a, b);
                break;
            case 3:
                multiplication(a, b);
                break;
            case 4:
                division(a, b);
                break;
            case 5:
                Pow(a, b);
                break;
            case 6:
                Sqrt(a);
                break;
            case 7:
                Triangle();
                break; 
            case 8:
                TrigonometricOperations();
                break;
            case 9:
                PercentageCalculations();
                break;
            case 10:
                Converters();
                break;
            case 11:
                BMICalculator();
                break;
            case 12: 
                CalculateAreaAndPermiter();
                break;
            case 13: {
            std::cout << "Inserisci la data di nascita (AAAA MM GG): ";
            std::tm birthDate = {};
            std::cin >> std::get_time(&birthDate, "%Y %m %d");

            if (std::cin.fail()) {
                std::cerr << "Errore nell'input della data." << std::endl;
                break;
            }

            int age = CalculateAge(birthDate);
            std::cout << "La tua età è: " << age << " anni." << std::endl;
            break;
        }
            case 14: 
            CalculateTax();
            break;
            
            case 15:
                exitProgram = true;  // Imposta la variabile per uscire dal ciclo
                break;
            default:
                std::cout << "Opzione non valida.\n";
                break;
        }
    }
}


void addition(float &a, float &b) {
    std::cout << "Inserisci primo valore: ";
    std::cin >> a;
    std::cout << "Inserisci secondo valore: ";
    std::cin >> b;
    std::cout << "Risultato dell'addizione: " << a + b << std::endl;
}

void subtraction(float &a, float &b) {
    std::cout << "Inserisci primo valore: ";
    std::cin >> a;
    std::cout << "Inserisci secondo valore: ";
    std::cin >> b;
    std::cout << "Risultato della sottrazione: " << a - b << std::endl;
}

void multiplication(float &a, float &b) {
    std::cout << "Inserisci primo valore: ";
    std::cin >> a;
    std::cout << "Inserisci secondo valore: ";
    std::cin >> b;
    std::cout << "Risultato della moltiplicazione: " << a * b << std::endl;
}

void division(float &a, float &b) {
    std::cout << "Inserisci primo valore: ";
    std::cin >> a;
    std::cout << "Inserisci secondo valore: ";
    std::cin >> b;

    if (b == 0) {
        std::cout << "Divisione per zero non consentita." << std::endl;
    } else {
        std::cout << "Risultato della divisione: " << a / b << std::endl;
    }
}

void Pow(float &a, float &b) {
    std::cout << "Inserisci il primo valore: ";
    std::cin >> a;
    std::cout << "Inserisci il valore della potenza: ";
    std::cin >> b;
    std::cout << "Risultato finale: " << std::pow(a, b) << std::endl;
}

void Sqrt(float &a) {
    std::cout << "Inserisci il valore: ";
    std::cin >> a;
    
    if (a < 0) {
        std::cout << "Valore negativo, impossibile calcolare la radice quadrata." << std::endl;
    } else {
        std::cout << "Risultato finale: " << std::sqrt(a) << std::endl;
    }
}

void Triangle() {
    int t_option;
    std::cout << "Scegli l'opzione:\n 1. Calcola il cateto\n 2. Calcola l'ipotenusa\n";
    std::cin >> t_option;
    
    float a, b, c;
    
    switch (t_option) {
        case 1:
            std::cout << "Inserisci il valore dell'ipotenusa: ";
            std::cin >> a;
            std::cout << "Inserisci il valore del cateto: ";
            std::cin >> b;
            c = std::sqrt(pow(a, 2) - pow(b, 2));
            std::cout << "Il cateto misura: " << c << std::endl;
            break;
        case 2:
            std::cout << "Inserisci il valore del cateto maggiore: ";
            std::cin >> a;
            std::cout << "Inserisci il valore del cateto minore: ";
            std::cin >> b;
            c = std::sqrt(pow(a, 2) + pow(b, 2));
            std::cout << "Il cateto misura: " << c << std::endl;
            break;
        default:
            std::cout << "Opzione non valida" << std::endl;
            break;
    }
}

void TrigonometricOperations() {
    int choice;
    float angle;

    std::cout << "Scegli l'operazione:\n 1. Calcola il seno\n 2. Calcola il coseno\n 3. Calcola la tangente\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Inserisci l'angolo in gradi: ";
            std::cin >> angle;
            std::cout << "Seno(" << angle << "): " << std::sin(angle * M_PI / 180) << std::endl;
            break;
        case 2:
            std::cout << "Inserisci l'angolo in gradi: ";
            std::cin >> angle;
            std::cout << "Coseno(" << angle << "): " << std::cos(angle * M_PI / 180) << std::endl;
            break;
        case 3:
            std::cout << "Inserisci l'angolo in gradi: ";
            std::cin >> angle;
            std::cout << "Tangente(" << angle << "): " << std::tan(angle * M_PI / 180) << std::endl;
            break;
        default:
            std::cout << "Opzione non valida.\n";
            break;
    }
}

void PercentageCalculations() {
    int choice;
    float initialValue, percentage, result;

    std::cout << "Scegli l'operazione:\n 1. Calcola la variazione percentuale\n 2. Calcola lo sconto\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Inserisci il valore iniziale: ";
            std::cin >> initialValue;
            std::cout << "Inserisci la percentuale di variazione: ";
            std::cin >> percentage;
            result = initialValue * (percentage / 100);
            std::cout << "Variazione percentuale: " << result << std::endl;
            break;
        case 2:
            std::cout << "Inserisci il prezzo originale: ";
            std::cin >> initialValue;
            std::cout << "Inserisci lo sconto in percentuale: ";
            std::cin >> percentage;
            result = initialValue - (initialValue * (percentage / 100));
            std::cout << "Prezzo dopo lo sconto: " << result << std::endl;
            break;
        default:
            std::cout << "Opzione non valida.\n";
            break;
    }
}

void Converters() {
    int choice;
    float value;
    std::string fromUnit, toUnit;
    double exchangeRateUSDToEUR = 0.85;
    double exchangeRateGBPToEUR = 1.18;



    std::cout << "Scegli il tipo di conversione:\n 1. Lunghezza\n 2. Calorie\n 3. Massa\n 4. Temperatura\n 5. Velocità\n 6. Denaro\n";
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

        default:
            std::cout << "Scelta non valida." << std::endl;
            break;
    }
}

void BMICalculator() {
    float weight, height;

    // Richiedi all'utente di inserire il peso in kg e l'altezza in metri
    std::cout << "Inserisci il peso in kg: ";
    std::cin >> weight;
    std::cout << "Inserisci l'altezza in metri: ";
    std::cin >> height;

    // Calcola il BMI utilizzando la formula: BMI = peso (kg) / altezza^2 (m^2)
    float bmi = weight / (height * height);

    // Stampa il BMI calcolato
    std::cout << "Il tuo BMI è: " << bmi << std::endl;

    // Classifica il BMI in base alle categorie comuni
    if (bmi < 18.5) {
        std::cout << "Sottopeso" << std::endl;
    } else if (bmi < 24.9) {
        std::cout << "Normale" << std::endl;
    } else if (bmi < 29.9) {
        std::cout << "Sovrappeso" << std::endl;
    } else {
        std::cout << "Obeso" << std::endl;
    }
}

void CalculateAreaAndPermiter(){
    int choice;
    double side, length, width, radius, base, height;

    std::cout << "Scegli la figura geometrica:\n";
    std::cout << "1. Quadrato\n";
    std::cout << "2. Rettangolo\n";
    std::cout << "3. Cerchio\n";
    std::cout << "4. Triangolo\n";
    std::cout << "Scelta: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Inserisci la lunghezza del lato del quadrato: ";
            std::cin >> side;
            std::cout << "Area del quadrato: " << side * side << std::endl;
            std::cout << "Perimetro del quadrato: " << 4 * side << std::endl;
            break;

        case 2:
            std::cout << "Inserisci la lunghezza e la larghezza del rettangolo: ";
            std::cin >> length >> width;
            std::cout << "Area del rettangolo: " << length * width << std::endl;
            std::cout << "Perimetro del rettangolo: " << 2 * (length + width) << std::endl;
            break;

        case 3:
            std::cout << "Inserisci il raggio del cerchio: ";
            std::cin >> radius;
            std::cout << "Area del cerchio: " << M_PI * radius * radius << std::endl;
            std::cout << "Circonferenza del cerchio: " << 2 * M_PI * radius << std::endl;
            break;

        case 4:
            std::cout << "Inserisci la base e l'altezza del triangolo: ";
            std::cin >> base >> height;
            std::cout << "Area del triangolo: " << 0.5 * base * height << std::endl;
            std::cout << "Perimetro del triangolo: Inserisci i lati: ";
            double side1, side2, side3;
            std::cin >> side1 >> side2 >> side3;
            std::cout << "Perimetro del triangolo: " << side1 + side2 + side3 << std::endl;
            break;

        default:
            std::cout << "Scelta non valida!" << std::endl;
            break;    
}
}

// Funzione per calcolare l'età in base alla data di nascita
int CalculateAge(const std::tm& birthDate) {
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);

    int age = currentDate->tm_year - birthDate.tm_year;
    if (currentDate->tm_mon < birthDate.tm_mon ||
        (currentDate->tm_mon == birthDate.tm_mon && currentDate->tm_mday < birthDate.tm_mday)) {
        age--;
    }

    return age;
}

// Funzione per calcolare l'importo delle tasse in base al reddito e alle aliquote fiscali
double CalculateTax() {
    int percentTax;
    double income;

    std::cout << "Inserisci l'importo del tuo reddito: ";
    std::cin >> income;

    if (std::cin.fail()) {
        std::cerr << "Errore nell'input del reddito." << std::endl;
        return 0.0;
    }

    std::cout << "Inserisci la percentuale della tua aliquota fiscale: ";
    std::cin >> percentTax;

    if (std::cin.fail() || percentTax < 0 || percentTax > 100) {
        std::cerr << "Percentuale tassa non valida." << std::endl;
        return 0.0;
    }

    double tax = (income * percentTax) / 100.0;

    std::cout << "Le tue tasse sono pari a: " << tax << std::endl;
    return tax;
}
