#include <iostream>
int main() {
  	int a, b;
	std::cin>>a>>b;
  	for (int i = ((a + 1) / 2) * 2; i <= b; i += 2)
	{
    	std::cout << i << " ";
  	}
  	return 0;
}