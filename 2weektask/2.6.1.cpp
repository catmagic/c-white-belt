#include<iostream>
#include<string>
#include<set>
int main()
{
	std::string readstring;
	int N;
	std::cin>>N;
	std::set<std::string> uniqString;
	for(int i=0; i<N;++i)
	{
		std::cin>>readstring;
		uniqString.insert(readstring);
	}
	std::cout<<uniqString.size();
	return 0;
}