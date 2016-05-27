// Code for basic weather app by Wilson Adhikari

#include <iostream>
#include <string>
#include <ctime>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "json.hpp"

/*
1. Ask user for location parameters and save them
2. Perform a GET request using cURLpp with OpenWeatherMap API and saved parameters
3. Parse JSON object and get values for temperature with min and max, wind speed,
    weather conditions, sunset and sunrise, etc.
4. Save values to new Weather object
5. Create city object with members to save values from JSON object and set members
    to those values
*/

class Weather {
public:
  double coordLon;
  double coordLat;
  std::string city;
  std::string country;
  std::string id;
  double tempCurrent;
  double humidity;
  double pressure;
  double tempMin;
  double tempMax;
  double windSpeed;
  double windDirection;
  std::time_t sunset;
  std::time_t sunrise;
  std::string weatherCondition;
  std::string weatherConditionDescription;
  std::string weatherIcon;
private:
  std::string API_Key {"5b626ec962861b526359c3ede8ac78a2"};
}

// Search by city name
std::string userCity( std::string cityName ) {

  std::ostringstream os;
	os << curlpp::options::Url("http://api.openweathermap.org/data/2.5/weather"
                              + "?q=" + cityName + "&appid=" + API_Key);
  return os.str();
}

// Search by city name and country name
std::string userCity( std::string cityName, std::string countryName ) {
  std::ostringstream os;
	os << curlpp::options::Url("http://api.openweathermap.org/data/2.5/weather"
                              + "?q=" + cityName + "," + countryName +
                                "&appid=" + API_Key);
  return os.str();
}

// Search by city ID in OpenWeatherMap database
std::string userCity( long int cityID ) {
  std::ostringstream os;
	os << curlpp::options::Url("http://api.openweathermap.org/data/2.5/weather"
                              + "?id=" + cityID + "&appid=" + API_Key);
  return os.str();
}

// Search by location coordinates
std::string userCity( double coordLat, double coordLon ) {
  std::ostringstream os;
	os << curlpp::options::Url("http://api.openweathermap.org/data/2.5/weather"
                              + "?lat=" coordLat + "&lon=" + coordLon +
                                "&appid=" + API_Key);
  return os.str();
}
