#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include<vector>
using namespace std;
class Person {
public:
  Person(const string &first_name,const string &last_name,int year_born)
	{
 		firstName[year_born]= first_name;
 		lastName[year_born] = last_name;
		yearborn=year_born;
	}
  void ChangeFirstName(int year, const string &first_name) {
    // добавить факт изменения имени на first_name в год year
	if(year>yearborn){
    firstName[year] = first_name;}
  }
  void ChangeLastName(int year, const string &last_name) {
    // добавить факт изменения фамилии на last_name в год year
if(year>yearborn){
    lastName[year] = last_name;}
  }
  string GetFullName(int year)const {
    // получить имя и фамилию по состоянию на конец года year
    string firstNameS = "", lastNameS = "";
	if(year<yearborn)
{
return "No person";}
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
string GetFullNameWithHistory(int year) const{
if(year<yearborn)
{
return "No person";}
    string firstNameS = "", lastNameS = "";

    auto it = firstName.upper_bound(year);

      firstNameS = format(firstName.cbegin(),it);


    it = lastName.upper_bound(year);


      lastNameS =format(lastName.cbegin(),it);

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
	int yearborn;
	string format (map<int, string>::const_iterator  begin,const map<int, string>::const_iterator upper_bound)const
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
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}*/
