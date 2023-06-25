#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    string s;
    while(getline(input,s))
    {
        output<<s<<endl;
    }
    return 0;
}
