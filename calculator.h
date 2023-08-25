#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>


void choice();
void addition(float &a, float &b);
void subtraction(float &a, float &b);
void multiplication(float &a, float &b);
void division(float &a, float &b);
void Pow(float &a, float &b);
void Sqrt(float &a);
void Triangle();
void TrigonometricOperations();
void PercentageCalculations();
void BMICalculator();
void CalculateAreaAndPermiter();
int CalculateAge(const std::tm& birthDate);
double CalculateTax();
void GeneratePassword(int length);
float CalculateVolume();
float CalculateSurface();

#endif // CALCULATOR_H
