#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include<vector>
using namespace std;
class Person {
public:
  void ChangeFirstName(int year, const string &first_name) {
    // добавить факт изменения имени на first_name в год year
    firstName[year] = first_name;
  }
  void ChangeLastName(int year, const string &last_name) {
    // добавить факт изменения фамилии на last_name в год year
    lastName[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string firstNameS = "", lastNameS = "";

    auto it = firstName.upper_bound(year);
    if (it != firstName.begin()) {
      it--;
      firstNameS = it->second;
    }

    it = lastName.upper_bound(year);

    if (it != lastName.begin()) {
      it--;
      lastNameS = it->second;
    }
    stringstream ss;
    if (!firstNameS.empty()) {
      if (!lastNameS.empty()) {
        ss << firstNameS << " " << lastNameS;
      } else {
        ss << firstNameS << " with unknown last name";
      }
    } else {
      if (!lastNameS.empty()) {
        ss << lastNameS << " with unknown first name";
      } else {
        ss << "Incognito";
      }
    }
    return ss.str();
  }
string GetFullNameWithHistory(int year) {
    string firstNameS = "", lastNameS = "";

    auto it = firstName.upper_bound(year);
    
      firstNameS = format(firstName.begin(),it);
    

    it = lastName.upper_bound(year);

   
      lastNameS =format(lastName.begin(),it);

    stringstream ss;
    if (!firstNameS.empty()) {
      if (!lastNameS.empty()) {
        ss << firstNameS << " " << lastNameS;
      } else {
        ss << firstNameS << " with unknown last name";
      }
    } else {
      if (!lastNameS.empty()) {
        ss << lastNameS << " with unknown first name";
      } else {
        ss << "Incognito";
      }
    }
    return ss.str();
  }

private:
  map<int, string> firstName, lastName;
	string format ( map<int, string>::iterator  begin,map<int, string>::iterator upper_bound)
	{
		vector<string> namewithoutdublicade;
		if(begin==upper_bound)
		{
			return  "";
		}
	 	auto it =upper_bound;
		it--;
		namewithoutdublicade.push_back(it->second);
		while(it!=begin)
		{
			it--;
			if(namewithoutdublicade[namewithoutdublicade.size()-1]!=it->second)
			{
				namewithoutdublicade.push_back(it->second);
			}
			
		}
		if(namewithoutdublicade.size()==1)
		{
			return  namewithoutdublicade[0];
		}
		string 	result;
		result=namewithoutdublicade[0];
		result+=" (";
		for(int i=1;i<namewithoutdublicade.size();++i)
		{
			if(i!=1)
			{
				result+=", ";
			}
			result+=namewithoutdublicade[i];
		}
		result+=")";
		return result;
	}
};
/*int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}*/