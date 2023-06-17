#include<iostream>
#include<string>
int main()
{
	int n;
	std::cin>>n;
	std::string s;
	while(n)
	{
		char c='0';
		if(n&1)
		{
			c='1';
		}
		s=std::string(1,c)+s;
		n/=2;
	}
	std::cout<<s;
	return 0;
}