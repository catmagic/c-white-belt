#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
  int size;
  std::cin >> size;
  std::vector<std::string> res;
  for (int i = 0; i < size; ++i) {
    std::string tmp;
    std::cin >> tmp;
    res.push_back(tmp);
  }
  std::sort(res.begin(), res.end(), [](std::string a, std::string b) {
    std::string atolower, btolower;
    atolower.resize(a.size());
    btolower.resize(b.size());
    std::transform(a.begin(), a.end(), atolower.begin(),
                   [](char c) { return std::tolower(c); });
    std::transform(b.begin(), b.end(), btolower.begin(),
                   [](char c) { return std::tolower(c); });
    return atolower < btolower;
  });
  for (auto str : res) {
    std::cout << str << " ";
  }
  return 0;
}