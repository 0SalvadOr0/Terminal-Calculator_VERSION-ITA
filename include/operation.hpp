#pragma once 

#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "..\lib\libs.hpp"

template<typename T>
T addition(const std::vector<T>& nums);

template<typename T>
T subtraction(const std::vector<T>& nums);

template<typename T>
T multiplication(const std::vector<T>& nums);

template<typename T>
T division(const std::vector<T>& nums);

template<typename T>
T pow(T base, T exponent);

template<typename T>
T sqrt(T num);

void operation();
void Triangle();
void PercentageCalculations();

#endif