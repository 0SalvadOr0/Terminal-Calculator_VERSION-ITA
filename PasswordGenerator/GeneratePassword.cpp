#include "GeneratePassword.hpp"

// Definizione della funzione per generare password casuale
std::string generateRandomPassword(int length) {
    int choice,  passwordLenght;

    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numericChars = "0123456789";
    const std::string specialChars = "!@#$%^&*()-_+=<>?";

    const std::string allChars = lowercaseChars + uppercaseChars + numericChars + specialChars;

    std::string password;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, allChars.length() - 1);

    for (int i = 0; i < length; ++i) {
        int randomIndex = distrib(gen);
        password += allChars[randomIndex];
    }

    return password;
}