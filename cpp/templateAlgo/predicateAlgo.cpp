#include <iostream>
#include <string>
#include <vector>

bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}

template <typename T>
std::ostream &operator<<(std::ostream &cout, std::vector<T> vec)
{
	for (auto v : vec)
	{
		cout << v << " ";
	}
	cout << std::endl;

	return cout;
}

int main()
{
	std::vector<std::string> vec{"abc", "aaaa", "def", "aaa", "gadd", "bbb", "baa"};

	std::sort(vec.begin(), vec.end());
	std::cout << vec;

	std::sort(vec.begin(), vec.end(), isShorter);
	std::cout << vec;

	std::stable_sort(vec.begin(), vec.end(), isShorter);
	std::cout << vec;

	return 0;
}
