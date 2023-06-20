#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int size;
  std::cin >> size;
  std::vector<int> res;
  for (int i = 0; i < size; ++i) {
    int num;
    std::cin >> num;
    res.push_back(num);
  }
  std::sort(res.begin(), res.end(),
            [](int a, int b) { return abs(a) < abs(b); });
  for (auto num : res) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}