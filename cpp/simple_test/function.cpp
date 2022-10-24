#include <iostream>
#include <functional> //bind函数 placeholders命名空间

int Plus(int x, int y)
{
	return x + y;
}

int PlusOne(int x)
{
	auto func = std::bind(Plus, std::placeholders::_1, 1);
	return func(x);
}

int main()
{
	std::cout << PlusOne(9) << std::endl; //结果 10
	return 0;
}
