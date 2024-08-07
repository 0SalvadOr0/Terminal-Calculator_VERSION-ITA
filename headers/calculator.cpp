#include "calculator.hpp"


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

        float a,b;
        std::string y;
        std::string expression;


        switch (option) {
            case 0:
                exitProgram = true;  // Imposta la variabile per uscire dal ciclo
                break;
            case 1:
                operation();
                break;
            case 2:
                Triangle();
                break; 
            case 3:
                ScientificCalculator();
                break;
            case 4:
                PercentageCalculations();
                break;
            case 5:
                Converters();
                break;
            case 6:
                BMICalculator();
                break;
            case 7: 
                CalculateAreaAndPerimeter();
                break;
            case 8: 
                timeFuncs();
                break;
            case 9: 
                CalculateTax();
                break;    
           case 10:
           checkDecision();
            break;
            case 11:
            std::cout << ANSI_COLOR_BLUE << "Opzioni:\n 1. Calcolatore di Volume\n 2. Calcolatore di superficie\n" << ANSI_COLOR_RESET;
            std::cout << "******************************" << std::endl;
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
         case 12:
            std::cout << "Inserisci un espressione: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, expression);

    try {
        float result = calculateExpression(expression);
        std::cout << "Risultato: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    break;


           case 13:
            std::cout << ANSI_COLOR_BLUE << "Opzioni:\n 1. Equazioni lineari del tipo ax+b = 0\n 2. Sistemi lineari\n 3. Equazioni quadratiche del tipo ax^2+bx+c=0\n" << ANSI_COLOR_RESET;
            std::cout << "******************************" << std::endl;
            std::cin >> choice;
            while(std::cin.fail()) {
                std::cout << "Input non valido. Per favore inserisci un numero: ";
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> choice;
                }

            switch (choice)
            {
            case 1:
                std::cout << "******************************" << std::endl;
                std::cout << ANSI_COLOR_MAGENTA << "Inserisci il coefficiente a: " << ANSI_COLOR_RESET;
                std::cin >> a;
                std::cout << ANSI_COLOR_MAGENTA << "Inserisci il coefficiente b: " << ANSI_COLOR_RESET;
                std::cin >> b;

                solveLinearEquation(a, b);
                break;
            case 2: 
                CramerSistemEquation();
                break; 
            case 3:
                solveQuadratic();
                break;
            default:
                break;
            }
            break;
            case 14: 
            statistics();
            break;
            case 15:
            graphics();
            break;
            case 16:
            weather();
            break;
            case 17:
            SpacePerson();
            break;
            case 18:
            GetF1Standings();
            break;
            case 19:
            searchRapidAPI();
            break;
            case 20:
            mapsSearch();
            break;
            case 21:
            fileFunc();
            break;
            case 22:
            googleTranslate();
            break;
            case 23:
            distance();
            break;
            case 24:
            ExerciseDb();
            break;
            default:
                std::cout << ANSI_COLOR_RED << "Opzione non valida.\n" << ANSI_COLOR_RESET;
                break;
        }
    }
}


void BMICalculator() {
    float weight, height;

    // Richiedi all'utente di inserire il peso in kg e l'altezza in metri
    std::cout << ANSI_COLOR_CYAN << "Inserisci il peso in kg: " << ANSI_COLOR_RESET;
    std::cin >> weight;
    std::cout << ANSI_COLOR_CYAN << "Inserisci l'altezza in metri: " << ANSI_COLOR_RESET;
    std::cin >> height;

    // Calcola il BMI utilizzando la formula: BMI = peso (kg) / altezza^2 (m^2)
    float bmi = weight / (height * height);

    // Stampa il BMI calcolato
    std::cout << "Il tuo BMI è: " << ANSI_COLOR_GREEN << bmi << ANSI_COLOR_RESET << std::endl;

    // Classifica il BMI in base alle categorie comuni
    if (bmi < 18.5) {
        std::cout << ANSI_COLOR_YELLOW << "Categoria: Sottopeso" << ANSI_COLOR_RESET << std::endl;
    } else if (bmi < 24.9) {
        std::cout << ANSI_COLOR_GREEN << "Categoria: Normale" << ANSI_COLOR_RESET << std::endl;
    } else if (bmi < 29.9) {
        std::cout << ANSI_COLOR_RED << "Categoria: Sovrappeso" << ANSI_COLOR_RESET << std::endl;
    } else {
        std::cout << ANSI_COLOR_MAGENTA << "Categoria: Obeso" << ANSI_COLOR_RESET << std::endl;
    }
}

