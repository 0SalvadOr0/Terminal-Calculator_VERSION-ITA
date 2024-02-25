#include "..\include\graphics.hpp"

void graphics(const std::string& y_expr){
    Gnuplot gp;
    try {
        gp << "plot " << y_expr << '\n';
    } catch (const std::runtime_error& e) {
        std::cerr << "Errore durante la creazione del grafico: " << e.what() << std::endl;
    }
}