#include "calculator.h"
#include "design/design.h"
#include "converter/converter.h"

// Definizione di M_PI se non è già definito
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Funzione per la scelta dell'operazione
void choice() {
    int option;
    int choice;
    bool exitProgram = false;  // Aggiunta della variabile di controllo per l'uscita


    while (!exitProgram) {  // Utilizzo di un ciclo per mantenere il menu attivo
        Title();
        Menu();
         std::cout << "Inserisci la tua scelta: ";
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
    std::cout << "Lunghezza della password:\n 1. 6 Caratteri\n 2. 8 Caratteri\n 3. 12 Caratteri\n";
    std::cin >> choice;
    

    switch (choice) {
        case 1:
            GeneratePassword(6);
            break;
        case 2:
            GeneratePassword(8);
            break;
        case 3:
            GeneratePassword(12);
            break;
        default:
            std::cout << "Scelta non valida." << std::endl;
            break;
    }
    break;
            case 16:
            std::cout << "Opzioni:\n 1. Calcolatore di Volume\n 2. Calcolatore di superficie\n";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                CalculateVolume();
                break;
            case 2:
                CalculateSurface();
                break;
            default:
                break;
            }
            break;
            case 17:
                exitProgram = true;  // Imposta la variabile per uscire dal ciclo
                break;
            default:
                std::cout << "Opzione non valida.\n";
                break;
        }
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


void GeneratePassword(int length) {
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numericChars = "0123456789";
    const std::string specialChars = "!@#$%^&*()-_+=<>?";

    const std::string allChars = lowercaseChars + uppercaseChars + numericChars + specialChars;

    std::string password;

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int randomIndex = std::rand() % allChars.length();
        password += allChars[randomIndex];
    }

    std::cout << "Password generata con successo: " << password << std::endl;
    std::cout << "Non mostrare la tua password a nessuno"<<std::endl;
}

float CalculateVolume() {
    float radius, height;
    float volume;
    int shape;

    std::cout << "Inserisci il valore del raggio: ";
    std::cin >> radius;

    std::cout << "Decidi il tipo di figura:\n 1. Sfera\n 2. Cilindro\n 3. Cono\n";
    std::cin >> shape;

    if (shape == 1) {
        // Sfera
        volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
        std::cout << "Il volume misura: " << volume << std::endl;
    } else if (shape == 2) {
        std::cout << "Inserisci il valore dell'altezza: ";
        std::cin >> height;
        // Cilindro
        volume = M_PI * radius * radius * height;
        std::cout << "Il volume misura: " << volume << std::endl;
    } else if (shape == 3) {
        std::cout << "Inserisci il valore dell'altezza: ";
        std::cin >> height;
        // Cono
        volume = 1.0 / 3.0 * M_PI * radius * radius * height;
        std::cout << "Il volume misura: " << volume << std::endl;
    }
    return volume;
}


float CalculateSurface() {
    float radius, height, slantHeight;
    float surface;
    int shape;

    std::cout << "Inserisci il valore del raggio: ";
    std::cin >> radius;

    std::cout << "Decidi il tipo di figura:\n 1. Sfera\n 2. Cilindro\n 3. Cono\n";
    std::cin >> shape;

    if (shape == 1) {
        // Sfera  
        surface = 4 * M_PI * radius * radius;
        std::cout << "La superficie misura: " << surface << std::endl;
    } else if (shape == 2) {
        std::cout << "Inserisci il valore dell'altezza: ";
        std::cin >> height;
        // Cilindro
        surface = 2 * M_PI * radius * (radius + height);
        std::cout << "La superficie misura: " << surface << std::endl;
    } else if (shape == 3) {
        std::cout << "Inserisci il valore dell'altezza: ";
        std::cin >> height;
        // Cono
        slantHeight = sqrt(radius * radius + height * height);
        surface = M_PI * radius * (radius + slantHeight);
        std::cout << "La superficie misura: " << surface << std::endl;
    }
    return surface;
}

