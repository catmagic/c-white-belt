#include<iostream>
#include<string>
#include<set>
#include<map>
#include<tuple>
#include<sstream>
#include<iomanip>
#include<exception>
using namespace std;
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
    stringstream ss;
    ss<<s;
    char first,second;
    if(ss>>date.year>>first>>date.month>>second>>date.day)
    {
        if(first!=second&&first!='-')
        {
            throw runtime_error(string("Wrong date format: ")+s);
        }
        if(date.month>12||date.month<1)
        {
            throw runtime_error(string("Month value is invalid: ")+to_string(date.month));
        }
        if(date.day>31||date.month<1)
        {
            throw runtime_error(string("Day value is invalid: ")+to_string(date.day));
        }
    }
    else
    {
        throw runtime_error(string("Wrong date format: ")+s);
    }
    return input;
}
ostream& operator<<(ostream& output,const Date& date)
{
    return output<<setfill('0')<<setw(4)<<date.GetYear()<<'-'<<setw(2)<<date.GetMonth()<<'-'<<setw(2)<<date.GetDay();
}
bool operator<(const Date& lhs, const Date& rhs)
{
    return make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())<make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}


class Database {
public:
  void AddEvent(const Date& date, const string& event)
  {
    db[date].insert(event);
  }
 // bool DeleteEvent(const Date& date, const string& event);
 // int  DeleteDate(const Date& date);

  /* ??? */ //Find(const Date& date) const;

    void Print() const
    {
        for(const auto it:db )
        {
            for(const auto event:it.second)
            {
                cout<<it.first<<" "<<event<<endl;
            }
        }
    }
private:
    map<Date,set<string>> db;
};

int main() {
  Database db;

  string fullcommand;
  while (getline(cin, fullcommand))
  {
    try
    {
        stringstream ss;
        ss<<fullcommand;
        string command;
        ss>>command;
        if(command=="Add")
        {
            Date date;
            string event;
            ss>>date>>event;
            db.AddEvent(date,event);
        }
        if(command=="Print")
        {
            db.Print();
        }

    }
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }

  }

  return 0;
}
