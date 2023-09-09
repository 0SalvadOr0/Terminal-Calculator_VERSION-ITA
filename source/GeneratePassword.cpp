#include "..\include\GeneratePassword.hpp"

// Lista delle 200 password più comuni
const std::vector<std::string> commonPasswords = {
    "123456", "password", "123456789", "12345678", "12345", "1234567", "1234567890",
    "qwerty", "abc123", "111111", "123123", "admin", "letmein", "welcome", "monkey",
    "1234", "superman", "iloveyou", "sunshine", "baseball", "football", "1234567890",
    "password1", "password123", "123456a", "123456b", "123456c", "123456abc", "123abc",
    "abc1234", "abcd1234", "password12", "password1234", "welcome123", "starwars",
    "iloveyou1", "iloveyou2", "iloveyou3", "iloveyou123", "password!", "letmein1",
    "qwerty1", "qwerty123", "admin1", "admin123", "hello", "test", "trustno1", "123qwe",
    "123", "abc", "aaa", "bbb", "ccc", "password!", "password12", "password1234",
    "letmein!", "welcome1", "welcome123", "welcome!", "monkey1", "monkey12", "monkey123",
    "football1", "baseball1", "superman1", "iloveyou!", "sunshine1", "shadow", "master",
    "jennifer", "hockey", "mustang", "snoopy", "michael", "1234qwer", "1qaz2wsx",
    "access", "flower", "55555", "pass", "pass123", "adminadmin", "root", "1234abcd",
    "rootroot", "qwertyuiop", "123123123", "loveme", "welcome2", "abc123!", "1234qwer!",
    "letmein123", "dragon", "charlie", "buster", "thomas", "letmein2", "superman123",
    "iloveyou!", "sunshine1", "shadow1", "master1", "jennifer1", "hockey1", "mustang1",
    "snoopy1", "michael1", "password!", "password12", "password1234", "letmein!", "welcome1",
    "welcome123", "monkey1", "monkey12", "monkey123", "football1", "baseball1", "superman1",
    "iloveyou!", "sunshine1", "shadow", "master", "jennifer", "hockey", "mustang", "snoopy",
    "michael", "1234qwer", "1qaz2wsx", "access", "flower", "55555", "pass", "pass123",
    "adminadmin", "root", "1234abcd", "rootroot", "qwertyuiop", "123123123", "loveme",
    "welcome2", "abc123!", "1234qwer!", "letmein123", "dragon", "charlie", "buster", "thomas",
    "letmein2", "superman123", "sunshine123", "shadow123", "master123", "jennifer123",
    "hockey123", "mustang123", "snoopy123", "michael123", "password1!", "password12!",
    "password1234!", "letmein!", "welcome1!", "welcome123!", "monkey1!", "monkey12!", "monkey123!",
    "football1!", "baseball1!", "superman1!", "iloveyou!!", "sunshine1!", "shadow1!",
    "master1!", "jennifer1!", "hockey1!", "mustang1!", "snoopy1!", "michael1!"
};

// Definizione della funzione per generare password casuale
std::string generateRandomPassword(int length) {

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

PasswordStrength checkPasswordStrength(const std::string &password) {
    // Verifica la lunghezza della password
    if (password.length() < 8) {
        return Weak;
    }

    // Verifica la presenza di almeno una lettera maiuscola, una lettera minuscola e un numero
    if (!std::regex_search(password, std::regex("[A-Z]")) ||
        !std::regex_search(password, std::regex("[a-z]")) ||
        !std::regex_search(password, std::regex("[0-9]"))) {
        return Moderate;
    }

    // Verifica la complessità dei caratteri (presenza di caratteri speciali)
    if (!std::regex_search(password, std::regex("[!@#$%^&*()_+\\-=\\[\\]{};':\",./<>?\\\\|]"))) {
        return Moderate;
    }

    // Verifica la resistenza alle tecniche di attacco comuni (contro una lista di password comuni)
    if (std::find(commonPasswords.begin(), commonPasswords.end(), password) != commonPasswords.end()) {
        return Weak;
    }

    // Se ha superato tutte le verifiche, considerala una password forte
    return Strong;
}

void checkDecision(){
    int decision = 0;
    int passwordLength = 0; // Inizializzo la variabile passwordLength
    int choice;
    std::string password;

    std::cout << "******************************" << std::endl;

    std::cout << ANSI_COLOR_BLUE << "1. Generatore di password\n 2. Sicurezza della password\n" << ANSI_COLOR_RESET;
    std::cin >> decision;
    std::cout << "******************************" << std::endl;

           if(decision == 1){
    std::cout << ANSI_COLOR_BLUE << "Lunghezza della password:\n 1. 6 Caratteri\n 2. 8 Caratteri\n 3. 12 Caratteri\n 4. 24 caratteri\n" << ANSI_COLOR_RESET;
    std::cin >> choice;
    std::cout << "******************************" << std::endl;

    switch (choice) {
        case 1:
            passwordLength = 6;
            break;
        case 2:
            passwordLength = 8;
            break;
        case 3:
            passwordLength = 12;
            break;
        case 4:
             passwordLength = 24;
             break;
        default:
            std::cout << ANSI_COLOR_RED << "Scelta non valida." << ANSI_COLOR_RESET << std::endl;
            break;
    }

    if (passwordLength > 0) {
        std::string generatedPassword = generateRandomPassword(passwordLength);
        std::cout << ANSI_COLOR_GREEN << "Password generata con successo: " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << generatedPassword << ANSI_COLOR_RESET << std::endl;
        std::cout << ANSI_COLOR_MAGENTA << "Non mostrare la tua password a nessuno" << ANSI_COLOR_RESET << std::endl;
    }
           }
    else if (decision == 2)
    {
        std::cout << ANSI_COLOR_CYAN << "Inserisci la tua password: " << ANSI_COLOR_RESET;
        std::cin >> password;

    PasswordStrength strength = checkPasswordStrength(password);

    switch (strength) {
        case Weak:
            std::cout << ANSI_COLOR_RED << "La tua password e' debole." << ANSI_COLOR_RESET << std::endl;
            break;
        case Moderate:
            std::cout << ANSI_COLOR_YELLOW << "La tua password e' di media complessità." << ANSI_COLOR_RESET << std::endl;
            break;
        case Strong:
            std::cout << ANSI_COLOR_GREEN << "La tua password e' forte." << ANSI_COLOR_RESET << std::endl;
            break;
    }
    
    }
}