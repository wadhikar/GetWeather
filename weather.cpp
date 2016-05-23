// Code for basic weather app by Wilson Adhikari

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "json.hpp"

/*
1. Ask for parameters and save them
2. Perform a GET request using cURLpp with OpenWeatherMap API and saved parameters
3. Parse JSON object and get values for temperature with min and max, wind speed,
    weather conditions, sunset and sunrise, etc.
4. Create city object with members to save values from JSON object and set members
    to those values
*/

class Weather {
  std::string city;
  std::string country;
  double tempCurrent;
  double tempMin;
  double tempMax;
  double windSpeed;
  std::time_t sunset;
  std::time_t sunrise;
  std::string weatherCondition;
  std::string weatherConditionDescription;
  double humidity;
  double pressure;
}

std::string userCity( std::string cityName ) {
}

std::string userCity( std::string cityName, std::string countryName ) {
}
