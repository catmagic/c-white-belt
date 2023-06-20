#include <iostream>
#include <map>
#include <string>
int main() {
  int N;
  std::cin >> N;
  std::map<std::string, std::string> mapCountryToCapital;
  for (int i = 0; i < N; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "CHANGE_CAPITAL") {
      std::string country, capital;
      std::cin >> country >> capital;
      if (mapCountryToCapital.find(country) != mapCountryToCapital.end()) {
        if (mapCountryToCapital[country] == capital) {
          std::cout << "Country " << country << " hasn't changed its "
                    << capital << std::endl;
        } else {
          std::cout << "Country " << country << " has changed its capital from "
                    << mapCountryToCapital[country] << " to " << capital
                    << std::endl;
          mapCountryToCapital[country] = capital;
        }

      } else {
        std::cout << "Introduce new country " << country << " with capital "
                  << capital << std::endl;
        mapCountryToCapital[country] = capital;
      }
    }
    if (command == "RENAME") {
      std::string oldCountry, newCountry;
      std::cin >> oldCountry >> newCountry;
      if (mapCountryToCapital.find(oldCountry) != mapCountryToCapital.end()) {
        std::cout << "Country " << oldCountry << " with capital "
                  << mapCountryToCapital[oldCountry] << " has been renamed to "
                  << newCountry << std::endl;
        mapCountryToCapital[newCountry] = mapCountryToCapital[oldCountry];
        mapCountryToCapital.erase(oldCountry);
      } else {
        std::cout << "Incorrect rename, skip" << std::endl;
      }
    }
    if (command == "ABOUT") {
      std::string country;
      std::cin >> country;
      if (mapCountryToCapital.find(country) != mapCountryToCapital.end()) {
        std::cout << "Country " << country << " has capital "
                  << mapCountryToCapital[country]<<std::endl;
      } else {
        std::cout << "Country " << country << " doesn't exist" << std::endl;
      }
    }
    if (command == "DUMP") {
      if (mapCountryToCapital.size()) {
        for (auto item : mapCountryToCapital) {
          std::cout << item.first << '/' << item.second << " ";
        }std::cout<<std::endl;
      } else {
        std::cout << "There are no countries in the world" << std::endl;
      }
    }
  }
  return 0;
}