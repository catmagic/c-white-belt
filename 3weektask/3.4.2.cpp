#include<iostream>
#include<string>
#include<map>
#include <algorithm> 
#include<sstream>
using namespace std;
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  firstName[year]=first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  lastName[year]=last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  string firstNameS,lastNameS;
	  if(firstName.upper_bound(year)!=firstName.end())
	  {		  
		  firstNameS=firstName.upper_bound(year)->second;
	  }
	  if(lastName.upper_bound(year)!=lastName.end())
	  {
		  lastNameS=lastName.upper_bound(year)->second;
	  }
	  stringstream ss;
	  if(!firstNameS.empty())
	  {
		  if(!lastNameS.empty())
		  {
			  ss<<firstNameS<<" "<<lastNameS;
		  }
		  else
		  {
			  ss<< firstNameS<<" with unknown last name";
		  }
	  }
	  else
	  {
		  if(!lastNameS.empty())
		  {
			  ss<<lastNameS<<" with unknown first name";
		  }
		  else
		  {
			  ss<<"Incognito";
		  }
	  }
	  return ss.str();
  }
private:
  map<int,string>firstName,lastName;
};
/*int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}*/