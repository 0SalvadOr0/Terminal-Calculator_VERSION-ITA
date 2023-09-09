#pragma once 

#ifndef GENERATEPASSWORD_HPP
#define GENERATEPASSWORD_HPP

#include "..\lib\libs.hpp"

std::string generateRandomPassword(int length);

enum PasswordStrength {
    Weak,
    Moderate,
    Strong,
};

PasswordStrength checkPasswordStrength(const std::string &password);

void checkDecision();

#endif