#include<iostream>
int main()
{
	int a,b;
	std::cin>>a>>b;
	int tmp;
	if(a<b)
	{
		tmp=b;
		b=a;
		b=tmp;
	}
	while(b!=0)
	{
		a%=b;
		tmp=a;
		a=b;
		b=tmp;
		
	}
	std::cout<<a;
	return 0;
}