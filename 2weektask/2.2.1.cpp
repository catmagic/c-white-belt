#include<iostream>
void UpdateIfGreater(int& a, int& b)
{
	if(a>b)
	{
		b=a;
	}
}
int main()
{
	int a = 4;
	int b = 2;
	std::cout<<UpdateIfGreater(a, b);
	return 0;
}
