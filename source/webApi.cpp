#include "../include/webApi.hpp"

std::map<std::string, std::string> loadConfig(const std::string& filename) {
    std::map<std::string, std::string> config;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            config[key] = value;
        }
    }
    return config;
}


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size*nmemb;
    size_t oldLength = s->size();
    try {
        s->resize(oldLength + newLength);
    }
    catch(std::bad_alloc &e) {
        return 0;
    }

    std::copy((char*)contents,(char*)contents+newLength,s->begin()+oldLength);
    return size*nmemb;
}

json getWeatherData(const std::string& city, std::string apikey) {
    std::string url = "https://api.tomorrow.io/v4/weather/realtime?location=" + city + "&apikey=" + apikey;
    CURL* curl = curl_easy_init();
    CURLcode res;
    std::string readBuffer;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        // Abilita la verifica del certificato SSL
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        // Usa i certificati CA di Windows quando si costruisce con OpenSSL
        curl_easy_setopt(curl, CURLOPT_SSL_OPTIONS, CURLSSLOPT_NATIVE_CA);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            json j = json::parse(readBuffer);
            return j;
        }
    }

    return {};
}

void weather() {
    std::string city;

    std::map<std::string, std::string> config = loadConfig("config.txt");
    std::string rapidApiKey = config["WeatherAPIKey"];


    std::cout << ANSI_COLOR_MAGENTA << "Inserisci il nome della citta: " << ANSI_COLOR_RESET;
    std::cin >> city;

    json weatherData = getWeatherData(city, rapidApiKey);

if (!weatherData.empty()) {
    std::string time = weatherData["data"]["time"].get<std::string>();
    double temperature = weatherData["data"]["values"]["temperature"].get<double>();
    double humidity = weatherData["data"]["values"]["humidity"].get<double>();
    double windspeed = weatherData["data"]["values"]["windSpeed"].get<double>();
    double lat = weatherData["location"]["lat"].get<double>();
    double lon = weatherData["location"]["lon"].get<double>();

    std::cout << "Meteo in " << city << " all' ora: " << time << ":" << std::endl;
    std::cout << "Latitudine: " << lat << " Longitudine: " << lon << std::endl;
    std::cout << "Temperatura: " << temperature << " C" << std::endl;
    std::cout << "Umidita': " << humidity << "%" << std::endl;
    std::cout << "Velocita' del vento a: " << windspeed << " km/h" << std::endl;

} else {
    std::cout << "Failed to get weather data" << std::endl;
}

}

