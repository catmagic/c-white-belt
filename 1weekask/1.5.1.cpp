#include<string>
#include<iostream>
int main ()
{
	std::string a,b,c,min;
	std::cin>>a>>b>>c;
	min=a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	std::cout<<min;
	return 0;
}