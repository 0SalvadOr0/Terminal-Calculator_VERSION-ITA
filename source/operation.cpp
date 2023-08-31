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