void CalculateAreaAndPerimeter() {
    int choice;
    double side, length, width, radius, base, height, side1, side2, side3;

    std::cout << ANSI_COLOR_CYAN << "Scegli la figura geometrica:\n";
    std::cout << "1. Quadrato\n";
    std::cout << "2. Rettangolo\n";
    std::cout << "3. Cerchio\n";
    std::cout << "4. Triangolo\n";
    std::cout << "5. Trapezio\n" << ANSI_COLOR_RESET;
    std::cout << "Scelta: ";
    std::cin >> choice;
    std::cout << "******************************" << std::endl;

    switch (choice) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci la lunghezza del lato del quadrato: " << ANSI_COLOR_RESET;
            std::cin >> side;
            std::cout << "Area del quadrato: " << ANSI_COLOR_GREEN << side * side << ANSI_COLOR_RESET << std::endl;
            std::cout << "Perimetro del quadrato: " << ANSI_COLOR_GREEN << 4 * side << ANSI_COLOR_RESET << std::endl;
            break;

        case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci la lunghezza e la larghezza del rettangolo: " << ANSI_COLOR_RESET;
            std::cin >> length >> width;
            std::cout << "Area del rettangolo: " << ANSI_COLOR_GREEN << length * width << ANSI_COLOR_RESET << std::endl;
            std::cout << "Perimetro del rettangolo: " << ANSI_COLOR_GREEN << 2 * (length + width) << ANSI_COLOR_RESET << std::endl;
            break;

        case 3:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il raggio del cerchio: " << ANSI_COLOR_RESET;
            std::cin >> radius;
            std::cout << "Area del cerchio: " << ANSI_COLOR_GREEN << M_PI * radius * radius << ANSI_COLOR_RESET << std::endl;
            std::cout << "Circonferenza del cerchio: " << ANSI_COLOR_GREEN << 2 * M_PI * radius << ANSI_COLOR_RESET << std::endl;
            break;

        case 4:
            std::cout << ANSI_COLOR_CYAN << "Inserisci la base e l'altezza del triangolo: " << ANSI_COLOR_RESET;
            std::cin >> base >> height;
            std::cout << "Area del triangolo: " << ANSI_COLOR_GREEN << 0.5 * base * height << ANSI_COLOR_RESET << std::endl;
            std::cout << ANSI_COLOR_CYAN << "Inserisci i lati del triangolo: " << ANSI_COLOR_RESET;
            std::cin >> side1 >> side2 >> side3;
            std::cout << "Perimetro del triangolo: " << ANSI_COLOR_GREEN << side1 + side2 + side3 << ANSI_COLOR_RESET << std::endl;
            break;
        case 5:
            std::cout << ANSI_COLOR_CYAN << "Inserisci le lunghezze delle basi e l'altezza del trapezio: " << ANSI_COLOR_RESET;
            std::cin >> base >> side >> height;
            std::cout << "Area del trapezio: " << ANSI_COLOR_GREEN << 0.5 * (base + side) * height << ANSI_COLOR_RESET << std::endl;
            std::cout << "Perimetro del trapezio: " << ANSI_COLOR_GREEN << base + side + 2 * sqrt(pow((base - side) / 2, 2) + pow(height, 2)) << ANSI_COLOR_RESET << std::endl;
            break;           
        default:
            std::cout << ANSI_COLOR_RED << "Scelta non valida!" << ANSI_COLOR_RESET << std::endl;
            break;
    }
}


