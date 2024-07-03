#include "..\include\operation.hpp"

template<typename T>
inline T addition(const std::vector<T>& nums) {
    T sum = 0;
    for (const auto &num : nums) {
        sum += num;
    }
    return sum;
}

template<typename T>
inline T subtraction(const std::vector<T>& nums) {
    T result = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        result -= nums[i];
    }
    return result;
}

template<typename T>
inline T multiplication(const std::vector<T>& nums) {
    T result = 1;
    for (const auto &num : nums) {
        result *= num;
    }
    return result;
}

template<typename T>
inline T division(const std::vector<T>& nums) {
    T result = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] == 0) {
            std::cout << "Divisione per zero non consentita." << std::endl;
            return 0;
        }
        result /= nums[i];
    }
    return result;
}

template<typename T>
inline T pow(T base, T exponent) {
    return std::pow(base, exponent);
}

template<typename T>
inline T sqrt(T num) {
    if (num < 0) {
        std::cout << "Valore negativo, impossibile calcolare la radice quadrata." << std::endl;
        return 0;
    }
    return std::sqrt(num);
}

void operation() {
    std::vector<double> nums;
    int arg;
    double num;

    int choice;
    std::cout << "******************************" << std::endl;
    std::cout << ANSI_COLOR_CYAN;
    std::cout << "1. Addizione\n";
    std::cout << "2. Sottrazione\n";
    std::cout << "3. Moltiplicazione\n";
    std::cout << "4. Divisione\n";
    std::cout << "5. Potenza\n";
    std::cout << "6. Radice quadrata\n";
    std::cout << "Scegli l'operazione da eseguire:\n" << ANSI_COLOR_RESET;
    std::cin >> choice;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
    {
        std::cout << ANSI_COLOR_YELLOW << "Inserisci quanti numeri vuoi immettere: " << ANSI_COLOR_RESET;
        std::cin >> arg;

        for(int i = 0; i < arg; i++) {
            std::cout << ANSI_COLOR_BLUE << "Inserisci il numero " << i+1 << ": " << ANSI_COLOR_RESET;
            std::cin >> num;
            nums.push_back(num);
        }
        switch(choice) {
            case 1:
                std::cout << ANSI_COLOR_GREEN << "Risultato dell'addizione: " << addition(nums) << ANSI_COLOR_RESET << std::endl;
            break;
            case 2:
                std::cout << ANSI_COLOR_GREEN << "Risultato della sottrazione: " << subtraction(nums) << ANSI_COLOR_RESET << std::endl;
            break;
            case 3:
                std::cout << ANSI_COLOR_GREEN<< "Risultato della moltiplicazione: " << multiplication(nums) << ANSI_COLOR_RESET << std::endl;
            break;
            case 4:
                std::cout << ANSI_COLOR_GREEN << "Risultato della divisione: " << division(nums) << ANSI_COLOR_RESET << std::endl;
            break;
            default:
                std::cout << ANSI_COLOR_RED << "Scelta non valida.\n" << ANSI_COLOR_RESET;
            break;
    }}
    else if (choice == 5 || choice == 6)
    {
        switch (choice)
        {
        case 5:
            float base, exponent;
            std::cout << ANSI_COLOR_MAGENTA << "Inserisci la base per la potenza: " << ANSI_COLOR_RESET;
            std::cin >> base;
            std::cout << ANSI_COLOR_MAGENTA << "Inserisci l'esponente per la potenza: " << ANSI_COLOR_RESET;
            std::cin >> exponent;
            std::cout << ANSI_COLOR_GREEN << "Risultato della potenza: " << pow(base, exponent) << ANSI_COLOR_RESET << std::endl;
            break;
        case 6:
            float radicand;
            std::cout << ANSI_COLOR_MAGENTA << "Inserisci il radicando per la radice quadrata: " << ANSI_COLOR_RESET;
            std::cin >> radicand;
            std::cout << ANSI_COLOR_GREEN << "Risultato della radice quadrata: " << sqrt(radicand) << ANSI_COLOR_RESET << std::endl;
            break;
        default:
            std::cout << ANSI_COLOR_RED << "Scelta non valida." << ANSI_COLOR_RESET << std::endl;
            break;
        }
    }   
    }

void Triangle() {
    int t_option;
    std::cout << ANSI_COLOR_MAGENTA << "Scegli l'opzione:\n 1. Calcola il cateto\n 2. Calcola l'ipotenusa\n" << ANSI_COLOR_RESET;
    std::cin >> t_option;
    
    float a, b, c;
    
    switch (t_option) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore dell'ipotenusa: " << ANSI_COLOR_RESET;
            std::cin >> a;
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto: " << ANSI_COLOR_RESET;
            std::cin >> b;
            c = std::sqrt(pow(a, 2) - pow(b, 2));
            std::cout << "Il cateto misura: " << ANSI_COLOR_GREEN << c << ANSI_COLOR_RESET << std::endl;
            break;
        case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto maggiore: " << ANSI_COLOR_RESET;
            std::cin >> a;
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore del cateto minore: " << ANSI_COLOR_RESET;
            std::cin >> b;
            c = std::sqrt(pow(a, 2) + pow(b, 2));
            std::cout << "Il cateto misura: " << ANSI_COLOR_GREEN << c << ANSI_COLOR_RESET << std::endl;
            break;
        default:
            std::cout << ANSI_COLOR_RED << "Opzione non valida" << ANSI_COLOR_RESET << std::endl;
            break;
    }
}

void PercentageCalculations() {
    int choice;
    float initialValue, percentage, result;

    std::cout << ANSI_COLOR_MAGENTA << "Scegli l'operazione:\n 1. Calcola la variazione percentuale\n 2. Calcola lo sconto\n" << ANSI_COLOR_RESET;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il valore iniziale: " << ANSI_COLOR_RESET;
            std::cin >> initialValue;
            std::cout << ANSI_COLOR_CYAN << "Inserisci la percentuale di variazione: " << ANSI_COLOR_RESET;
            std::cin >> percentage;
            result = initialValue * (percentage / 100);
            std::cout << "Variazione percentuale: " << ANSI_COLOR_GREEN << result << ANSI_COLOR_RESET << std::endl;
            break;
        case 2:
            std::cout << ANSI_COLOR_CYAN << "Inserisci il prezzo originale: " << ANSI_COLOR_RESET;
            std::cin >> initialValue;
            std::cout << ANSI_COLOR_CYAN << "Inserisci lo sconto in percentuale: " << ANSI_COLOR_RESET;
            std::cin >> percentage;
            result = initialValue - (initialValue * (percentage / 100));
            std::cout << "Prezzo dopo lo sconto: " << ANSI_COLOR_GREEN << result << ANSI_COLOR_RESET << std::endl;
            break;
        default:
            std::cout << ANSI_COLOR_RED << "Opzione non valida." << ANSI_COLOR_RESET << std::endl;
            break;
    }
}