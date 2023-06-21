#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main()
{
	map<string,vector<string>> bustostop;
	map<string,vector<string>> stoptobus;
	int N;
	cin>>N;
	for(int i;i<N;++i)
	{
		string command;
		cin>>command;
		if(command=="NEW_BUS")
		{
			string bus,stop;
			int stopcount;
			cin>>bus>>stopcount;
			for(int j=0;j<stopcount;++j)
			{
				cin>>stop;
				bustostop[bus].push_back(stop);
				stoptobus[stop].push_back(bus);
			}
		}
		if(command=="BUSES_FOR_STOP")
		{
			string stop;
			cin>>stop;
			if(stoptobus.find(stop)!=stoptobus.end())
			{
				for(auto bus:stoptobus[stop])
				{
					cout<<bus<<" ";
				}
				cout<<endl;
			}
			else
			{
				cout<<"No stop"<<endl;
			}
			
		}
		if(command=="STOPS_FOR_BUS")
		{
			string bus;
			cin>>bus;
			if(bustostop.find(bus)!=bustostop.end())
			{
			
				for(auto stop:bustostop[bus])
				{
					cout<<"Stop "<<stop<<":";
					if(stoptobus[stop].size()!=1)
					{
						
						for(auto otherbus:stoptobus[stop])
						{
							if(otherbus!=bus)
							{
								cout<<" "<<otherbus;
							}
						}cout<<endl;
					}else
					{
						cout<<" no interchange"<<endl;
					}
				}
			}
		}
		if(command=="ALL_BUSES")
		{
			if(bustostop.size())
			{
				for(auto buswithstop:bustostop)
				{
					cout<<"Bus "<<buswithstop.first<<":";
					for(auto stop:buswithstop.second)
					{
						cout<<" "<<stop;
					}cout<<endl;
				}
			}
			else
			{
				cout<<"No buses"<<endl;
			}
		}
	}
	return 0;
}