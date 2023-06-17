#include<iostream>
bool IsPalindrom(std::string s)
{
	for(int i=0;i<s.size()/2;++i)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			return false;
		}
	}
	return true;
}
vector<std::string> PalindromFilter(vector<std::string> words, int minLength )
{
	vector<std::string> result;
	for(auto word :words)
	{
		if(IsPalindrom(word)&&word.size()>=minLength)
		{
			result.push_back(word);
		}
	}
	return result;
}
int main()
{
	vector<std::string> words
	std::string word;
	int n;
	std::cin>>n;
	for(int i=0; i<n;++i)
	{
		std::cin>>word;
		words.push_back(word);
	}
	std::cout<<PalindromFilter(s,2);
	return 0;
}