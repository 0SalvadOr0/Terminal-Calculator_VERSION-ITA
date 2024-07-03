#pragma once 

#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "..\lib\libs.hpp"

template<typename T>
inline T addition(const std::vector<T>& nums);

template<typename T>
inline T subtraction(const std::vector<T>& nums);

template<typename T>
inline T multiplication(const std::vector<T>& nums);

template<typename T>
inline T division(const std::vector<T>& nums);

template<typename T>
inline T pow(T base, T exponent);

template<typename T>
inline T sqrt(T num);


void operation();
void Triangle();
void PercentageCalculations();

#endif