void SpacePerson() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://api.open-notify.org/astros.json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            json j = json::parse(readBuffer);
            std::cout << "Number di persone nello spazio: " << j["number"] << std::endl;
            for (auto& person : j["people"]) {
                std::cout << person["name"] << " is on " << person["craft"] << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void GetF1Standings() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        // Aggiungi l'URL dell'API della Formula 1 per ottenere le classifiche
        curl_easy_setopt(curl, CURLOPT_URL, "https://ergast.com/api/f1/current/driverStandings.json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        // Abilita la verifica del certificato SSL
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        // Usa i certificati CA di Windows quando si costruisce con OpenSSL
        curl_easy_setopt(curl, CURLOPT_SSL_OPTIONS, CURLSSLOPT_NATIVE_CA);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            json j;
            try {
                j = json::parse(readBuffer);
            } catch(const std::exception& e) {
                std::cerr << "Errore durante il parsing del JSON: " << e.what() << std::endl;
                return;
            }

            // Estrai e stampa la classifica del campionato piloti
            if (j.find("MRData") != j.end() && j["MRData"].find("StandingsTable") != j["MRData"].end()) {
                auto standings = j["MRData"]["StandingsTable"]["StandingsLists"][0]["DriverStandings"];
                std::cout << "Classifica del campionato piloti:" << std::endl;
                for (const auto& driver : standings) {
                    std::cout << driver["position"] << ". " << driver["Driver"]["givenName"] << " " << driver["Driver"]["familyName"] << " - " << driver["points"] << " punti" << std::endl;
                }
            } else {
                std::cerr << "Errore: dati non trovati o formato non valido." << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void searchRapidAPI() {
    std::map<std::string, std::string> config = loadConfig("config.txt");
    std::string rapidApiKey = config["X-RapidAPI-Key"];

    CURL* hnd = curl_easy_init();

    std::string query;
    std::cout << "Inserisci la tua query di ricerca: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, query);  // Usa getline per consentire query multi-parola

    // Sostituisci gli spazi nella query con '%20' per la corretta formattazione dell'URL
    size_t spacePos = query.find(' ');
    while (spacePos != std::string::npos) {
        query.replace(spacePos, 1, "%20");
        spacePos = query.find(' ', spacePos + 3);
    }

    std::string url = "https://google-search72.p.rapidapi.com/search?q=" + query + "&gl=it&lr=lang_it&num=10&start=0";
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "X-RapidAPI-Key: "+ rapidApiKey);
    headers = curl_slist_append(headers, "X-RapidAPI-Host: google-search72.p.rapidapi.com");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    std::string readBuffer;
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &readBuffer);
    // Abilita la verifica del certificato SSL
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 1L);
    // Usa i certificati CA di Windows quando si costruisce con OpenSSL
    curl_easy_setopt(hnd, CURLOPT_SSL_OPTIONS, CURLSSLOPT_NATIVE_CA);

    CURLcode ret = curl_easy_perform(hnd);

    if (ret != CURLE_OK) {
        std::cerr << "Errore durante la richiesta HTTP: " << curl_easy_strerror(ret) << std::endl;
    } else {
        // Analizza la risposta JSON
        json root = json::parse(readBuffer);
        const json& items = root["items"];
        for (const auto& result : items) {
            std::string title = result["title"].get<std::string>();
            std::string description = result["snippet"].get<std::string>();
            std::string resUrl = result["link"].get<std::string>();
            std::cout << "Titolo: " << title << std::endl;
            std::cout << "Url: " << resUrl << std::endl;
            std::cout << "Descrizione: " << description << std::endl;
            std::cout << std::endl;
        }
    }

        // Cleanup
    curl_easy_cleanup(hnd);
    curl_slist_free_all(headers);
}

void mapsSearch() {
    std::string city;
    std::cout << "Inserisci il nome della città: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, city);

    // Mostra un menu con diverse opzioni
    std::cout << "1. Vai direttamente alla città\n";
    std::cout << "2. Visualizza i ristoranti\n";
    std::cout << "3. Visualizza gli hotel\n";
    std::cout << "4. Visualizza i musei\n";
    std::cout << "5. Visualizza i parchi\n";
    std::cout << "6. Visualizza i cinema\n";
    std::cout << "Scegli un'opzione:";
    // Aggiungi qui altre opzioni...

    int option;
    std::cin >> option;

    switch(option) {
    case 1: {
        // Vai direttamente alla città
        std::string command = "start https://www.google.com/maps/place/" + city;
        system(command.c_str());
        break;
    }
    case 2: {
        // Visualizza i ristoranti
        std::string command = "start https://www.google.com/maps/search/ristoranti+" + city;
        system(command.c_str());
        break;
    }
    case 3: {
        // Visualizza gli hotel
        std::string command = "start https://www.google.com/maps/search/hotel+" + city;
        system(command.c_str());
        break;
    }
    case 4: {
        // Visualizza i musei
        std::string command = "start https://www.google.com/maps/search/musei+" + city;
        system(command.c_str());
        break;
    }
    case 5: {
        // Visualizza i parchi
        std::string command = "start https://www.google.com/maps/search/parchi+" + city;
        system(command.c_str());
        break;
    }
    case 6: {
        // Visualizza i cinema
        std::string command = "start https://www.google.com/maps/search/cinema+" + city;
        system(command.c_str());
        break;
    }
    default:
        std::cout << ANSI_COLOR_RED << "Errrore: Funziona inesistente" << ANSI_COLOR_RESET;
        break;
    // Gestisci qui altre opzioni...
}
}

