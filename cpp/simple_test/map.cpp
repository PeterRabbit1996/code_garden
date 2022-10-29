#include <map>
#include <string>
#include <iterator>
#include <iostream>

int main()
{
	std::multimap<std::string, size_t> people{{"Ann", 25}, {"Bill", 46}, {"Jack", 77}, {"Jack", 32}, {"Jill", 32}, {"Ann", 35}};
	auto iter = people.find("Jack");
	while (iter != std::end(people))
	// if (iter != std::end(people))
	{
		std::cout << iter->first << " is " << iter->second << std::endl;
	}

	iter = people.find("Ann");
	if (iter != std::end(people))
	{
		std::cout << iter->first << " is " << iter->second << std::endl;
	}

	iter = people.find("Jack");
	// while (iter != people.end())
	// {
	// 	std::cout << iter->first << " is " << iter->second << std::endl;
	// }
}