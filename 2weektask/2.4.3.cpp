#include <iostream>
#include <string>
#include <vector>
int next_mouth(int mouth) { return (mouth + 1) % 12; }
int main() {
  std::vector<int> day_mouth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int mouth = 0;
  std::vector<std::vector<std::string>> daytask(day_mouth[mouth]);
  int N;
  std::string command;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> command;
    if (command == "ADD") {
      int day;
      std::string task;
      std::cin >> day >> task;
      daytask[day - 1].push_back(task);
    }
    if (command == "DUMP") {
      int day;
      std::cin >> day;
      std::cout << daytask[day - 1].size() << " ";
      for (auto task : daytask[day - 1]) {
        std::cout << task << " ";
      }
      std::cout << std::endl;
    }
    if (command == "NEXT") {

      for (int day = day_mouth[mouth]; day > day_mouth[next_mouth(mouth)];
           --day) {
        for (auto task : daytask[day - 1]) {
          daytask[day_mouth[next_mouth(mouth)] - 1].push_back(task);
        }
      }
      mouth = next_mouth(mouth);
      daytask.resize(day_mouth[mouth]);
    }
  }
  return 0;
}