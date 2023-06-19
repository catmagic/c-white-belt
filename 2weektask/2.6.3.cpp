#include <iostream>
#include <map>
#include <set>
#include <string>
int main() {
  std::map<std::string, std::set<std::string>> dict;
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "ADD") {
      std::string first, second;
      std::cin >> first >> second;
      dict[first].insert(second);
      dict[second].insert(first);
    }
    if (command == "COUNT") {
      std::string word;
      std::cin >> word;
      std::cout << dict[word].size() << std::endl;
    }
    if (command == "CHECK") {
      std::string first, second;
      std::cin >> first >> second;
      if (dict[first].find(second) != dict[first].end()) {
        std::cout << "YES" << std::endl;
      } else {
        	std::cout << "NO" << std::endl;
      }
    }
  }
  return 0;
}