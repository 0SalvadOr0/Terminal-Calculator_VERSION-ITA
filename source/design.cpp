#include "..\include\design.hpp"


// Funzione per stampare il titolo stilizzato
void Title(){
// Stampa del titolo con caratteri speciali
std::cout << "******************************" << std::endl;
    std::cout << ANSI_COLOR_CYAN;
    std::cout << "  -----------------" << std::endl;
    std::cout << " |                  |" << std::endl;
    std::cout << "  -------   --------" << std::endl;
    std::cout << "        |   |     --------" << std::endl;
    std::cout << "        |   |    /  ------" << std::endl;
    std::cout << "        |   |    ||" << std::endl;
    std::cout << "        |   |    ||" << std::endl;
    std::cout << "         ---     ||" << std::endl;
    std::cout << "                 \\" << std::endl;
    std::cout << "                  --------" << std::endl;
    std::cout << ANSI_COLOR_RESET;
}


void Menu(){
    std::cout << "******************************" << std::endl;
    std::cout << ANSI_COLOR_YELLOW;
    std::cout << "Scegli l'opzione:" << std::endl;
    std::cout << " 0. " << ANSI_COLOR_GREEN << "Esci" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 1. " << ANSI_COLOR_GREEN << "Calcolatrice standard" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 2. " << ANSI_COLOR_GREEN << "Opzioni triangolo" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 3. " << ANSI_COLOR_GREEN << "Operazioni di trigonometria" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 4. " << ANSI_COLOR_GREEN << "Percentuali" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 5. " << ANSI_COLOR_GREEN << "Convertitore" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 6. " << ANSI_COLOR_GREEN << "Calcolo BMI" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 7. " << ANSI_COLOR_GREEN << "Calcolo Area e Perimetro" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 8. " << ANSI_COLOR_GREEN << "Funzioni orologio e eta'" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 9. " << ANSI_COLOR_GREEN << "Calcolatore delle tasse" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 10. " << ANSI_COLOR_GREEN << "Password" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 11. " << ANSI_COLOR_GREEN << "Calcolatore di volume e superficie" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 12. " << ANSI_COLOR_GREEN << "Espressioni" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 13. " << ANSI_COLOR_GREEN << "Equazioni" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 14. " << ANSI_COLOR_GREEN << "Statistica" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 15. " << ANSI_COLOR_GREEN << "Creazione di grafici" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 16. " << ANSI_COLOR_GREEN << "Meteo" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 17. " << ANSI_COLOR_GREEN << "Persone nello spazio" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 18. " << ANSI_COLOR_GREEN << "F1" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 19. " << ANSI_COLOR_GREEN << "Ricerche google" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 20. " << ANSI_COLOR_GREEN << "Ricerche google maps" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 21. " << ANSI_COLOR_GREEN << "Funzioni file" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 22. " << ANSI_COLOR_GREEN << "Traduttore" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 23. " << ANSI_COLOR_GREEN << "Distanza tra due punti sul globo" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << " 24. " << ANSI_COLOR_GREEN << "Esercizi per gruppo muscolare" << ANSI_COLOR_YELLOW << std::endl;
    std::cout << ANSI_COLOR_RESET;
}
