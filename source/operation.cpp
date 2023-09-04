#include "..\include\operation.hpp"

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