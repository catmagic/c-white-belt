#include<iostream>
#include<string>
using namespace std;
class ReversibleString
{
public:
	ReversibleString(string s="")
	{
		this->s=s;
	}
	void Reverse()
	{
		s=string(s.rbegin(),s.rend());
	}
	string ToString()const 
	{
		return s;
	}
private:
string s;
};
/*int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}*/