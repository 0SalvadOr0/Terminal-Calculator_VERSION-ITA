#include "..\include\operation.hpp"

void addition(float &a, float &b) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci primo valore: " << ANSI_COLOR_RESET;
    std::cin >> a;
    std::cout << ANSI_COLOR_CYAN << "Inserisci secondo valore: " << ANSI_COLOR_RESET;
    std::cin >> b;
    std::cout << "Risultato dell'addizione: " << ANSI_COLOR_GREEN << a + b << ANSI_COLOR_RESET << std::endl;
}

void subtraction(float &a, float &b) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci primo valore: " << ANSI_COLOR_RESET;
    std::cin >> a;
    std::cout << ANSI_COLOR_CYAN << "Inserisci secondo valore: " << ANSI_COLOR_RESET;
    std::cin >> b;
    std::cout << "Risultato della sottrazione: " << ANSI_COLOR_GREEN << a - b << ANSI_COLOR_RESET << std::endl;
}

void multiplication(float &a, float &b) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci primo valore: " << ANSI_COLOR_RESET;
    std::cin >> a;
    std::cout << ANSI_COLOR_CYAN << "Inserisci secondo valore: " << ANSI_COLOR_RESET;
    std::cin >> b;
    std::cout << "Risultato della moltiplicazione: " << ANSI_COLOR_GREEN << a * b << ANSI_COLOR_RESET << std::endl;
}

void division(float &a, float &b) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci primo valore: " << ANSI_COLOR_RESET;
    std::cin >> a;
    std::cout << ANSI_COLOR_CYAN << "Inserisci secondo valore: " << ANSI_COLOR_RESET;
    std::cin >> b;

    if (b == 0) {
        std::cout << ANSI_COLOR_RED << "Divisione per zero non consentita." << ANSI_COLOR_RESET << std::endl;
    } else {
        std::cout << "Risultato della divisione: " << ANSI_COLOR_GREEN << a / b << ANSI_COLOR_RESET << std::endl;
    }
}

void Pow(float &a, float &b) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci il primo valore: " << ANSI_COLOR_RESET;
    std::cin >> a;
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore della potenza: " << ANSI_COLOR_RESET;
    std::cin >> b;
    std::cout << "Risultato finale: " << ANSI_COLOR_GREEN << std::pow(a, b) << ANSI_COLOR_RESET << std::endl;
}

void Sqrt(float &a) {
    std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
    std::cin >> a;

    if (a < 0) {
        std::cout << ANSI_COLOR_RED << "Valore negativo, impossibile calcolare la radice quadrata." << ANSI_COLOR_RESET << std::endl;
    } else {
        std::cout << "Risultato finale: " << ANSI_COLOR_GREEN << std::sqrt(a) << ANSI_COLOR_RESET << std::endl;
    }
}

void Triangle() {
    int t_option;
    std::cout << ANSI_COLOR_MAGENTA << "Scegli l'opzione:\n 1. Calcola il cateto\n 2. Calcola l'ipotenusa\n" << ANSI_COLOR_RESET;
    std::cin >> t_option;
    
    float a, b, c;
    
    switch (t_option) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'ipotenusa: " << ANSI_COLOR_RESET;
            std::cin >> a;
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto: " << ANSI_COLOR_RESET;
            std::cin >> b;
            c = std::sqrt(pow(a, 2) - pow(b, 2));
            std::cout << "Il cateto misura: " << ANSI_COLOR_GREEN << c << ANSI_COLOR_RESET << std::endl;
            break;
        case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto maggiore: " << ANSI_COLOR_RESET;
            std::cin >> a;
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto minore: " << ANSI_COLOR_RESET;
            std::cin >> b;
            c = std::sqrt(pow(a, 2) + pow(b, 2));
            std::cout << "Il cateto misura: " << ANSI_COLOR_GREEN << c << ANSI_COLOR_RESET << std::endl;
            break;
        default:
            std::cout << ANSI_COLOR_RED << "Opzione non valida" << ANSI_COLOR_RESET << std::endl;
            break;
    }
}

void PercentageCalculations() {
    int choice;
    float initialValue, percentage, result;

    std::cout << ANSI_COLOR_MAGENTA << "Scegli l'operazione:\n 1. Calcola la variazione percentuale\n 2. Calcola lo sconto\n" << ANSI_COLOR_RESET;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore iniziale: " << ANSI_COLOR_RESET;
            std::cin >> initialValue;
            std::cout << ANSI_COLOR_CYAN << "Inserisci la percentuale di variazione: " << ANSI_COLOR_RESET;
            std::cin >> percentage;
            result = initialValue * (percentage / 100);
            std::cout << "Variazione percentuale: " << ANSI_COLOR_GREEN << result << ANSI_COLOR_RESET << std::endl;
            break;
        case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il prezzo originale: " << ANSI_COLOR_RESET;
            std::cin >> initialValue;
            std::cout << ANSI_COLOR_CYAN << "Inserisci lo sconto in percentuale: " << ANSI_COLOR_RESET;
            std::cin >> percentage;
            result = initialValue - (initialValue * (percentage / 100));
            std::cout << "Prezzo dopo lo sconto: " << ANSI_COLOR_GREEN << result << ANSI_COLOR_RESET << std::endl;
            break;
        default:
            std::cout << ANSI_COLOR_RED << "Opzione non valida." << ANSI_COLOR_RESET << std::endl;
            break;
    }
}