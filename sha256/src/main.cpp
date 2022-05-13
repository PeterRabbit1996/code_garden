#include "shasum.h"
#include <string>
#include <iostream>

int main()
{
	while (true)
	{
		std::string src;
		std::cin >> src;
		
		
		std::string dst;
		calculateHash((void *)src.c_str(), src.size(), dst);
		std::cout << dst << std::endl;
	}
}
