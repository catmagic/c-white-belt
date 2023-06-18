#include<iostream>
#include<vector>
vector<int> Reversed(const vector<int>& v)
{
	std::vector<int> res(v.size());
	for(int i=0;i<v.size();++i)
	{
		res[v.size()-i-1]=v[i];
	}
	return res;
}
/*int main()
{
	std::vector<int> numbers = {1, 5, 3, 4, 2};
	std::vector<int> res;
	res=Reversed(numbers);
	for(auto number : res)
	{
		std::cout<<number<<" ";
	}
	return 0;
}*/