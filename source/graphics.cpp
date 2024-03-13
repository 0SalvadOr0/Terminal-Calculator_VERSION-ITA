#include "..\include\graphics.hpp"

void graphics2D(const std::string& y_expr, const std::string& title) {
    Gnuplot gp;
    try {
        gp << "set title '" << title << "'\n";
        gp << "set xlabel 'X'\n";
        gp << "set ylabel 'Y'\n";

        gp << "plot " << y_expr << '\n';

    } catch (const std::runtime_error& e) {
        std::cerr << "Errore durante la creazione del grafico: " << e.what() << std::endl;
    }
}

void graphics3D(const std::string& z_expr, const std::string& title) {
    Gnuplot gp;
    try {
        gp << "set title '" << title << "'\n";
        gp << "set xlabel 'X'\n";
        gp << "set ylabel 'Y'\n";
        gp << "set zlabel 'Z'\n";

        gp << "splot " << z_expr << '\n';
    } catch (const std::runtime_error& e) {
        std::cerr << "Errore durante la creazione del grafico 3D: " << e.what() << std::endl;
    }
}

void graphics() {
    std::string title, y, z;
    int choice;

    std::cout << "1. Grafico 2d\n 2. Grafico 3d\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        
    std::cout << "Inserisci il titolo del grafico: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);

    std::cout << "Inserisci l'espressione di y in termini di x: ";
    std::getline(std::cin, y);

    graphics2D(y, title);
        break;
    case 2:
    std::cout << "Inserisci il titolo del grafico 3D: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);

    std::cout << "Inserisci l'espressione di z in termini di x e y: ";
    std::getline(std::cin, z);

    graphics3D(z, title);
    break;
    default:
        break;
    }
}
