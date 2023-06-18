#include<iostream>
#include<vector>
int main()
{
	int N;
	std::cin>>N;
	std::vector<int> temperaturesdays(N);
	int sum=0;
	int middleTemperatureday;
	for(int i=0;i<N;++i)
	{
		std::cin>>temperaturesdays[i];
		sum+=temperaturesdays[i];
	}
	middleTemperatureday=sum/N;
	std::vector<int> res;
	for(int i=0;i<N;++i)
	{
		if(middleTemperatureday<temperaturesdays[i])
		{
			res.push_back(i);
		}
		
	}
	std::cout<<res.size()<<std::endl;
	for(auto numberday:res)
	{
		std::cout<<numberday<<" ";
	}
	return 0;
	
}