#include<string>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SortedStrings {
public:
  void AddString(const string& s) {
    auto lower=lower_bound(sortedString.begin(), sortedString.end(), s);
	if(lower!=sortedString.end())
	{
		sortedString.insert(lower, s);
	}
	else
	{
		sortedString.push_back(s);
	}
  }
  vector<string> GetSortedStrings() {
	  return sortedString;
    // получить набор из всех добавленных строк в отсортированном порядке
  }
private:
vector<string> sortedString;
  // приватные поля
};
/*void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}*/