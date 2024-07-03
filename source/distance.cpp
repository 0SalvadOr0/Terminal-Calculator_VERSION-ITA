#include "../include/distance.hpp"

// Definizione di M_PI se non è già definito
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Funzione per convertire i gradi in radianti
double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

// Funzione per calcolare la distanza tra due punti sulla Terra
double haversine(double lat1, double lon1, double lat2, double lon2) {
    // Distanza in latitudine e longitudine
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);

    // Formula dell'Haversine
    double a = sin(dLat/2) * sin(dLat/2) +
                cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
                sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c; // Raggio della Terra in km

    return d;
}

void distance(){
    double lat1, lon1, lat2, lon2;

    std::cout << "Inserisci il valore della latitudine del primo punto: ";
    std::cin >> lat1;

    std::cout << "Inserisci il valore della longitudine del primo punto: ";
    std::cin >> lon1;

    std::cout << "Inserisci il valore della latitudine del secondo punto: ";
    std::cin >> lat2;

    std::cout << "Inserisci il valore della longitudine del secondo punto: ";
    std::cin >> lon2;

    double d = haversine(lat1,lon1,lat2,lon2);

    std::cout << "La distanza tra due punti e' pari a: "<< d << '\n';

}