#include <iostream>
#include <vector>
#include <functional>

namespace bind
{

	void test1()
	{
		auto f1 = [](char c1, char c2, char c3, char c4, char c5)
		{
			std::cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << ' ' << c5 << std::endl;
			return;
		};

		auto b1 = std::bind(f1, 'a', 'b', std::placeholders::_1, 'c', std::placeholders::_2);
		auto b2 = std::bind(f1, 'a', 'b', std::placeholders::_2, 'c', std::placeholders::_1);

		b1('1', '2');
		b2('1', '2');

		return;
	}

	void test2()
	{

		auto print_num = [](std::ostream &os, const int val, const char c) -> std::ostream &
		{
			return os << val << c;
		};

		std::vector<char> vec{'a', 'b', 'c'};

		std::for_each(vec.begin(), vec.end(), std::bind(print_num, std::ref(std::cout), std::placeholders::_1, ' '));
		std::cout << std::endl;

		std::for_each(vec.begin(), vec.end(), std::bind(print_num, std::ref(std::cout), ' ', std::placeholders::_1));
		std::cout << std::endl;

		return;
	}
} // namespace bind

int main()
{

	bind::test1();
	bind::test2();

	return 0;
}