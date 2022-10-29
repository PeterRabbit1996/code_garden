#include <iostream>

namespace lambda
{
	void test1()
	{
		int val = 10;
		auto f1 = [val]() mutable
		{ return ++val; };
		std::cout << "f1() = " << f1() << std::endl;
		std::cout << "f1() = " << f1() << std::endl;
		std::cout << "val = " << val << std::endl;

		return;
	}

} // namespace lambda

int main()
{
	lambda::test1();

	return 0;
}
