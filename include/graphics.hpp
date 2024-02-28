#pragma once

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "..\lib\colors.hpp"
#include "expression.hpp"

void graphics2D(const std::string& y_expr, const std::string &title);
void graphics3D(const std::string& z_expr, const std::string& title);
void graphics();

#endif