// Funzione per calcolare l'importo delle tasse in base al reddito e alle aliquote fiscali
double CalculateTax() {
    int percentTax;
    double income;

    std::cout << ANSI_COLOR_CYAN << "Inserisci l'importo del tuo reddito: " << ANSI_COLOR_RESET;
    std::cin >> income;

    if (std::cin.fail()) {
        std::cerr << ANSI_COLOR_RED << "Errore nell'input del reddito." << ANSI_COLOR_RESET << std::endl;
        return 0.0;
    }

    std::cout << ANSI_COLOR_CYAN << "Inserisci la percentuale della tua aliquota fiscale: " << ANSI_COLOR_RESET;
    std::cin >> percentTax;

    if (std::cin.fail() || percentTax < 0 || percentTax > 100) {
        std::cerr << ANSI_COLOR_RED << "Percentuale tassa non valida." << ANSI_COLOR_RESET << std::endl;
        return 0.0;
    }

    double tax = (income * percentTax) / 100.0;

    std::cout << "Le tue tasse sono pari a: " << ANSI_COLOR_GREEN << tax << ANSI_COLOR_RESET << std::endl;
    return tax;
}


float CalculateVolume() {
    float radius, height;
    float volume = 0.0;
    int shape;

    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del raggio: " << ANSI_COLOR_RESET;
    std::cin >> radius;

    std::cout << ANSI_COLOR_BLUE << "Decidi il tipo di figura:\n 1. Sfera\n 2. Cilindro\n 3. Cono\n" << ANSI_COLOR_RESET;
    std::cin >> shape;

    std::cout << "******************************" << std::endl;
    if (shape == 1) {
        // Sfera
        volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
        std::cout << ANSI_COLOR_GREEN << "Il volume misura: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << volume << ANSI_COLOR_RESET <<std::endl;
    } else if (shape == 2) {
        std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'altezza: " << ANSI_COLOR_RESET;
        std::cin >> height;
        // Cilindro
        volume = M_PI * radius * radius * height;
        std::cout << ANSI_COLOR_GREEN << "Il volume misura: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << volume << ANSI_COLOR_RESET <<std::endl;
    } else if (shape == 3) {
        std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'altezza: " << ANSI_COLOR_RESET;
        std::cin >> height;
        // Cono
        volume = 1.0 / 3.0 * M_PI * radius * radius * height;
        std::cout << ANSI_COLOR_GREEN << "Il volume misura: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << volume << ANSI_COLOR_RESET << std::endl;
    }else
    {
        std::cout << ANSI_COLOR_RED << "Tipo di figura non trovato" << ANSI_COLOR_RESET << std::endl;
    }
    
    return volume;
}


float CalculateSurface() {
    float radius, height, slantHeight;
    float surface = 0.0;
    int shape;

    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del raggio: " << ANSI_COLOR_RESET;
    std::cin >> radius;

    std::cout << ANSI_COLOR_BLUE << "Decidi il tipo di figura:\n 1. Sfera\n 2. Cilindro\n 3. Cono\n" << ANSI_COLOR_RESET;
    std::cin >> shape;

    std::cout << "******************************" << std::endl;

    if (shape == 1) {
        // Sfera
        surface = 4 * M_PI * radius * radius;
        std::cout << ANSI_COLOR_GREEN << "La superficie misura: " << ANSI_COLOR_YELLOW << surface << ANSI_COLOR_RESET << std::endl;
    } else if (shape == 2) {
        std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'altezza: " << ANSI_COLOR_RESET;
        std::cin >> height;
        // Cilindro
        surface = 2 * M_PI * radius * (radius + height);
        std::cout << ANSI_COLOR_GREEN << "La superficie misura: " << ANSI_COLOR_YELLOW << surface << ANSI_COLOR_RESET << std::endl;
    } else if (shape == 3) {
        std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'altezza: " << ANSI_COLOR_RESET;
        std::cin >> height;
        // Cono
        slantHeight = sqrt(radius * radius + height * height);
        surface = M_PI * radius * (radius + slantHeight);
        std::cout << ANSI_COLOR_GREEN << "La superficie misura: " << ANSI_COLOR_YELLOW << surface << ANSI_COLOR_RESET << std::endl;
    } else {
        std::cout << ANSI_COLOR_RED << "Tipo di figura non trovato" << ANSI_COLOR_RESET << std::endl;
    }

    return surface;
}


