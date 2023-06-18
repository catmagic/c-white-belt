#include<iostream>
#include<vector>
using namespace std;
const vector<int> Reversed(const vector<int>& v)
{
	std::vector<int> res(v.size());
	for(int i=0;i<v.size();++i)
	{
		res[v.size()-i-1]=v[i];
	}
	return res;
}
/*void printVector(const vector<int>&v)
{
	for(auto item:v)
	{
		cout<<item<<" ";
	}cout<<endl;
}
int main()
{
	std::vector<int> numbers = {1, 5, 3, 4, 2};
	std::vector<int> res;
	printVector(Reversed(numbers));
	for(auto number : res)
	{
		std::cout<<number<<" ";
	}
	return 0;
}*/