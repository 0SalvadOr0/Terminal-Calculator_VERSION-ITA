#pragma once

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "..\lib\libs.hpp"
#include "..\include\converter.hpp"
#include "..\include\design.hpp"
#include "..\include\GeneratePassword.hpp"
#include "..\include\operation.hpp"
#include "..\include\trigoOperation.hpp"
#include "..\include\expression.hpp"

void choice();
void BMICalculator();
void CalculateAreaAndPerimeter();
int CalculateAge(const std::tm& birthDate);
double CalculateTax();
float CalculateVolume();
float CalculateSurface();

#endif // CALCULATOR_H
