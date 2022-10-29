#include <iostream>
#include <set>

template <typename T>
void display(const T &t)
{
	for (auto val : t)
	{
		std::cout << val<< std::endl;
	}

	return;
}

namespace set
{
	void test1()
	{
		std::set<std::string> s{"a", "a", "b", "c"};
		display<std::set<std::string>>(s);
	}

} // namespace set

int main()
{
	set::test1();

	return 0;
}
