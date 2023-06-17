#include<iostream>
#include<cmath>
int main()
{
	double a,b,c;
	std::cin>>a>>b>>c;
	if(a==0)
	{
		if(b!=0)
		{
			std::cout<<-c/b;	
		}
	}
	else
	{
		if(b*b>4*a*c)
		{
			std::cout<<(-b-sqrt(b*b-4*a*c))/2/a<<" "<<(-b+sqrt(b*b-4*a*c))/2/a<<std::endl;
		}
		if(b*b==4*a*c)
		{
			std::cout<<-b/2/a;
		}
	}
	return 0;
}