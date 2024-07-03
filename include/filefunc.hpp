#pragma once

#ifndef FILEFUNC_HPP
#define FILEFUNC_HPP

#include "..\lib\libs.hpp"

void leggiDaFile(const std::string& nomeFile);
void scriviSuFile(const char* nomeFile, const char* contenuto);
void cancellaContenuto(const char* nomeFile);
void fileFunc();

#endif