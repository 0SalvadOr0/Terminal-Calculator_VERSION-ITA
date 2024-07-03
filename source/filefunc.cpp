#include "..\include\filefunc.hpp"

void leggiDaFile(const char* nomeFile) {
    FILE *f1;
    char contenuto[1000]; // Assumendo che il file non superi i 1000 caratteri

    f1 = fopen(nomeFile, "r");

    if (f1 == NULL) {
        printf("Non è stato possibile aprire il file\n");
        return;
    }

    while (fgets(contenuto, sizeof(contenuto), f1)) {
        printf("%s", contenuto);
    }

    fclose(f1);
}

void scriviSuFile(const char* nomeFile, const char* contenuto) {
    FILE *f1;

    // Apri il file in modalità scrittura
    f1 = fopen(nomeFile, "w");
    if (f1 == NULL) {
        printf("Non è stato possibile aprire il file\n");
        return;
    }

    // Scrivi il contenuto sul file
    while (*contenuto) {
        fputc(*contenuto++, f1);
    }

    // Chiudi il file
    fclose(f1);
}

void cancellaContenuto(const char* nomeFile) {
    FILE *f1;

    // Apri il file in modalità scrittura
    f1 = fopen(nomeFile, "w");
    if (f1 == NULL) {
        printf("Non è stato possibile aprire il file\n");
        return;
    }

    // Chiudi il file (questo cancellerà il contenuto)
    fclose(f1);
}

void fileFunc(){
    std::string nomeFile, cont;
    std::cout << "Inserisci il nome del file: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nomeFile);
    std::cout << "1. Crea e/o Scrivi sul file\n 2. Leggi il file\n 3. Cancella il contenuto del file";
    std::cout << "\n Scegli l'opzione: ";
    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
        std::cout << "Inserisci il contenuto che vuoi scrivere: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, cont);
        scriviSuFile(nomeFile.c_str(), cont.c_str());
        break;
    case 2:
        leggiDaFile(nomeFile.c_str());
        break;
    case 3:
        cancellaContenuto(nomeFile.c_str());
        break;
    default:
        break;
    }
}
