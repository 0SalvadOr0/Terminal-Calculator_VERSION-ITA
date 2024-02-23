#include "../include/statistics.hpp"

double media(const std::vector<double>& numeri) {
    return std::accumulate(numeri.begin(), numeri.end(), 0.0) / numeri.size();
}

double mediana(std::vector<double> numeri) {
    std::sort(numeri.begin(), numeri.end());
    if (numeri.size() % 2 == 0)
        return (numeri[numeri.size()/2 - 1] + numeri[numeri.size()/2]) / 2;
    else
        return numeri[numeri.size()/2];
}

double varianza(const std::vector<double>& numeri) {
    double m = media(numeri);
    double accum = 0.0;
    std::for_each(numeri.begin(), numeri.end(), [&](double d){
        accum += (d - m) * (d - m);
    });
    return accum / (numeri.size()-1);
}

double deviazioneStandard(const std::vector<double>& numeri) {
    return std::sqrt(varianza(numeri));
}

int statistics(){
    std::vector<double> numeri;
    int n;
    double num;

    std::cout << "Quanti numeri vuoi inserire? ";
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cout << "Inserisci il numero " << i+1 << ": ";
        std::cin >> num;
        numeri.push_back(num);
    }

    std::cout << "Media: " << media(numeri) << std::endl;
    std::cout << "Mediana: " << mediana(numeri) << std::endl;
    std::cout << "Varianza su dati campionati: " << varianza(numeri) << std::endl;
    std::cout << "Deviazione standard: " << deviazioneStandard(numeri) << std::endl;

    return 0;
}