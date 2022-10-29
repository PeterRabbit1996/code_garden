#include <iostream>
#include <vector>

using namespace std;

void func_1()
{
	int size = 14;
	vector<int> vec(size, 4);
	fill_n(vec.begin(), 10, 0); // error if vec is empty or size() less than size!

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

void func_2()
{
	vector<int> vec;
	fill_n(back_inserter(vec), 10, 3); // error if vec is empty or size() less than size!

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

void func_3()
{
	vector<int> vec;
	auto it1 = back_inserter(vec);
	auto it2 = back_inserter(vec);
	auto it3 = back_inserter(vec);

	*it1 = 3;
	*it2 = 6;
	// *it3 = 9;

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

void func_4()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		*(back_inserter(vec)) = i;
	}

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

void func_5()
{
	vector<int> vec;
	auto it1 = back_inserter(vec);
	auto it2 = back_inserter(vec);

	std::cout << "size = " << vec.size() << std::endl;
	*it1 = 3;
	std::cout << "size = " << vec.size() << std::endl;
	*it2 = 6;
	std::cout << "size = " << vec.size() << std::endl;

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

void func_6()
{
	vector<int> vec;
	auto it1 = back_inserter(vec);
	auto it2 = back_inserter(vec);
	auto it3 = back_inserter(vec);

	*it3 = 9;
	*it1 = 3;
	*it2 = 6;

	for (auto v : vec)
	{
		printf("%d ", v);
	}
	printf("\n");

	return;
}

int main()
{
	func_1();
	func_2();
	func_3();
	func_4();
	func_5();
	func_6();

	return 0;
}
