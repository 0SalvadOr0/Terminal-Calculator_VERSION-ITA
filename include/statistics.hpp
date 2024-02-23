#pragma once

#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include "..\lib\libs.hpp"

double media(const std::vector<double>& numeri);
double mediana(std::vector<double> numeri);
double varianza(const std::vector<double>& numeri);
double deviazioneStandard(const std::vector<double>& numeri);
int statistics();

#endif