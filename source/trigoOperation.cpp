#include "..\include\trigoOperation.hpp"

// Definizione di M_PI se non è già definito
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Funzione per la calcolatrice scientifica
void ScientificCalculator() {
    int option;
    float value;

    while (true) {
        std::cout << ANSI_COLOR_MAGENTA << "Scegli l'operazione:\n";
        std::cout << " 1. Esponenziale\n";
        std::cout << " 2. Logaritmo\n";
        std::cout << " 3. Seno\n";
        std::cout << " 4. Coseno\n";
        std::cout << " 5. Tangente\n";
        std::cout << " 6. Seno inverso\n";
        std::cout << " 7. Coseno inverso\n";
        std::cout << " 8. Tangente inversa\n";
        std::cout << " 9. Ritorna al menu principale\n" << ANSI_COLOR_RESET;
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Esponenziale(" << value << "): " << ANSI_COLOR_GREEN << std::exp(value) << ANSI_COLOR_RESET << std::endl;
                break;
            case 2:
                std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Logaritmo naturale(" << value << "): " << ANSI_COLOR_GREEN << std::log(value) << ANSI_COLOR_RESET << std::endl;
                break;
            case 3:
                std::cout << ANSI_COLOR_CYAN << "Inserisci l'angolo in gradi: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Seno(" << value << "): " << ANSI_COLOR_GREEN << std::sin(value * M_PI / 180) << ANSI_COLOR_RESET << std::endl;
                break;
            case 4:
                std::cout << ANSI_COLOR_CYAN << "Inserisci l'angolo in gradi: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Coseno(" << value << "): " << ANSI_COLOR_GREEN << std::cos(value * M_PI / 180) << ANSI_COLOR_RESET << std::endl;
                break;
            case 5:
                std::cout << ANSI_COLOR_CYAN << "Inserisci l'angolo in gradi: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Tangente(" << value << "): " << ANSI_COLOR_GREEN << std::tan(value * M_PI / 180) << ANSI_COLOR_RESET << std::endl;
                break;
            case 6:
                std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Seno inverso(" << value << "): " << ANSI_COLOR_GREEN << std::asin(value) * 180 / M_PI << " deg" << ANSI_COLOR_RESET << std::endl;
                break;
            case 7:
                std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Coseno inverso(" << value << "): " << ANSI_COLOR_GREEN << std::acos(value) * 180 / M_PI << " deg" << ANSI_COLOR_RESET << std::endl;
                break;
            case 8:
                std::cout << ANSI_COLOR_CYAN << "Inserisci il valore: " << ANSI_COLOR_RESET;
                std::cin >> value;
                std::cout << "Tangente inversa(" << value << "): " << ANSI_COLOR_GREEN << std::atan(value) * 180 / M_PI << " deg" << ANSI_COLOR_RESET << std::endl;
                break;
            case 9:
                return;  // Ritorna al menu principale
            default:
                std::cout << ANSI_COLOR_RED << "Opzione non valida.\n" << ANSI_COLOR_RESET;
                break;
        }
    }
}