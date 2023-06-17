#include<iostream>
int main ()
{
	std::string s;
	std::cin>>s;
	int r;
	int count=0;
	for(int i=0;i<s.size();++i)
	{
		if(count <2)
		{
			if(s[i]=='f')
			{
				++count;
				if(count==2)
				{
					r=i;
				}
			}
		}
	}
	if(count ==0)
	{
		std::cout<<-2;
	}
	if(count ==1)
	{
		std::cout<<-1;
	}
	if(count==2)
	{
		std::cout<<r;
	}
	return 0;
}