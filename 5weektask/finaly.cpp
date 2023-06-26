#include<iostream>
#include<string>
#include<set>
#include<map>
#include<tuple>
#include<sstream>
class Date {
public:
  int GetYear() const
  {
    return year;
  }
  int GetMonth() const
  {
    return month;
  }
  int GetDay() const
  {
    return day;
  }
    int year,month,day;
};
istream& operator>>(istream& input,Date& date)
{
    string s;
    input>>s;
    stringstream ss<<s;
    char first,second;
    if(ss>>date.year>>first>>date.month>>second>>date.day)
    {
        if(first!=second&&first!='-')
        {
            throw exception("Wrong date format: "+s);
        }
        if(date.month>13||date.month<1)
        {
            throw exception("Month value is invalid: "+to_string(date.month));
        }
        if(date.day>31||date.month<1)
        {
            throw exception("Day value is invalid: "+to_string(date.day));
        }
    }
    else
    {
        throw exception("Wrong date format: "+s);
    }
    return input;
}
bool operator<(const Date& lhs, const Date& rhs)
{
    return make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())<make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay())
}


class Database {
public:
  void AddEvent(const Date& date, const string& event);
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  /* ??? */ Find(const Date& date) const;

  void Print() const;
};

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {

  }

  return 0;
}
