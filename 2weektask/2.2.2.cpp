#include<iostream>
#include<vector>
void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
	for(auto word : source)
	{
		destination.push_back(word);
	}
	source.clear();
}
/*int main()
{
	std::vector<std::string> source = {"a", "b", "c"};
	std::vector<std::string> destination = {"z"};
	MoveStrings(source, destination);
	for(auto word : source)
	{
		std::cout<<word<<" ";
	}
	std::cout<<std::endl;
	for(auto word : destination)
	{
		std::cout<<word<<" ";
	}
	return 0;
}*/