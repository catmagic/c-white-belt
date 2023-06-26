#include<iostream>
#include<string>
#include<set>
#include<map>
#include<tuple>
#include<sstream>
#include<iomanip>
#include<cctype>
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
    if(ss>>date.year)
    {
        if(ss.peek() != '-')
        {

            throw runtime_error(string("Wrong date format: ")+s );
        }
        ss.ignore(1);
        if(ss.peek() != '+'&&!isdigit(ss.peek()))
        {
            throw runtime_error(string("Wrong date format: ")+s);
        }
        if(ss.peek() == '+')
        {
             ss.ignore(1);
        }
        if(ss>>date.month){}
        else{ throw runtime_error(string("Wrong date format: ")+s);}
        if(ss.peek() != '-')
        {
            throw runtime_error(string("Wrong date format: ")+s);
        }
        ss.ignore(1);
        if(ss.peek() != '+'&&!isdigit(ss.peek()))
        {
            throw runtime_error(string("Wrong date format: ")+s);
        }if(ss>>date.day){}
        else{ throw runtime_error(string("Wrong date format: ")+s);}
        if(date.month>12||date.month<1)
        {
            throw runtime_error(string("Month value is invalid: ")+to_string(date.month));
        }
        if(date.day>31||date.day<1)
        {
            throw runtime_error(string("Day value is invalid: ")+to_string(date.day));
        }
        char c;
        if(ss>>c)
        {
            throw runtime_error(string("Wrong date format: ")+s);
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
    bool DeleteEvent(const Date& date, const string& event)
    {
        auto itDate=db.find(date);
        if(itDate!=db.end())
        {
            auto itEvent=db[date].find(event);
            if(itEvent!=db[date].end())
            {
                db[date].erase(event);
                if(db[date].size()==0)
                {
                    db.erase(date);
                }
                return true;
            }
            return false;
        }
        return false;
    }
    int  DeleteDate(const Date& date)
    {
        auto itDate=db.find(date);
        if(itDate!=db.end())
        {
            int countEvent=db[date].size();
            db.erase(date);
            return countEvent;
        }
        return 0;
    }

    void Find(const Date& date) const
    {
        const auto it=db.find(date);
        if(db.cend()!=it)
        {
            for(const auto event:db.at(date))
            {
                cout<<event<<endl;
            }
        }
    }

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
        bool flag=false;
        if(command=="Add")
        {
            flag=true;
            Date date;
            string event;
            ss>>date>>event;
            db.AddEvent(date,event);
        }
        if(command=="Print")
        {
            flag=true;
            db.Print();
        }
        if(command=="Find")
        {
            flag=true;
            Date date;
            ss>>date;
            db.Find(date);
        }
        if(command=="Del")
        {
            flag=true;
            Date date;
            string event;
            ss>>date;
            if(ss>>event)
            {
                if(db.DeleteEvent(date,event))
                {
                    cout<<"Deleted successfully"<<endl;
                }
                else
                {
                    cout<<"Event not found"<<endl;
                }
            }
            else
            {
                int countevent=db.DeleteDate(date);
                cout<<"Deleted "<<countevent<<" events"<<endl;
            }
        }
        if(!flag)
        {
            if(!command.empty())
            {
                throw runtime_error("Unknown command: "+command);
            }
        }


    }
    catch(exception &e)
    {
        cout<<e.what()<<endl;
        return 0;
    }

  }

  return 0;
}
