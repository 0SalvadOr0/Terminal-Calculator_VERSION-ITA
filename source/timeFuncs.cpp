// timeFuncs.cpp

#include "../include/timeFuncs.hpp"

void clearLine() {
    std::cout << "\r" << std::string(80, ' ') << "\r";
}

void printElapsedTime(const std::chrono::time_point<std::chrono::high_resolution_clock>& start) {
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start);
    clearLine();
    std::cout << "Tempo trascorso: " << duration.count() << " secondi" << std::flush;
}

void timer(int seconds) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + std::chrono::seconds(seconds);
    while (std::chrono::high_resolution_clock::now() < end) {
        printElapsedTime(start);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    printElapsedTime(start);
    std::cout << "\nTimer finito!\n";
    Beep(1500, 2000);
}

std::atomic<bool> click(false);

void getInput() {
    std::cin.get();
    click = true;
}

void cronograph() {
    std::thread inputThread(getInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    auto start = std::chrono::high_resolution_clock::now();
    while (!click) {
        printElapsedTime(start);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    clearLine();
    std::cout << "\nIl cronometro e' stato fermato dopo " << duration.count() << " secondi.\n";
}

int CalculateAge(const std::tm& birthDate) {
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);

    int age = currentDate->tm_year - birthDate.tm_year;
    if (currentDate->tm_mon < birthDate.tm_mon ||
        (currentDate->tm_mon == birthDate.tm_mon && currentDate->tm_mday < birthDate.tm_mday)) {
        age--;
    }

    return age;
}

void timeFuncs() {
    int seconds, choice;
    std::cout << "1. Timer\n2. Cronografo\n3. Calcolatore dell'eta'\nInserisci la tua scelta: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "Inserisci il numero di secondi per il timer: ";
        std::cin >> seconds;
        timer(seconds);
        break;
    case 2:
        cronograph();
        break;
    case 3:{
            std::cout << ANSI_COLOR_CYAN << "Inserisci la data di nascita (AAAA MM GG): " << ANSI_COLOR_RESET;
            std::tm birthDate = {};
            std::cin >> std::get_time(&birthDate, "%Y %m %d");

            if (std::cin.fail()) {
                std::cerr << ANSI_COLOR_RED << "Errore nell'input della data." << ANSI_COLOR_RESET << std::endl;
                break;
            }

            int age = CalculateAge(birthDate);
            std::cout << ANSI_COLOR_GREEN << "La tua età e': " << age << " anni." << ANSI_COLOR_RESET << std::endl;
            break;
        }
    default:
        std::cout << "Scelta non valida\n";
        break;
    }
}
