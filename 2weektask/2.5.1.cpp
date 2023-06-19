#include<iostream>
#include<string>
#include<map>
int main()
{
	int N;
	std::string first,second;
	std::cin>>N;
	std::map<char,int> mapFirst,mapSecond;
	for(int i=0;i<N;++i)
	{
		std::cin>>first>>second;
		for(auto c:first)
		{
			++mapFirst[c];
		}
		for(auto c:second)
		{
			++mapSecond[c];
		}
		if(mapFirst==mapSecond)
		{
			std::cout<<"YES\n";
		}
		else
		{
			std::cout<<"NO\n";
		}
		mapFirst.clear();
		mapSecond.clear();
	}
	return 0;
}