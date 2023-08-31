#include "..\include\design.hpp"

// Funzione per stampare il titolo stilizzato
void Title(){
// Stampa del titolo con caratteri speciali
std::cout<<"******************************"<<std::endl;
std::cout<<"  ----------------- "<<std::endl;
std::cout<<" |                  | "<<std::endl;
std::cout<<"  -------   --------  "<<std::endl;
std::cout<<"        |   |     -------- "<<std::endl;
std::cout<<"        |   |    /  ------ "<<std::endl;
std::cout<<"        |   |    || "<<std::endl;
std::cout<<"        |   |    || "<<std::endl;
std::cout<<"         ---     || "<<std::endl;
std::cout<<"                 \\ "<<std::endl;
std::cout<<"                  --------"<<std::endl;
std::cout<<"******************************"<<std::endl;
}


void Menu(){
    std::cout << "******************************" << std::endl;
    std::cout << "Scegli l'opzione:\n";
    std::cout << " 1. Addizione\n";
    std::cout << " 2. Sottrazione\n";
    std::cout << " 3. Moltiplicazione\n";
    std::cout << " 4. Divisione\n";
    std::cout << " 5. Potenza\n";
    std::cout << " 6. Radice quadrata\n";
    std::cout << " 7. Opzioni triangolo\n";
    std::cout << " 8. Operazioni di trigonometria\n";
    std::cout << " 9. Percentuali\n";
    std::cout << " 10. Convertitore\n";
    std::cout << " 11. Calcolo BMI\n"; // Aggiunta dell'opzione per il calcolo del BMI
    std::cout << " 12. Calcolo Area e Perimetro\n";
    std::cout << " 13. Calcolatore dell'eta'\n";
    std::cout << " 14. Calcolatore delle tasse\n";
    std::cout << " 15. Generatore di Password\n";
    std::cout << " 16. Calcolatore di volume e superficie\n";
    std::cout << " 17. Esci\n"; // Aggiornamento del numero dell'opzione "Esci"
    std::cout << "******************************"<<std::endl;;
}
