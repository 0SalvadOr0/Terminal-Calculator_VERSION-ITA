#include "..\include\equations.hpp"


//equazioni lineari del tipo ax + b = 0
double solveLinearEquation(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            std::cout << ANSI_COLOR_YELLOW << "L'equazione ha infinite soluzioni.\n" << ANSI_COLOR_RESET << std::endl;
        } else {
            std::cout << ANSI_COLOR_BLUE << "L'equazione non ha soluzioni.\n" << ANSI_COLOR_RESET  << std::endl;
        }
    } else {
        double solution = -b / a;
        std::cout << ANSI_COLOR_GREEN << "La soluzione dell'equazione " << ANSI_COLOR_YELLOW << a << "x + " << b << " = 0 e' " << ANSI_COLOR_RESET << " x = " << solution << ANSI_COLOR_RESET << std::endl;
        return solution;
    }
    return 0; // Se l'equazione è mal definita, restituisci 0.
}

float CramerSistemEquation() {
    float a1, b1, c1, a2, b2, c2, a3, b3, c3, det, detX, detY, detZ,x, y, z, d1, d2, d3;
    int choice;

    std::cout << "******************************" << std::endl;
    std::cout << ANSI_COLOR_MAGENTA << "Digita:\n 1. Sistema a 2 incognite\n 2. Sistema a 3 incognite\n" << ANSI_COLOR_RESET;

    std::cin >> choice;

    switch (choice)
    {
    case 1:
    // Inserisci i coefficienti delle tue equazioni
    std::cout << ANSI_COLOR_BLUE <<"Inserisci i coefficienti per la prima equazione (a1, b1, c1): ";
    std::cin >> a1 >> b1 >> c1;

    std::cout << "Inserisci i coefficienti per la seconda equazione (a2, b2, c2): ";
    std::cin >> a2 >> b2 >> c2;

    // Calcola il determinante del sistema
    det = a1*b2 - a2*b1;
    // Calcola i determinanti per x e y
    detX = c1*b2 - c2*b1;
    detY = a1*c2 - a2*c1;

    if (det == 0 && detX == 0 && detY == 0) {
        std::cout << ANSI_COLOR_MAGENTA << "Il sistema non ha una soluzione unica. Indeterminato\n" << ANSI_COLOR_RESET;
    }
    else if (det == 0 && detX != 0 && detY != 0)
    {
        std::cout << ANSI_COLOR_MAGENTA << "Il sistema non ha una soluzioni. Impossibile\n" << ANSI_COLOR_RESET;
    }  
    else {
        // Calcola le soluzioni
        x = detX / det;
        y = detY / det;

        std::cout << ANSI_COLOR_GREEN << "La soluzione del sistema e': x = " << x << ", y = " << y << ANSI_COLOR_RESET << '\n';
    }
        break;

    case 2:
        // Inserisci i coefficienti delle tue equazioni
    std::cout << ANSI_COLOR_BLUE <<"Inserisci i coefficienti per la prima equazione (a1, b1, c1): ";
    std::cin >> a1 >> b1 >> c1;

    std::cout << "Inserisci i coefficienti per la seconda equazione (a2, b2, c2): ";
    std::cin >> a2 >> b2 >> c2;

    std::cout << "Inserisci i coefficienti per la seconda equazione (a3, b3, c3): ";
    std::cin >> a3 >> b3 >> c3;

    std::cout << "Inserisci i termini noti (d1, d2, d3): ";
    std::cin >> d1 >> d2 >> d3;

    det = a1 * b2 * c3 + b1 * c2 * a3 + c1 * a2 * b3 - a3 * b2 * c1 - b3 * c2 * a1 - c3 * a2 * b1;
    
    detX = d1 * b2 * c3 + b1 * c2 * d3 + c1 * d2 * b3 - d3 * b2 * c1 - b3 * c2 * d1 - c3 * d2 * b1;
    detY = a1 * d2 * c3 + d1 * c2 * a3 + c1 * a2 * d3 - a3 * d2 * c1 - d3 * c2 * a1 - c3 * a2 * d1;
    detZ = a1 * b2 * d3 + b1 * d2 * a3 + d1 * a2 * b3 - a3 * b2 * d1 - b3 * d2 * a1 - d3 * a2 * b1;

    if (det == 0 && detX == 0 && detY == 0 && detZ == 0) {
        std::cout << ANSI_COLOR_MAGENTA << "Il sistema non ha una soluzione unica. Indeterminato\n" << ANSI_COLOR_RESET;
    }
    else if (det == 0 && detX != 0 && detY != 0 && detZ == 0)
    {
        std::cout << ANSI_COLOR_MAGENTA << "Il sistema non ha una soluzioni. Impossibile\n" << ANSI_COLOR_RESET;
    }  
    else {
        // Calcola le soluzioni
        x = detX / det;
        y = detY / det;
        z = detZ / det;

        std::cout << ANSI_COLOR_GREEN << "La soluzione del sistema e': x = " << x << ", y = " << y << ", z = " << z <<ANSI_COLOR_RESET << '\n';
    }
        break;

    default:
    std::cout << ANSI_COLOR_RED << "Opzione non valida.\n" << ANSI_COLOR_RESET;
        break;
    }

    return 0;
}

//ax^2+bx+c=0
void solveQuadratic() {
    double a, b, c;

    std::cout << "Inserisci il valore del coefficiente a: ";
    std::cin >> a;
    std::cout << "Inserisci il valore del coefficiente b: ";
    std::cin >> b;
    std::cout << "Inserisci il valore del valore c: ";
    std::cin >> c;

    double discriminant = b*b - 4*a*c;


    if (discriminant < 0) {
        std::cout << "L'equazione non ha soluzioni reali.\n";
    } else {
        double x1 = (-b + std::sqrt(discriminant)) / (2*a);
        double x2 = (-b - std::sqrt(discriminant)) / (2*a);
        std::cout << "Le soluzioni dell'equazione sono " << x1 << " e " << x2 << ".\n";
    }
}
