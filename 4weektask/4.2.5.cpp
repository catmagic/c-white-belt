#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Student
{
    string firstName,lastName;
    int year,month,day;
};
int main()
{
    int N;
    cin>>N;
    vector<Student> Students(N);
    for(int i=0;i<N;++i)
    {
        cin>>Students[i].firstName>>Students[i].lastName>>Students[i].day>>Students[i].month>>Students[i].year;
    }
    int M;
    cin>>M;
    for(int i=0;i<M;++i)
    {
        string command;
        int index;
        cin>>command>>index;
        --index;
        if(((command=="name")||(command=="date"))&&((index>=0)&&(index<N)))
        {
            Student tmp=Students[index];
            if(command=="name")
            {
                cout<<tmp.firstName<<" "<<tmp.lastName<<endl;
            }
            else
            {
                 cout<<tmp.day<<"."<<tmp.month<<"."<<tmp.year<<endl;
            }
        }
        else
        {
            cout<<"bad request"<<endl;
        }
    }
    return 0;
}
