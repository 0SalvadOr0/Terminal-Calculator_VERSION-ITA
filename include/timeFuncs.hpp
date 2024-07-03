// timeFuncs.hpp
#pragma once

#ifndef TIMEFUNCS_HPP
#define TIMEFUNCS_HPP

#include "../lib/libs.hpp"
#include <windows.h>
#include <chrono>
#include <atomic>
#include <time.h>
#include <thread>

void clearLine();
void printElapsedTime(const std::chrono::time_point<std::chrono::high_resolution_clock>& start);
void timer(int seconds);
void getInput();
void cronograph();
int CalculateAge(const std::tm& birthDate);
void timeFuncs();

#endif
