#include <iostream>
#include <map>
#include <vector>
#include <string>
int main() {
  int N;
  std::cin >> N;
  std::map<std::vector<std::string>, int> maptobus;
  for (int i = 0; i < N; ++i) {
    int countStop;
    std::cin >> countStop;
    std::vector<std::string> stops;
    std::string stop;
    for (int j = 0; j < countStop; ++j) {
      std::cin >> stop;
      stops.push_back(stop);
    }
    if (maptobus.find(stops) != maptobus.end()) {
      std::cout << "Already exists for " << maptobus[stops] << std::endl;
    } else {
      int newBusPath = maptobus.size() + 1;
      std::cout << "New bus " << newBusPath << std::endl;
      maptobus[stops] = newBusPath;
    }
  }
  return 0;
}