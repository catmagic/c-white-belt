#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream input("input.txt");
    string s;
    while(getline(input,s))
    {
        cout<<s<<endl;
    }
    return 0;
}
