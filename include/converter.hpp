#pragma once

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "..\lib\libs.hpp"
#include <curl/curl/curl.h>
#include <nlohmann/json.hpp>

size_t WriteCallbackConverter(void* contents, size_t size, size_t nmemb, std::string* output);
void exangeMoney();
void Converters();

#endif