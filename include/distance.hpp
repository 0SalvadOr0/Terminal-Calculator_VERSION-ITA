#pragma once

#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include "../lib/libs.hpp"

double deg2rad(double deg);
double haversine(double lat1, double lon1, double lat2, double lon2);
void distance();

#endif
