#include "..\include\equations.hpp"


//equazioni lineari del tipo ax + b = 0
double solveLinearEquation(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            std::cout << ANSI_COLOR_YELLOW << "L'equazione ha infinite soluzioni." << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_BLUE << "L'equazione non ha soluzioni." << ANSI_COLOR_RESET  << std::endl;
        }
    } else {
        double solution = -b / a;
        std::cout << ANSI_COLOR_GREEN << "La soluzione dell'equazione " << ANSI_COLOR_YELLOW << a << "x + " << b << " = 0 e' " << ANSI_COLOR_RESET << " x = " << solution << ANSI_COLOR_RESET << std::endl;
        return solution;
    }
    return 0; // Se l'equazione è mal definita, restituisci 0.
}