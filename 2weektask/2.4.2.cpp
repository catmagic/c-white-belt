#include<iostream>
#include<string>
#include<vector>
int main()
{
	std::vector<bool> worry;
	int N;
	std::string command;
	std::cin>>N;
	for(int i=0; i<N;++i)
	{
		std::cin>>command;
		if(command=="WORRY")
		{
			int k;
			std::cin>>k;
			worry[k]=true;
		}
		if(command=="QUIET")
		{
			int k;
			std::cin>>k;
			worry[k]=false;
		}
		if(command=="COME")
		{
			int k;
			std::cin>>k;
			if(k>0)
			{
				for(int j=0;j<k;++j)
				{
					worry.push_back(false);
				}
			}
			else
			{
				k*=-1;
				for(int j=0;j<k;++j)
				{
					worry.pop_back();
				}
			}
			worry[k]=false;
		}
		if(command=="WORRY_COUNT")
		{
			int k=0;
			for(bool worr:worry)
			{
				if(worr)
				{
					++k;
				}
			}
			std::cout<<k<<std::endl;
		}
		
	}
	return 0;
}