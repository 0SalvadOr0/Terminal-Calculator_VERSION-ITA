#include "trigoOperation.hpp"

// Definizione di M_PI se non è già definito
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Funzione per la calcolatrice scientifica
void ScientificCalculator() {
    int option;
    float value;

    while (true) {
        std::cout << "Scegli l'operazione:\n";
        std::cout << " 1. Esponenziale\n";
        std::cout << " 2. Logaritmo\n";
        std::cout << " 3. Seno\n";
        std::cout << " 4. Coseno\n";
        std::cout << " 5. Tangente\n";
        std::cout << " 6. Seno inverso\n";
        std::cout << " 7. Coseno inverso\n";
        std::cout << " 8. Tangente inversa\n";
        std::cout << " 9. Ritorna al menu principale\n";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Inserisci il valore: ";
                std::cin >> value;
                std::cout << "Esponenziale(" << value << "): " << std::exp(value) << std::endl;
                break;
            case 2:
                std::cout << "Inserisci il valore: ";
                std::cin >> value;
                std::cout << "Logaritmo naturale(" << value << "): " << std::log(value) << std::endl;
                break;
            case 3:
                std::cout << "Inserisci l'angolo in gradi: ";
                std::cin >> value;
                std::cout << "Seno(" << value << "): " << std::sin(value * M_PI / 180) << std::endl;
                break;
            case 4:
                std::cout << "Inserisci l'angolo in gradi: ";
                std::cin >> value;
                std::cout << "Coseno(" << value << "): " << std::cos(value * M_PI / 180) << std::endl;
                break;
            case 5:
                std::cout << "Inserisci l'angolo in gradi: ";
                std::cin >> value;
                std::cout << "Tangente(" << value << "): " << std::tan(value * M_PI / 180) << std::endl;
                break;
            case 6:
                std::cout << "Inserisci il valore: ";
                std::cin >> value;
                std::cout << "Seno inverso(" << value << "): " << std::asin(value) * 180 / M_PI << " deg" << std::endl;
                break;
            case 7:
                std::cout << "Inserisci il valore: ";
                std::cin >> value;
                std::cout << "Coseno inverso(" << value << "): " << std::acos(value) * 180 / M_PI << " deg" << std::endl;
                break;
            case 8:
                std::cout << "Inserisci il valore: ";
                std::cin >> value;
                std::cout << "Tangente inversa(" << value << "): " << std::atan(value) * 180 / M_PI << " deg" << std::endl;
                break;
            case 9:
                return;  // Ritorna al menu principale
            default:
                std::cout << "Opzione non valida.\n";
                break;
        }
    }
}