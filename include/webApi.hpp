#pragma once

#ifndef WEBAPI_HPP
#define WEBAPI_HPP

#include <curl/curl/curl.h>
#include <nlohmann/json.hpp>
#include "../lib/libs.hpp"

using json = nlohmann::json;

std::map<std::string, std::string> loadConfig(const std::string& filename);
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);
json getWeatherData(const std::string& city, std::string apiKey);
void weather();
void SpacePerson();
void GetF1Standings();
void searchRapidAPI();
void mapsSearch();
CURLcode translate(std::string text, std::string sourceLang, std::string targetLang, std::string& translatedText);
std::string getTranslatedText(const std::string& jsonResponse);
void googleTranslate();
void ExerciseDb();

#endif