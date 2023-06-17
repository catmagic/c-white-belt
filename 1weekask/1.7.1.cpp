#include<iostream>
int main()
{
	double n,a,b,x,y;
	std::cin>>n>>a>>b>>x>>y;
	if(n>b)
	{
		std::cout<<(100.-y)*n/100;
	}
	else
	{
		if(n>a)
		{
			std::cout<<(100.-x)*n/100;
		}
		else
		{
			std::cout<<n;
		}
	}
	return 0;
}