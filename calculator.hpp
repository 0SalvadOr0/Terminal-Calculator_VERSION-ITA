#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "design\design.hpp"
#include "converter\converter.hpp"
#include "trigoOperation\trigoOperation.hpp"
#include "operation\operation.hpp"
#include "PasswordGenerator\GeneratePassword.hpp"


void choice();
void Triangle();
void PercentageCalculations();
void BMICalculator();
void CalculateAreaAndPermiter();
int CalculateAge(const std::tm& birthDate);
double CalculateTax();
float CalculateVolume();
float CalculateSurface();

#endif // CALCULATOR_H
