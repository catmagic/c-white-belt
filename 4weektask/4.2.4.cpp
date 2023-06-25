#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    ifstream input("input.txt");
    int  n,m;
    int d;
    input>>n>>m;
    cout << setfill(' ');
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char c;
            input>>d;
            if(j!=m-1)
            {
                input>>c;
            }
             cout<< setw(10)<<d;
             if(j!=m-1)
            {
                cout<<' ';
            }
        }
        if(i!=n-1)
        {
            cout<<endl;
        }

    }
    return 0;
}