CURLcode translate(std::string text, std::string sourceLang, std::string targetLang, std::string& translatedText) {
    std::map<std::string, std::string> config = loadConfig("config.txt");
    std::string rapidApiKey = config["X-RapidAPI-Key"];

    CURL *hnd = curl_easy_init();
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, "https://google-translate1.p.rapidapi.com/language/translate/v2");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "content-type: application/x-www-form-urlencoded");
    headers = curl_slist_append(headers, "Accept-Encoding: application/gzip");
    headers = curl_slist_append(headers, "X-RapidAPI-Key: "+ rapidApiKey);
    headers = curl_slist_append(headers, "X-RapidAPI-Host: google-translate1.p.rapidapi.com");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    std::string postFields = "q=" + text + "&target=" + targetLang + "&source=" + sourceLang;
    curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, postFields.c_str());

    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &translatedText);
    // Abilita la verifica del certificato SSL
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 1L);
    // Usa i certificati CA di Windows quando si costruisce con OpenSSL
    curl_easy_setopt(hnd, CURLOPT_SSL_OPTIONS, CURLSSLOPT_NATIVE_CA);

    CURLcode ret = curl_easy_perform(hnd);

    // Cleanup
    curl_slist_free_all(headers);
    curl_easy_cleanup(hnd);

    return ret;
}

std::string getTranslatedText(const std::string& jsonResponse) {
    json j = json::parse(jsonResponse);
    std::string translatedText = j["data"]["translations"][0]["translatedText"];
    return translatedText;
}

void googleTranslate() {
    std::string text;
    std::cout << "Inserisci il testo da tradurre: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, text);

    std::string sourceLang;
    std::cout << "Inserisci la lingua di origine (es. 'en' per l'inglese): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> sourceLang;

    std::string targetLang;
    std::cout << "Inserisci la lingua di destinazione (es. 'es' per lo spagnolo): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> targetLang;

    std::string jsonResponse;

    CURLcode ret = translate(text, sourceLang, targetLang, jsonResponse);

    if (ret != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(ret));
    } else {
        std::string translatedText = getTranslatedText(jsonResponse);
        std::cout << "Testo tradotto: " << translatedText << std::endl;
    }

}

void ExerciseDb() {

    std::map<std::string, std::string> config = loadConfig("config.txt");
    std::string rapidApiKey = config["X-RapidAPI-Key"];

    std::string bodyPart;
    std::cout << "Inserisci il gruppo muscolare che vuoi allenare: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, bodyPart);
    std::cout << '\n';

    // Sostituisci gli spazi nella query con '%20' per la corretta formattazione dell'URL
    size_t spacePos = bodyPart.find(' ');
    while (spacePos != std::string::npos) {
        bodyPart.replace(spacePos, 1, "%20");
        spacePos = bodyPart.find(' ', spacePos + 3);
    }


    std::string url = "https://exercisedb.p.rapidapi.com/exercises/bodyPart/" + bodyPart + "?limit=10";

    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        // Abilita la verifica del certificato SSL
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        // Usa i certificati CA di Windows quando si costruisce con OpenSSL
        curl_easy_setopt(curl, CURLOPT_SSL_OPTIONS, CURLSSLOPT_NATIVE_CA);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "X-RapidAPI-Key: "+ rapidApiKey);
        headers = curl_slist_append(headers, "X-RapidAPI-Host: exercisedb.p.rapidapi.com");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    auto root = json::parse(readBuffer);
    for (auto& exercise : root) {
        std::cout << "Nome dell'esercizio: " << exercise["name"] << '\n';
        std::cout << "Equipaggiamento: " << exercise["equipment"] << '\n';
        std::cout << "Muscolo target: " << exercise["target"] << '\n';
        std::cout << "Clicca per visualizzare la gif animata: " << exercise["gifUrl"] << '\n';
        std::cout << "Istruzioni:\n";
        for (auto& instruction : exercise["instructions"]) {
            std::cout << "- " << instruction << '\n';
        }
        std::cout << '\n';
    }
}
